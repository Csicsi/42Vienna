/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcsicsak <dcsicsak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 15:51:36 by dcsicsak          #+#    #+#             */
/*   Updated: 2024/09/04 15:52:39 by dcsicsak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

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

void	print_status(t_philosopher *philo, char *status)
{
	pthread_mutex_lock(&philo->data->state_lock);
	if (philo->data->simulation_running)
	{
		pthread_mutex_lock(&philo->data->print_lock);
		printf("%ld %d %s\n", get_time_in_ms() - philo->data->start_time,
			philo->id, status);
		pthread_mutex_unlock(&philo->data->print_lock);
	}
	pthread_mutex_unlock(&philo->data->state_lock);
}

int	check_simulation_running(t_philosopher *philo)
{
	pthread_mutex_lock(&philo->data->state_lock);
	if (!philo->data->simulation_running)
	{
		pthread_mutex_unlock(&philo->data->state_lock);
		return (0);
	}
	pthread_mutex_unlock(&philo->data->state_lock);
	return (1);
}

void	cleanup_forks_and_locks(t_data *data, int i)
{
	int	j;

	j = 0;
	while (j < i)
	{
		pthread_mutex_destroy(&data->forks[j]);
		j++;
	}
	pthread_mutex_destroy(&data->print_lock);
	pthread_mutex_destroy(&data->state_lock);
	free(data->forks);
	free(data->philo);
}

void	cleanup_threads(pthread_t *threads,
	int num_created, pthread_t monitor_thread)
{
	while (num_created > 0)
	{
		num_created--;
		pthread_join(threads[num_created], NULL);
	}
	pthread_join(monitor_thread, NULL);
	free(threads);
}
