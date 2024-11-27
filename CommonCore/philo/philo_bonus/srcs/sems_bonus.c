/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sems_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcsicsak <dcsicsak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 08:45:16 by dcsicsak          #+#    #+#             */
/*   Updated: 2024/11/27 08:45:41 by dcsicsak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_bonus.h"

sem_t	*create_semaphore(char *name, int value)
{
	sem_t	*sem;

	sem_unlink(name);
	sem = sem_open(name, O_CREAT, 0644, value);
	if (!sem)
		return (write(2, "Error: Failed to create semaphore\n", 35), NULL);
	return (sem);
}

void	close_and_unlink_semaphore(sem_t **sem, const char *name)
{
	if (*sem)
	{
		sem_close(*sem);
		sem_unlink(name);
		*sem = NULL;
	}
}

void	cleanup_semaphores(t_data *data)
{
	int	i;

	close_and_unlink_semaphore(&data->forks, "/forks");
	close_and_unlink_semaphore(&data->print_lock, "/print_lock");
	close_and_unlink_semaphore(&data->state_lock, "/state_lock");
	close_and_unlink_semaphore(&data->full, "/full");
	close_and_unlink_semaphore(&data->dead, "/dead");
	close_and_unlink_semaphore(&data->kill, "/kill");
	i = 0;
	while (i < data->num_philos)
	{
		close_and_unlink_semaphore(&data->philo[i].terminate_lock,
			data->philo[i].terminate_sem_name);
		i++;
	}
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
