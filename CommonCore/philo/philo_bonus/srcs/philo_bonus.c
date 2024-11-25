/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csicsi <csicsi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 08:54:56 by dcsicsak          #+#    #+#             */
/*   Updated: 2024/11/25 17:16:08 by csicsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_bonus.h"

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
		write(2, "Error: Number too long!\n", 24);
		return (false);
	}
	free(converted_str);
	*result = number;
	return (true);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	unsigned int	src_len;
	unsigned int	i;

	src_len = 0;
	i = 0;
	while (src[src_len])
	{
		src_len++;
	}
	if (size == 0)
	{
		return (src_len);
	}
	while (i < size - 1 && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (src_len);
}

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	unsigned int	index1;
	unsigned int	index2;
	unsigned int	res;

	index1 = 0;
	index2 = 0;
	res = 0;
	while (dst[index1])
		index1++;
	while (src[res])
		res++;
	if (size <= index1)
		res += size;
	else
		res += index1;
	while (src[index2] && (index1 + 1) < size)
	{
		dst[index1] = src[index2];
		index1++;
		index2++;
	}
	dst[index1] = '\0';
	return (res);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new;
	size_t	len;

	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2) + 1;
	new = malloc(len * sizeof(char));
	if (!new)
		return (NULL);
	ft_strlcpy(new, s1, len);
	ft_strlcat(new, s2, len);
	return (new);
}

static sem_t	*create_semaphore(char *name, int value)
{
	sem_t	*sem;

	sem_unlink(name);
	sem = sem_open(name, O_CREAT, 0644, value);
	if (!sem)
		return (write(2, "Error: Failed to create semaphore\n", 35), NULL);
	return (sem);
}

void cleanup_semaphores(t_data *data)
{
	int	i;

	if (data->forks)
	{
		sem_close(data->forks);
		sem_unlink("/forks");
		data->forks = NULL;
	}
	if (data->print_lock)
	{
		sem_close(data->print_lock);
		sem_unlink("/print_lock");
		data->print_lock = NULL;
	}
	if (data->state_lock)
	{
		sem_close(data->state_lock);
		sem_unlink("/state_lock");
		data->state_lock = NULL;
	}
	if (data->full)
	{
		sem_close(data->full);
		sem_unlink("/full");
		data->full = NULL;
	}
	if (data->dead)
	{
		sem_close(data->dead);
		sem_unlink("/dead");
		data->dead = NULL;
	}
	if (data->kill)
	{
		sem_close(data->kill);
		sem_unlink("/kill");
		data->kill = NULL;
	}
	i = 0;
	while (i < data->num_philos)
	{
		sem_close(data->philo[i].terminate_lock);
		sem_unlink(data->philo[i].terminate_sem_name);
		i++;
	}
}

bool is_terminated(t_philosopher *philo)
{
	bool	terminated;

	sem_wait(philo->terminate_lock);
	terminated = philo->terminate;
	sem_post(philo->terminate_lock);
	return (terminated);
}

void set_terminate(t_philosopher *philo, bool value)
{
	sem_wait(philo->terminate_lock);
	philo->terminate = value;
	sem_post(philo->terminate_lock);
}

int sleep_for(long time_in_ms, t_philosopher *philo)
{
	long	start_time;

	start_time = get_time_in_ms();
	while ((get_time_in_ms() - start_time) < time_in_ms)
	{
		if (is_terminated(philo))
			return (-1);
		usleep(100);
	}
	return (0);
}

void print_status(t_philosopher *philo, char *status)
{
	sem_wait(philo->data->print_lock);
	if (!philo->terminate)
		printf("%ld %d %s\n", get_time_in_ms() - philo->data->start_time,
			philo->id, status);
	sem_post(philo->data->print_lock);
}

void *kill_philo(void *arg)
{
	t_philosopher	*philo;

	philo = (t_philosopher *)arg;
	sem_wait(philo->data->kill);
	set_terminate(philo, true);
	return (NULL);
}

void *check_death(void *arg)
{
	t_philosopher	*philo;

	philo = (t_philosopher *)arg;
	while (1)
	{
		if (is_terminated(philo))
			break ;
		sem_wait(philo->terminate_lock);
		if (get_time_in_ms() - philo->last_meal > philo->data->time_to_die)
		{
			sem_post(philo->data->dead);
			print_status(philo, "died");
			sem_wait(philo->data->print_lock);
			set_terminate(philo, true);
			usleep(500);
			sem_post(philo->data->print_lock);
			sem_post(philo->terminate_lock);
			break ;
		}
		sem_post(philo->terminate_lock);
		usleep(500);
	}
	return (NULL);
}

void philo_routine(t_philosopher *philo)
{
	pthread_t	monitoring_thread;
	pthread_t	kill_thread;

	pthread_create(&monitoring_thread, NULL, check_death, philo);
	pthread_create(&kill_thread, NULL, kill_philo, philo);
	print_status(philo, "is thinking");
	if (sleep_for(philo->delay, philo) == -1)
	{
		pthread_join(monitoring_thread, NULL);
		pthread_join(kill_thread, NULL);
		sem_post(philo->data->full);
		cleanup_semaphores(philo->data);
		free(philo->data->pids);
		free(philo->data->philo);
		return ;
	}
	while (1)
	{
		if (philo->terminate)
			break ;
		sem_wait(philo->data->forks);
		print_status(philo, "has taken a fork");
		sem_wait(philo->data->forks);
		print_status(philo, "has taken a fork");
		print_status(philo, "is eating");
		sem_wait(philo->terminate_lock);
		philo->last_meal = get_time_in_ms();
		sem_post(philo->terminate_lock);
		if (sleep_for(philo->data->time_to_eat, philo) == -1)
		{
			sem_post(philo->data->forks);
			sem_post(philo->data->forks);
			break ;
		}
		sem_post(philo->data->forks);
		sem_post(philo->data->forks);
		philo->meals_eaten++;
		if (philo->data->meals_required != -1
			&& philo->meals_eaten >= philo->data->meals_required)
			sem_post(philo->data->full);
		print_status(philo, "is sleeping");
		if (sleep_for(philo->data->time_to_sleep, philo) == -1)
			break ;
		print_status(philo, "is thinking");
		if (sleep_for(philo->data->time_to_think, philo) == -1)
			break ;
	}
	sem_post(philo->data->full);
	pthread_join(monitoring_thread, NULL);
	pthread_join(kill_thread, NULL);
	cleanup_semaphores(philo->data);
	free(philo->data->pids);
	free(philo->data->philo);
}

void start_philo_processes(t_data *data)
{
	int	i;

	data->pids = malloc(sizeof(pid_t) * data->num_philos);
	if (!data->pids)
	{
		write(2, "Error: Failed to allocate memory for pids\n", 42);
		return ;
	}
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
			write(2, "Error: Failed to create philosopher process\n", 44);
			break ;
		}
		i++;
	}
}

int validate_input(int argc, char **argv)
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
			write(2, "Error: All arguments must be valid numbers.\n", 44);
			return (1);
		}
		if (argv[i][0] == '-')
		{
			write(2, "Error: Negative numbers are not allowed.\n", 42);
			return (1);
		}
		i++;
	}
	return (0);
}

void *monitor(void *arg)
{
	t_data	*data;
	int		cur;

	cur = -1;
	data = (t_data *)arg;
	sem_wait(data->dead);
	while (++cur < data->num_philos)
		sem_post(data->kill);
	return (NULL);
}

void wait_processes(t_data *data)
{
	int i;
	int status;

	i = 0;
	while (i < data->num_philos)
	{
		waitpid(data->pids[i], &status, 0);
		i++;
	}
	free(data->pids);
}

int initialize_semaphores(t_data *data)
{
	data->forks = create_semaphore("/forks", data->num_philos);
	if (!data->forks)
		return (write(2, "Error: Failed to create forks semaphore\n", 40), 1);
	data->print_lock = create_semaphore("/print_lock", 1);
	if (!data->print_lock)
		return (cleanup_semaphores(data),
			write(2, "Error: Failed to create print_lock semaphore\n", 45), 1);
	data->state_lock = create_semaphore("/state_lock", 1);
	if (!data->state_lock)
		return (write(2, "Error: Failed to create state_lock semaphore\n", 45), 1);
	data->full = create_semaphore("/full", 0);
	if (!data->full)
		return (cleanup_semaphores(data),
			write(2, "Error: Failed to create full semaphore\n", 39), 1);
	data->dead = create_semaphore("/dead", 0);
	if (!data->dead)
		return (cleanup_semaphores(data),
			write(2, "Error: Failed to create dead semaphore\n", 39), 1);
	data->kill = create_semaphore("/kill", 0);
	if (!data->kill)
		return (cleanup_semaphores(data),
			write(2, "Error: Failed to create kill semaphore\n", 39), 1);
	return (0);
}

int main(int argc, char **argv)
{
	t_data		data;
	size_t		temp;
	pthread_t	monitor_thread;
	int			i;
	long		delay;
	long		thinking_time;

	data = (t_data){0};
	if (validate_input(argc, argv))
		return (1);
	if (!ft_validate_number(argv[1], &temp) || temp == 0)
		return (write(2, "Error: Invalid number of philosophers\n", 38), 1);
	data.num_philos = temp;
	if (!ft_validate_number(argv[2], &temp))
		return (write(2, "Error: Invalid time to die\n", 27), 1);
	data.time_to_die = temp;
	if (!ft_validate_number(argv[3], &temp))
		return (write(2, "Error: Invalid time to eat\n", 27), 1);
	data.time_to_eat = temp;
	if (!ft_validate_number(argv[4], &temp))
		return (write(2, "Error: Invalid time to sleep\n", 29), 1);
	data.time_to_sleep = temp;
	data.start_time = get_time_in_ms();
	if (argc == 6 && ft_validate_number(argv[5], &temp))
		data.meals_required = temp;
	else
		data.meals_required = -1;
	if (data.num_philos % 2 == 1)
	{
		thinking_time = data.time_to_eat / (float)(data.num_philos / 2);
		data.time_to_think = data.time_to_eat - data.time_to_sleep
			+ thinking_time;
	}
	else
		data.time_to_think = data.time_to_eat - data.time_to_sleep;
	if (initialize_semaphores(&data))
		return (1);
	data.philo = malloc(sizeof(t_philosopher) * data.num_philos);
	if (!data.philo)
		return (cleanup_semaphores(&data),
			write(2, "Error: Memory allocation failure\n", 34), 1);
	i = 0;
	while (i < data.num_philos)
	{
		data.philo[i].id = i + 1;
		data.philo[i].meals_eaten = 0;
		data.philo[i].last_meal = data.start_time;
		data.philo[i].data = &data;
		data.philo[i].terminate = false;
		snprintf(data.philo[i].terminate_sem_name, sizeof(data.philo[i].terminate_sem_name),
			"/terminate_philo_%d", data.philo[i].id);
		data.philo[i].terminate_lock = sem_open(data.philo[i].terminate_sem_name, O_CREAT, 0644, 1);
		if (data.philo[i].terminate_lock == SEM_FAILED)
		{
			perror("sem_open");
			exit(EXIT_FAILURE);
		}
		if (data.num_philos % 2 == 0)
		{
			if (i >= data.num_philos / 2)
				data.philo[i].delay = data.time_to_eat;
			else
				data.philo[i].delay = 0;
		}
		else
		{
			delay = data.time_to_eat / (data.num_philos / 2);
			data.philo[i].delay = delay * i;
		}
		i++;
	}
	pthread_create(&monitor_thread, NULL, monitor, &data);
	start_philo_processes(&data);
	i = -1;
	while (++i < data.num_philos)
		sem_wait(data.full);
	i = -1;
	while (++i < data.num_philos)
		sem_post(data.kill);
	wait_processes(&data);
	sem_post(data.dead);
	pthread_join(monitor_thread, NULL);
	cleanup_semaphores(&data);
	free(data.philo);
	return (0);
}
