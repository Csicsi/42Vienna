/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcsicsak <dcsicsak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 08:54:56 by dcsicsak          #+#    #+#             */
/*   Updated: 2024/11/20 13:47:22 by dcsicsak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	is_number(char *str)
{
	int	i;

	i = 0;
	if (str[0] == '\0')
		return (0);
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (str[i] == '\0')
		return (0);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

long	get_time_in_ms(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

static int	numlen(size_t n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_sttoa(size_t n)
{
	int		len;
	char	*str;

	len = numlen(n);
	str = (char *)malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	str[len--] = '\0';
	if (n == 0)
		str[0] = '0';
	while (n != 0)
	{
		str[len--] = (n % 10) + '0';
		n /= 10;
	}
	return (str);
}

size_t	ft_atost(const char *nptr)
{
	size_t	i;
	size_t	number;
	size_t	previous;

	i = 0;
	number = 0;
	if (nptr[i] == '-' || nptr[i] == '+')
		i++;
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		previous = number;
		number = number * 10 + (nptr[i] - '0');
		if (number < previous)
			return (SIZE_MAX);
		i++;
	}
	return (number);
}

size_t	ft_strlen(const char *s)
{
	size_t	temp;

	temp = 0;
	while (*s != '\0')
	{
		temp++;
		s++;
	}
	return (temp);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	while (*s1 && (*s1 == *s2) && n != 0)
	{
		s1++;
		s2++;
		n--;
	}
	if (n == 0)
	{
		return (0);
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}

int	sleep_for(long time_in_ms, t_data *data)
{
	long	start_time;

	start_time = get_time_in_ms();
	while ((get_time_in_ms() - start_time) < time_in_ms)
	{
		sem_wait(data->state_lock);
		if (!data->simulation_running)
		{
			sem_post(data->state_lock);
			return (1);
		}
		sem_post(data->state_lock);
		usleep(100);
	}
	return (0);
}

bool	ft_validate_number(const char *str, size_t *result)
{
	size_t	number;
	char	*converted_str;

	number = ft_atost(str);
	converted_str = ft_sttoa(number);
	if (!converted_str)
		return (false);
	if (str[0] == '+')
		str++;
	if (ft_strncmp(str, converted_str, ft_strlen(str)) != 0)
	{
		free(converted_str);
		printf("Error: Number too long!\n");
		return (false);
	}
	free(converted_str);
	*result = number;
	return (true);
}

static sem_t	*create_semaphore(char *name, int value)
{
	sem_unlink(name);
	return (sem_open(name, O_CREAT, 0644, value));
}

void	print_status(t_philosopher *philo, char *status)
{
	sem_wait(philo->data->print_lock);
	if (philo->data->simulation_running)
		printf("%ld %d %s\n", get_time_in_ms() - philo->data->start_time,
			philo->id, status);
	sem_post(philo->data->print_lock);
}

void	handle_error(char *err)
{
	write(2, err, ft_strlen(err));
}

void	cleanup_semaphores(t_data *data)
{
	sem_close(data->forks);
	sem_close(data->print_lock);
	sem_close(data->state_lock);
	sem_unlink("/forks");
	sem_unlink("/print_lock");
	sem_unlink("/state_lock");
}

void	philo_routine(t_philosopher *philo)
{
	print_status(philo, "is thinking");
	sleep_for(philo->delay, philo->data);
	while (1)
	{
		sem_wait(philo->data->forks);
		print_status(philo, "has taken a fork");
		sem_wait(philo->data->forks);
		print_status(philo, "has taken a fork");
		print_status(philo, "is eating");
		philo->last_meal = get_time_in_ms();
		sleep_for(philo->data->time_to_eat, philo->data);
		sem_post(philo->data->forks);
		sem_post(philo->data->forks);
		philo->meals_eaten++;
		print_status(philo, "is sleeping");
		sleep_for(philo->data->time_to_sleep, philo->data);
		print_status(philo, "is thinking");
		sleep_for(philo->data->time_to_think, philo->data);
	}
}

void	start_philo_processes(t_data *data)
{
	int	i;

	data->pids = malloc(sizeof(pid_t) * data->num_philos);
	if (!data->pids)
		return (handle_error("Error: Failed to allocate memory for pids\n"));
	i = 0;
	while (i < data->num_philos)
	{
		data->pids[i] = fork();
		if (data->pids[i] == 0)
		{
			philo_routine(&data->philo[i]);
			exit(0);
		}
		else if (data->pids[i] < 0)
		{
			handle_error("Error: Failed to create philosopher process\n");
			break ;
		}
		i++;
	}
}

void monitor_processes(t_data *data)
{
	int status;
	int i;

	while (data->simulation_running)
	{
		for (i = 0; i < data->num_philos; i++)
		{
			sem_wait(data->state_lock);
			if (get_time_in_ms() - data->philo[i].last_meal > data->time_to_die)
			{
				data->simulation_running = false;
				printf("%ld %d has died\n",
						get_time_in_ms() - data->start_time, data->philo[i].id);
				sem_post(data->state_lock);
				break ;
			}
			sem_post(data->state_lock);
		}
		if (!data->simulation_running)
			break ;
		if (waitpid(-1, &status, WNOHANG) > 0)
		{
			if (WEXITSTATUS(status) == 1)
			{
				sem_wait(data->state_lock);
				data->simulation_running = false;
				sem_post(data->state_lock);
				break ;
			}
		}
		usleep(100);
	}
	for (i = 0; i < data->num_philos; i++)
		kill(data->pids[i], SIGTERM);
	for (i = 0; i < data->num_philos; i++)
		waitpid(data->pids[i], NULL, 0);
	free(data->pids);
}

int	validate_input(int argc, char **argv)
{
	int	i;

	if (argc != 5 && argc != 6)
	{
		printf("Usage: ./philo num_philos time_to_die ");
		printf("time_to_eat time_to_sleep [meals_required]\n");
		return (1);
	}
	i = 1;
	while (i < argc)
	{
		if (!is_number(argv[i]))
		{
			printf("Error: All arguments must be valid numbers.\n");
			return (1);
		}
		if (argv[i][0] == '-')
		{
			printf("Error: Negative numbers are not allowed.\n");
			return (1);
		}
		i++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	data;
	size_t	temp;

	if (validate_input(argc, argv))
		return (1);
	if (!ft_validate_number(argv[1], &temp) || temp == 0)
		return (handle_error("Error: Invalid number of philosophers\n"), 1);
	data.num_philos = temp;
	if (!ft_validate_number(argv[2], &temp))
		return (handle_error("Error: Invalid time to die\n"), 1);
	data.time_to_die = temp;
	if (!ft_validate_number(argv[3], &temp))
		return (handle_error("Error: Invalid time to eat\n"), 1);
	data.time_to_eat = temp;
	if (!ft_validate_number(argv[4], &temp))
		return (handle_error("Error: Invalid time to sleep\n"), 1);
	data.time_to_sleep = temp;
		data.simulation_running = true;
	data.start_time = get_time_in_ms();
	data.meals_required = (argc == 6 && ft_validate_number(argv[5], &temp)) ? temp : -1;
	data.time_to_think = data.time_to_eat - data.time_to_sleep;
	if (data.num_philos % 2 == 1 && data.num_philos != 1)
		data.time_to_think += data.time_to_eat / (float)(data.num_philos / 2);
	data.forks = create_semaphore("/forks", data.num_philos);
	data.print_lock = create_semaphore("/print_lock", 1);
	data.state_lock = create_semaphore("/state_lock", 1);
	if (!data.forks || !data.print_lock || !data.state_lock)
		return (handle_error("Error: Failed to initialize semaphores\n"), 1);
	data.philo = malloc(sizeof(t_philosopher) * data.num_philos);
	if (!data.philo)
		return (cleanup_semaphores(&data), handle_error("Error: Memory allocation failure\n"), 1);
	for (int i = 0; i < data.num_philos; i++)
	{
		data.philo[i].id = i + 1;
		data.philo[i].meals_eaten = 0;
		data.philo[i].last_meal = data.start_time;
		data.philo[i].data = &data;
		data.philo[i].delay = 0;
		if (data.num_philos % 2 == 0)
			data.philo[i].delay = data.time_to_eat
				* (i >= data.num_philos / 2);
		else
			data.philo[i].delay = data.time_to_eat
				/ (float)(data.num_philos / 2) * i;
	}
	data.simulation_running = true;
	start_philo_processes(&data);
	monitor_processes(&data);
	cleanup_semaphores(&data);
	free(data.philo);
	return (0);
}
