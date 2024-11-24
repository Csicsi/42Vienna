/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csicsi <csicsi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 08:54:56 by dcsicsak          #+#    #+#             */
/*   Updated: 2024/11/24 15:14:31 by csicsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_bonus.h"

int		is_number(char *str)
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
		printf("Error: Number too long!\n");
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

void	handle_error(char *err)
{
	write(2, err, ft_strlen(err));
}

void cleanup_semaphores(t_data *data)
{
	if (data->forks)
		sem_close(data->forks);
	if (data->print_lock)
		sem_close(data->print_lock);
	if (data->state_lock)
		sem_close(data->state_lock);
	if (data->full)
		sem_close(data->full);
	if (data->dead)
		sem_close(data->dead);
	if (data->kill)
		sem_close(data->kill);
	sem_unlink("/forks");
	sem_unlink("/print_lock");
	sem_unlink("/state_lock");
	sem_unlink("/full");
	sem_unlink("/dead");
	sem_unlink("/kill");
}

int sleep_for(long time_in_ms, t_philosopher *philo)
{
	long	start_time;

	start_time = get_time_in_ms();
	while ((get_time_in_ms() - start_time) < time_in_ms)
	{
		sem_wait(philo->lock);
		if (philo->terminate)
		{
			sem_post(philo->lock);
			return (-1);
		}
		sem_post(philo->lock);
		usleep(100);
	}
	return (0);
}

void print_status(t_philosopher *philo, char *status)
{
	sem_wait(philo->data->print_lock);
	printf("%ld %d %s\n", get_time_in_ms() - philo->data->start_time,
		philo->id, status);
	sem_post(philo->data->print_lock);
}

void *kill_philo(void *arg)
{
	t_philosopher	*philo;

	philo = (t_philosopher *)arg;
	sem_wait(philo->data->kill);
	sem_wait(philo->lock);
	philo->terminate = true;
	sem_post(philo->lock);
	return (NULL);
}

void *check_death(void *arg)
{
	t_philosopher	*philo;

	philo = (t_philosopher *)arg;
	while (1)
	{
		if (get_time_in_ms() - philo->last_meal > philo->data->time_to_die)
		{
			print_status(philo, "died");
			sem_wait(philo->lock);
			philo->terminate = true;
			sem_post(philo->lock);
			sem_post(philo->data->dead);
			break ;
		}
		usleep(100);
	}
	return (NULL);
}

void philo_routine(t_philosopher *philo)
{
	pthread_t	monitoring_thread;
	pthread_t	kill_thread;
	char		*sem_name;
	bool		has_forks;

	pthread_create(&monitoring_thread, NULL, check_death, philo);
	pthread_create(&kill_thread, NULL, kill_philo, philo);
	sem_name = ft_strjoin("/philo", ft_sttoa(philo->id));
	philo->lock = create_semaphore(sem_name, 1);
	if (!philo->lock)
		return (handle_error("Error: Failed to create philo semaphore\n"));
	print_status(philo, "is thinking");
	if (sleep_for(philo->delay, philo) == -1)
	{
		pthread_join(monitoring_thread, NULL);
		pthread_join(kill_thread, NULL);
		return ;
	}
	while (1)
	{
		sem_wait(philo->lock);
		if (philo->terminate)
		{
			sem_post(philo->lock);
			break ;
		}
		sem_post(philo->lock);
		sem_wait(philo->data->forks);
		print_status(philo, "has taken a fork");
		sem_wait(philo->data->forks);
		print_status(philo, "has taken a fork");
		has_forks = true;
		print_status(philo, "is eating");
		philo->last_meal = get_time_in_ms();
		if (sleep_for(philo->data->time_to_eat, philo) == -1)
			break ;
		sem_post(philo->data->forks);
		sem_post(philo->data->forks);
		has_forks = false;
		philo->meals_eaten++;
		if (philo->data->meals_required != -1
			&& philo->meals_eaten >= philo->data->meals_required)
		{
			sem_post(philo->data->full);
		}
		print_status(philo, "is sleeping");
		if (sleep_for(philo->data->time_to_sleep, philo) == -1)
			break ;
		print_status(philo, "is thinking");
		if (sleep_for(philo->data->time_to_think, philo) == -1)
			break ;
	}
	if (philo->lock)
	{
		sem_close(philo->lock);
		sem_unlink(sem_name);
	}
	free(sem_name);
	if (has_forks)
	{
		sem_post(philo->data->forks);
		sem_post(philo->data->forks);
	}
	sem_post(philo->data->full);
	pthread_join(monitoring_thread, NULL);
	pthread_join(kill_thread, NULL);
}

void start_philo_processes(t_data *data)
{
	int	i;

	data->pids = malloc(sizeof(pid_t) * data->num_philos);
	if (!data->pids)
	{
		handle_error("Error: Failed to allocate memory for pids\n");
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
			handle_error("Error: Failed to create philosopher process\n");
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

void *monitor(void *arg)
{
	t_data *data;
	int cur;

	cur = -2;
	data = (t_data *)arg;
	sem_wait(data->dead);
	while (++cur < data->num_philos)
	{
		sem_post(data->kill);
	}
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

int	validate_args(int argc, char **argv, t_data *data)
{
	size_t	temp;

	if (validate_input(argc, argv))
		return (1);
	if (!ft_validate_number(argv[1], &temp) || temp == 0)
		return (handle_error("Error: Invalid number of philosophers\n"), 1);
	data->num_philos = temp;
	if (!ft_validate_number(argv[2], &temp))
		return (handle_error("Error: Invalid time to die\n"), 1);
	data->time_to_die = temp;
	if (!ft_validate_number(argv[3], &temp))
		return (handle_error("Error: Invalid time to eat\n"), 1);
	data->time_to_eat = temp;
	if (!ft_validate_number(argv[4], &temp))
		return (handle_error("Error: Invalid time to sleep\n"), 1);
	data->time_to_sleep = temp;
	if (argc == 6 && ft_validate_number(argv[5], &temp))
		data->meals_required = temp;
	else
		data->meals_required = -1;
	return (0);
}

int initialize_simulation(int argc, char **argv, t_data *data)
{
	int i;

	data->forks = NULL;
	data->print_lock = NULL;
	data->state_lock = NULL;
	data->full = NULL;
	data->dead = NULL;
	data->kill = NULL;

	if (validate_args(argc, argv, data))
		return (1);

	data->start_time = get_time_in_ms();

	if (data->num_philos % 2 == 1)
		data->time_to_think = data->time_to_eat - data->time_to_sleep
			+ data->time_to_eat / (float)(data->num_philos / 2);
	else
		data->time_to_think = data->time_to_eat - data->time_to_sleep;

	data->forks = sem_open("/forks", O_CREAT, 0644, data->num_philos);
	data->print_lock = sem_open("/print_lock", O_CREAT, 0644, 1);
	data->state_lock = sem_open("/state_lock", O_CREAT, 0644, 1);
	data->full = sem_open("/full", O_CREAT, 0644, 0);
	data->dead = sem_open("/dead", O_CREAT, 0644, 0);
	data->kill = sem_open("/kill", O_CREAT, 0644, 0);

	if (!data->forks || !data->print_lock || !data->state_lock
		|| !data->full || !data->dead || !data->kill)
	{
		cleanup_semaphores(data);
		handle_error("Error: Failed to initialize semaphores\n");
		return (1);
	}

	data->philo = malloc(sizeof(t_philosopher) * data->num_philos);
	if (!data->philo)
	{
		cleanup_semaphores(data);
		handle_error("Error: Memory allocation failure\n");
		return (1);
	}

	for (i = 0; i < data->num_philos; i++)
	{
		data->philo[i].id = i + 1;
		data->philo[i].meals_eaten = 0;
		data->philo[i].last_meal = data->start_time;
		data->philo[i].data = data;
		data->philo[i].terminate = false;
		data->philo[i].delay = 0;
		data->philo[i].lock = NULL;
	}

	return (0);
}

int	main(int argc, char **argv)
{
	t_data		data;
	pthread_t	monitor_thread;
	int			i;

	if (initialize_simulation(argc, argv, &data))
		return (1);
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

