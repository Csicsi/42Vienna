/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csicsi <csicsi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 06:26:16 by csicsi            #+#    #+#             */
/*   Updated: 2024/11/26 06:26:21 by csicsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_bonus.h"

long	get_time_in_ms(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

bool	is_terminated(t_philosopher *philo)
{
	bool	terminated;

	sem_wait(philo->terminate_lock);
	terminated = philo->terminate;
	sem_post(philo->terminate_lock);
	return (terminated);
}

void	set_terminate(t_philosopher *philo, bool value)
{
	sem_wait(philo->terminate_lock);
	philo->terminate = value;
	sem_post(philo->terminate_lock);
}

int	sleep_for(long time_in_ms, t_philosopher *philo)
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

void	print_status(t_philosopher *philo, char *status)
{
	sem_wait(philo->data->print_lock);
	if (!is_terminated(philo))
		printf("%ld %d %s\n", get_time_in_ms() - philo->data->start_time,
			philo->id, status);
	sem_post(philo->data->print_lock);
}
