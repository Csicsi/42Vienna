#include "philo_bonus.h"

long	get_time_in_ms(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

int	sleep_for(long time_in_ms, t_philosopher *philo)
{
	long	start_time;

	start_time = get_time_in_ms();
	while ((get_time_in_ms() - start_time) < time_in_ms)
	{
		sem_wait(philo->data->done_lock);
		if (philo->data->all_philos_done)
		{
			sem_post(philo->data->done_lock);
			return -1;
		}
		sem_post(philo->data->done_lock);
		usleep(100);
	}
	return 0;
}

void	print_status(t_philosopher *philo, char *status)
{
	sem_wait(philo->data->done_lock);
	if (philo->data->all_philos_done)
	{
		printf("kurva\n");
		sem_post(philo->data->done_lock);
		return;
	}
	sem_post(philo->data->done_lock);
	long time_elapsed = get_time_in_ms() - philo->data->start_time;
	sem_wait(philo->data->print_lock);
	printf("%ld %d %s\n", time_elapsed, philo->id, status);
	sem_post(philo->data->print_lock);
}

void	*monitor_philosophers(void *arg)
{
	t_philosopher	*philos;
	t_data			*data;
	int				i;
	int				all_done;

	philos = (t_philosopher *)arg;
	data = philos[0].data;
	printf("Monitor thread started (Thread ID: %lu)\n", pthread_self());
	while (1)
	{
		all_done = 1;
		i = -1;
		while (++i < data->num_philos)
		{
			sem_wait(data->meal_time_lock);
			long time_since_last_meal = get_time_in_ms() - philos[i].last_meal;
			sem_post(data->meal_time_lock);

			// Check if a philosopher has died
			if (time_since_last_meal > data->time_to_die)
			{
				print_status(&philos[i], "died");
				sem_wait(data->done_lock);
				data->all_philos_done = 1;
				sem_post(data->done_lock);
				return (NULL);  // Exit the monitor thread when a philosopher dies
			}

			sem_wait(data->meals_lock);
			if (data->meals_required != -1 && philos[i].meals_eaten < data->meals_required)
				all_done = 0;
			sem_post(data->meals_lock);
		}

		// If all philosophers have finished eating the required number of meals
		if (all_done && data->meals_required != -1)
		{
			sem_wait(data->done_lock);
			data->all_philos_done = 1;
			sem_post(data->done_lock);
			printf("Monitor thread ending: All philosophers have completed meals\n");
			return (NULL);
		}

		// Check if simulation is over (philosophers are done)
		sem_wait(data->done_lock);
		if (data->all_philos_done)
		{
			sem_post(data->done_lock);
			return (NULL);
		}
		sem_post(data->done_lock);

		usleep(1000);  // Check again after 1 millisecond
	}
}

void	philosopher_life(t_philosopher *philo)
{
	t_data	*data;

	data = philo->data;
	printf("Philosopher %d: Process started (PID: %d)\n", philo->id, getpid());
	sem_wait(data->done_lock);
	printf("kurva2: %d\n", data->all_philos_done);
	sem_post(data->done_lock);
	if (data->num_philos == 1)
	{
		sem_wait(data->forks);
		print_status(philo, "has taken a fork");
		if (sleep_for(data->time_to_die, philo) == -1)
			return;
		print_status(philo, "died");
		sem_post(data->forks);
		return ;
	}
	print_status(philo, "is thinking");
	if (sleep_for(philo->delay, philo) == -1)
		return;
	while (1)
	{
		sem_wait(data->done_lock);
		if (data->all_philos_done)
		{
			sem_post(data->done_lock);
			return;
		}
		sem_post(data->done_lock);
		if (philo->id % 2 == 0)
		{
			sem_wait(data->forks);
			print_status(philo, "has taken a fork");
			sem_wait(data->forks);
			print_status(philo, "has taken a fork");
		}
		else
		{
			sem_wait(data->forks);
			print_status(philo, "has taken a fork");
			sem_wait(data->forks);
			print_status(philo, "has taken a fork");
		}
		sem_wait(data->meals_lock);
		print_status(philo, "is eating");
		sem_wait(data->meal_time_lock);
		philo->last_meal = get_time_in_ms();
		printf("Philosopher %d is updating last_meal at %ld\n", philo->id, philo->last_meal);
		sem_post(data->meal_time_lock);
		philo->meals_eaten++;
		sem_post(data->meals_lock);
		if (sleep_for(data->time_to_eat, philo) == -1)
			return;
		sem_post(data->forks);
		sem_post(data->forks);
		print_status(philo, "is sleeping");
		if (sleep_for(data->time_to_sleep, philo) == -1)
			return;
		print_status(philo, "is thinking");
		if (sleep_for(data->time_to_think, philo) == -1)
			return;
	}
}

void	cleanup_simulation(t_data *data)
{
	sem_close(data->forks);
	sem_close(data->print_lock);
	sem_close(data->state_lock);
	sem_close(data->meals_lock);
	sem_close(data->done_lock);
	sem_close(data->meal_time_lock);
	sem_unlink("/forks");
	sem_unlink("/print_lock");
	sem_unlink("/state_lock");
	sem_unlink("/meals_lock");
	sem_unlink("/done_lock");
	sem_unlink("/meal_time_lock");
}

void	init_semaphores(t_data *data)
{
	sem_unlink("/forks");
	sem_unlink("/print_lock");
	sem_unlink("/state_lock");
	sem_unlink("/meals_lock");
	sem_unlink("/done_lock");
	sem_unlink("/meal_time_lock");
	data->forks = sem_open("/forks", O_CREAT, 0644, data->num_philos);
	data->print_lock = sem_open("/print_lock", O_CREAT, 0644, 1);
	data->state_lock = sem_open("/state_lock", O_CREAT, 0644, 1);
	data->meals_lock = sem_open("/meals_lock", O_CREAT, 0644, 1);
	data->done_lock = sem_open("/done_lock", O_CREAT, 0644, 1);
	data->meal_time_lock = sem_open("/meal_time_lock", O_CREAT, 0644, 1);
	if (data->forks == SEM_FAILED || data->print_lock == SEM_FAILED
		|| data->state_lock == SEM_FAILED || data->meals_lock == SEM_FAILED
		|| data->done_lock == SEM_FAILED || data->meal_time_lock == SEM_FAILED)
	{
		printf("Error initializing semaphores\n");
		exit(1);
	}
}

int is_number(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

int	handle_input(int argc, char **argv, t_data *data)
{
	int	i;

	if (argc != 5 && argc != 6)
	{
		printf("Usage: ./philo_bonus num_philos time_to_die time_to_eat time_to_sleep [meals_required]\n");
		return (1);
	}
	i = 0;
	while (++i < argc)
	{
		if (!is_number(argv[i]) || atoi(argv[i]) <= 0)
		{
			printf("Error: Invalid input, all arguments must be positive numbers\n");
			return (1);
		}
	}
	data->num_philos = atoi(argv[1]);
	data->time_to_die = atoi(argv[2]);
	data->time_to_eat = atoi(argv[3]);
	data->time_to_sleep = atoi(argv[4]);
	if (argc == 6)
		data->meals_required = atoi(argv[5]);
	else
		data->meals_required = -1;
	if (data->num_philos % 2 == 0)
		data->time_to_think = data->time_to_eat - data->time_to_sleep;
	else
		data->time_to_think = (data->time_to_eat - data->time_to_sleep) +
			(data->time_to_eat / (float)(data->num_philos / 2));
	return (0);
}

void	start_simulation(t_data *data)
{
	t_philosopher	philos[data->num_philos];
	pthread_t		monitor_thread;
	int				i;

	data->start_time = get_time_in_ms();
	data->all_philos_done = 0;
	data->pids = (pid_t *)malloc(sizeof(pid_t) * data->num_philos);
	if (!data->pids)
	{
		printf("Error allocating memory for PIDs\n");
		return ;
	}
	i = -1;
	while (++i < data->num_philos)
	{
		bzero(&philos[i], sizeof(t_philosopher));
		philos[i].id = i + 1;
		philos[i].data = data;
		philos[i].last_meal = get_time_in_ms();
		philos[i].meals_eaten = 0;
		if (data->num_philos % 2 == 0)
		{
			if (i >= data->num_philos)
				philos[i].delay = data->time_to_eat;
			else
				philos[i].delay = 0;
		}
		else
			philos[i].delay = data->time_to_eat / (float)(data->num_philos / 2) * i;
	}
	i = -1;
	while (++i < data->num_philos)
	{
		if ((data->pids[i] = fork()) == 0)
		{
			philosopher_life(&philos[i]);
			return ;
		}
	}
	if (pthread_create(&monitor_thread, NULL, monitor_philosophers,
			(void *)philos) != 0)
	{
		printf("Error creating monitor thread\n");
		return ;
	}
	i = -1;
	while (++i < data->num_philos)
		waitpid(data->pids[i], NULL, 0);
	pthread_join(monitor_thread, NULL);
	if (data->all_philos_done)
		printf("All philosophers have finished eating the required number of meals\n");
	cleanup_simulation(data);
}

int	main(int argc, char **argv)
{
	t_data	data;

	printf("Main process started (PID: %d)\n", getpid());
	memset(&data, 0, sizeof(t_data));
	if (handle_input(argc, argv, &data))
		return (1);
	init_semaphores(&data);
	start_simulation(&data);
	data.all_philos_done = 1;
	printf("kurva2: %d\n", data.all_philos_done);
	printf("Main process ending (PID: %d)\n", getpid());
	return (0);
}
