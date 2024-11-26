/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csicsi <csicsi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 06:34:06 by csicsi            #+#    #+#             */
/*   Updated: 2024/11/26 06:46:03 by csicsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_bonus.h"

static void	handle_single_philosopher(t_philosopher *philo)
{
	sem_wait(philo->data->forks);
	print_status(philo, "has taken a fork");
	sleep_for(philo->data->time_to_die, philo);
	print_status(philo, "died");
	sem_post(philo->data->forks);
	sem_post(philo->data->full);
	cleanup_semaphores(philo->data);
}

static int	handle_delay(t_philosopher *philo,
	pthread_t *monitoring_thread, pthread_t *kill_thread)
{
	print_status(philo, "is thinking");
	if (sleep_for(philo->delay, philo) == -1)
	{
		pthread_join(*monitoring_thread, NULL);
		pthread_join(*kill_thread, NULL);
		sem_post(philo->data->full);
		cleanup_semaphores(philo->data);
		free(philo->data->pids);
		free(philo->data->philo);
		return (-1);
	}
	return (0);
}

static void	handle_eating(t_philosopher *philo)
{
	sem_wait(philo->data->forks);
	print_status(philo, "has taken a fork");
	sem_wait(philo->data->forks);
	print_status(philo, "has taken a fork");
	print_status(philo, "is eating");
	sem_wait(philo->terminate_lock);
	philo->last_meal = get_time_in_ms();
	sem_post(philo->terminate_lock);
	if (sleep_for(philo->data->time_to_eat, philo) != -1)
	{
		philo->meals_eaten++;
		if (philo->data->meals_required != -1
			&& philo->meals_eaten >= philo->data->meals_required)
		{
			sem_post(philo->data->full);
		}
	}
	sem_post(philo->data->forks);
	sem_post(philo->data->forks);
}

static void	handle_sleep_and_think(t_philosopher *philo)
{
	print_status(philo, "is sleeping");
	if (sleep_for(philo->data->time_to_sleep, philo) == -1)
		return ;
	print_status(philo, "is thinking");
	sleep_for(philo->data->time_to_think, philo);
}

void	philo_routine(t_philosopher *philo)
{
	pthread_t	monitoring_thread;
	pthread_t	kill_thread;

	if (philo->data->num_philos == 1)
	{
		handle_single_philosopher(philo);
		return ;
	}
	if (initialize_threads(philo, &monitoring_thread, &kill_thread) == -1)
		return ;
	if (handle_delay(philo,
			&monitoring_thread, &kill_thread) == -1)
		return ;
	while (1)
	{
		if (is_terminated(philo))
			break ;
		handle_eating(philo);
		if (philo->terminate)
			break ;
		handle_sleep_and_think(philo);
		if (philo->terminate)
			break ;
	}
	cleanup_resources(philo, &monitoring_thread, &kill_thread);
}
