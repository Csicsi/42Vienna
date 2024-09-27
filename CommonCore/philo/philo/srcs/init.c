/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcsicsak <dcsicsak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 15:56:12 by dcsicsak          #+#    #+#             */
/*   Updated: 2024/09/04 15:58:21 by dcsicsak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static int	allocate_memory(t_data *data)
{
	data->forks = malloc(sizeof(pthread_mutex_t) * data->num_philos);
	if (!data->forks)
	{
		handle_error("Error: Failed to allocate memory for forks\n");
		return (0);
	}
	data->philo = malloc(sizeof(t_philosopher) * data->num_philos);
	if (!data->philo)
	{
		handle_error("Error: Failed to allocate memory for philosophers\n");
		free(data->forks);
		return (0);
	}
	return (1);
}

static int	init_print_and_state_lock(t_data *data)
{
	if (pthread_mutex_init(&data->print_lock, NULL) != 0)
	{
		handle_error("Error: Failed to initialize print_lock\n");
		free(data->forks);
		free(data->philo);
		return (0);
	}
	if (pthread_mutex_init(&data->state_lock, NULL) != 0)
	{
		handle_error("Error: Failed to initialize state_lock\n");
		pthread_mutex_destroy(&data->print_lock);
		free(data->forks);
		free(data->philo);
		return (0);
	}
	return (1);
}

static int	init_forks_and_locks(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->num_philos)
	{
		if (pthread_mutex_init(&data->forks[i], NULL) != 0)
		{
			handle_error("Error: Failed to initialize fork mutex\n");
			cleanup_forks_and_locks(data, i);
			return (0);
		}
		if (pthread_mutex_init(&data->philo[i].meals_lock, NULL) != 0)
		{
			handle_error("Error: Failed to initialize meal lock mutex\n");
			cleanup_forks_and_locks(data, i);
			return (0);
		}
		i++;
	}
	return (1);
}

static void	init_single_philo(t_data *data, int i)
{
	data->philo[i].id = i + 1;
	data->philo[i].left_fork = &data->forks[i];
	data->philo[i].right_fork = &data->forks[(i + 1) % data->num_philos];
	data->philo[i].last_meal = get_time_in_ms();
	data->philo[i].meals_eaten = 0;
	data->philo[i].data = data;
	if (data->num_philos % 2 == 0)
	{
		if (i % 2 == 1)
			data->philo[i].delay = data->time_to_eat;
		else
			data->philo[i].delay = 0;
	}
	else
	{
		if (i % 2 == 1)
			data->philo[i].delay = data->time_to_eat
				+ (data->time_to_eat / (float)(data->num_philos / 2) * (i / 2));
		else
			data->philo[i].delay = data->time_to_eat
				/ (float)(data->num_philos / 2) * (i / 2);
	}
}

void	init_philosophers(t_data *data)
{
	int	i;

	i = 0;
	if (!allocate_memory(data))
		return ;
	if (!init_print_and_state_lock(data))
		return ;
	if (data->num_philos % 2 == 0)
		data->time_to_think = data->time_to_eat - data->time_to_sleep;
	else
		data->time_to_think = data->time_to_eat - data->time_to_sleep
			+ (data->time_to_eat / (float)(data->num_philos / 2));
	if (!init_forks_and_locks(data))
		return ;
	while (i < data->num_philos)
	{
		init_single_philo(data, i);
		i++;
	}
}
