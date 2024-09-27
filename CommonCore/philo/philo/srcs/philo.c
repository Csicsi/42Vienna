/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcsicsak <dcsicsak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 15:54:26 by dcsicsak          #+#    #+#             */
/*   Updated: 2024/09/04 15:59:49 by dcsicsak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static int	take_forks(t_philosopher *philo, pthread_mutex_t *first_fork,
	pthread_mutex_t *second_fork)
{
	pthread_mutex_lock(first_fork);
	print_status(philo, "has taken a fork");
	pthread_mutex_lock(second_fork);
	print_status(philo, "has taken a fork");
	pthread_mutex_lock(&philo->data->state_lock);
	if (!philo->data->simulation_running)
	{
		pthread_mutex_unlock(&philo->data->state_lock);
		pthread_mutex_unlock(second_fork);
		pthread_mutex_unlock(first_fork);
		return (0);
	}
	pthread_mutex_unlock(&philo->data->state_lock);
	return (1);
}

static int	eat_and_release_forks(t_philosopher *philo,
	pthread_mutex_t *first_fork, pthread_mutex_t *second_fork)
{
	print_status(philo, "is eating");
	pthread_mutex_lock(&philo->meals_lock);
	philo->last_meal = get_time_in_ms();
	pthread_mutex_unlock(&philo->meals_lock);
	if (sleep_for(philo->data->time_to_eat, philo->data))
	{
		pthread_mutex_unlock(second_fork);
		pthread_mutex_unlock(first_fork);
		return (0);
	}
	pthread_mutex_lock(&philo->meals_lock);
	philo->meals_eaten++;
	pthread_mutex_unlock(&philo->meals_lock);
	pthread_mutex_unlock(second_fork);
	pthread_mutex_unlock(first_fork);
	return (1);
}

static void	philo_loop(t_philosopher *philo,
	pthread_mutex_t *first_fork, pthread_mutex_t *second_fork)
{
	while (1)
	{
		if (!check_simulation_running(philo))
			break ;
		if (!take_forks(philo, first_fork, second_fork))
			break ;
		if (!eat_and_release_forks(philo, first_fork, second_fork))
			break ;
		print_status(philo, "is sleeping");
		if (sleep_for(philo->data->time_to_sleep, philo->data))
			break ;
		print_status(philo, "is thinking");
		if (sleep_for(philo->data->time_to_think, philo->data))
			break ;
	}
}

static void	get_forks_order(t_philosopher *philo,
	pthread_mutex_t **first_fork, pthread_mutex_t **second_fork)
{
	if (philo->left_fork < philo->right_fork)
	{
		*first_fork = philo->left_fork;
		*second_fork = philo->right_fork;
	}
	else
	{
		*first_fork = philo->right_fork;
		*second_fork = philo->left_fork;
	}
}

void	*philo_routine(void *arg)
{
	t_philosopher	*philo;
	pthread_mutex_t	*first_fork;
	pthread_mutex_t	*second_fork;

	philo = (t_philosopher *)arg;
	if (philo->data->num_philos == 1)
	{
		pthread_mutex_lock(philo->left_fork);
		print_status(philo, "has taken a fork");
		sleep_for(philo->data->time_to_die, philo->data);
		pthread_mutex_unlock(philo->left_fork);
		return (NULL);
	}
	get_forks_order(philo, &first_fork, &second_fork);
	print_status(philo, "is thinking");
	if (sleep_for(philo->delay, philo->data))
		return (NULL);
	philo_loop(philo, first_fork, second_fork);
	return (NULL);
}
