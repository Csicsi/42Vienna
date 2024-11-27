/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcsicsak <dcsicsak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 08:54:17 by dcsicsak          #+#    #+#             */
/*   Updated: 2024/11/27 08:54:23 by dcsicsak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_bonus.h"

void	*kill_philo(void *arg)
{
	t_philosopher	*philo;

	philo = (t_philosopher *)arg;
	sem_wait(philo->data->kill);
	set_terminate(philo, true);
	return (NULL);
}

void	*check_death(void *arg)
{
	t_philosopher	*philo;

	philo = (t_philosopher *)arg;
	while (1)
	{
		if (is_terminated(philo))
			break ;
		if (get_time_in_ms() - philo->last_meal > philo->data->time_to_die)
		{
			sem_post(philo->data->dead);
			print_status(philo, "died");
			sem_wait(philo->data->print_lock);
			set_terminate(philo, true);
			usleep(500);
			sem_post(philo->data->print_lock);
			break ;
		}
		usleep(500);
	}
	return (NULL);
}

void	*monitor(void *arg)
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
