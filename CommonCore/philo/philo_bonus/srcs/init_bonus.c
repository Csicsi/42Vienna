/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csicsi <csicsi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 06:41:18 by csicsi            #+#    #+#             */
/*   Updated: 2024/11/26 06:48:16 by csicsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_bonus.h"

int	initialize_semaphores(t_data *data)
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
		return (write(2, "Error: Failed to create state_lock sem\n", 40), 1);
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

static int	parse_input(int argc, char **argv, t_data *data)
{
	size_t	temp;

	if (validate_input(argc, argv))
		return (1);
	if (!validate_number(argv[1], &temp) || temp == 0)
		return (write(2, "Error: Invalid number of philosophers\n", 38), 1);
	data->num_philos = temp;
	if (!validate_number(argv[2], &temp))
		return (write(2, "Error: Invalid time to die\n", 27), 1);
	data->time_to_die = temp;
	if (!validate_number(argv[3], &temp))
		return (write(2, "Error: Invalid time to eat\n", 27), 1);
	data->time_to_eat = temp;
	if (!validate_number(argv[4], &temp))
		return (write(2, "Error: Invalid time to sleep\n", 29), 1);
	data->time_to_sleep = temp;
	if (argc == 6 && validate_number(argv[5], &temp))
		data->meals_required = temp;
	else
		data->meals_required = -1;
	return (0);
}

int	initialize_data(int argc, char **argv, t_data *data)
{
	long	thinking_time;

	*data = (t_data){0};
	if (parse_input(argc, argv, data))
		return (1);
	if (data->num_philos % 2 == 1 && data->num_philos > 1)
	{
		thinking_time = data->time_to_eat / (float)(data->num_philos / 2);
		data->time_to_think = data->time_to_eat
			- data->time_to_sleep + thinking_time;
	}
	else
		data->time_to_think = data->time_to_eat - data->time_to_sleep;
	data->start_time = get_time_in_ms();
	return (0);
}

static int	initialize_philosopher(t_data *data, int i)
{
	long	delay;

	data->philo[i].id = i + 1;
	data->philo[i].last_meal = data->start_time;
	data->philo[i].data = data;
	data->philo[i].terminate = false;
	create_terminate_sem_name(data->philo[i].terminate_sem_name,
		sizeof(data->philo[i].terminate_sem_name), i + 1);
	data->philo[i].terminate_lock
		= sem_open(data->philo[i].terminate_sem_name, O_CREAT, 0644, 1);
	if (data->philo[i].terminate_lock == SEM_FAILED)
		return (write(2, "Error: Failed to create terminate sem\n", 39), 1);
	if (data->num_philos % 2 == 0)
	{
		if (i >= data->num_philos / 2)
			data->philo[i].delay = data->time_to_eat;
		else
			data->philo[i].delay = 0;
	}
	else if (data->num_philos != 1)
	{
		delay = data->time_to_eat / (data->num_philos / 2);
		data->philo[i].delay = delay * i;
	}
	return (0);
}

int	initialize_philosophers(t_data *data)
{
	int	i;

	data->philo = malloc(sizeof(t_philosopher) * data->num_philos);
	if (!data->philo)
	{
		write(2, "Error: Memory allocation failure\n", 34);
		return (1);
	}
	i = 0;
	while (i < data->num_philos)
	{
		data->philo[i].meals_eaten = 0;
		if (initialize_philosopher(data, i) != 0)
		{
			write(2, "Error: Philosopher initialization failed\n", 42);
			return (1);
		}
		i++;
	}
	return (0);
}
