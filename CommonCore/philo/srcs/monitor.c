/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcsicsak <dcsicsak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 15:53:14 by dcsicsak          #+#    #+#             */
/*   Updated: 2024/09/14 19:33:44 by dcsicsak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static int	check_individual_philo_state(t_philosopher *philo, t_data *data)
{
	pthread_mutex_lock(&philo->meals_lock);
	if ((size_t)(get_time_in_ms() - philo->last_meal) > data->time_to_die)
	{
		pthread_mutex_unlock(&philo->meals_lock);
		print_status(philo, "died");
		pthread_mutex_lock(&data->state_lock);
		data->simulation_running = false;
		pthread_mutex_unlock(&data->state_lock);
		return (0);
	}
	if (data->meals_required > 0 && philo->meals_eaten < data->meals_required)
	{
		pthread_mutex_unlock(&philo->meals_lock);
		return (2);
	}
	pthread_mutex_unlock(&philo->meals_lock);
	return (1);
}

static int	check_philo_state(t_data *data)
{
	int	i;
	int	all_satisfied;
	int	status;

	i = 0;
	all_satisfied = 1;
	while (i < data->num_philos)
	{
		status = check_individual_philo_state(&data->philo[i], data);
		if (status == 0)
			return (0);
		if (status == 2)
			all_satisfied = 0;
		i++;
	}
	if (all_satisfied == 1 && data->meals_required > 0)
		return (1);
	return (2);
}

void	*monitor_philos(void *arg)
{
	t_data	*data;
	int		state;

	data = (t_data *)arg;
	while (1)
	{
		state = check_philo_state(data);
		if (state == 0)
			return (NULL);
		if (state == 1)
		{
			pthread_mutex_lock(&data->state_lock);
			data->simulation_running = false;
			pthread_mutex_unlock(&data->state_lock);
			return (NULL);
		}
		usleep(100);
	}
	return (NULL);
}
