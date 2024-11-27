/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcsicsak <dcsicsak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 08:49:54 by dcsicsak          #+#    #+#             */
/*   Updated: 2024/11/27 08:49:58 by dcsicsak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_bonus.h"

void	create_terminate_sem_name(char *terminate_sem_name, size_t size, int id)
{
	char	*id_str;
	char	*temp;

	id_str = ft_sttoa(id);
	if (!id_str)
	{
		terminate_sem_name[0] = '\0';
		return ;
	}
	temp = ft_strjoin("/terminate_philo_", id_str);
	if (temp)
		ft_strlcpy(terminate_sem_name, temp, size);
	else
		terminate_sem_name[0] = '\0';
	free(id_str);
	free(temp);
}

int	initialize_philosopher_array(t_data *data)
{
	data->philo = malloc(sizeof(t_philosopher) * data->num_philos);
	if (!data->philo)
	{
		cleanup_semaphores(data);
		write(2, "Error: Memory allocation failure\n", 34);
		return (1);
	}
	return (0);
}

int	initialize_philosopher(t_philosopher *philo, t_data *data, int index)
{
	long	delay;

	philo->id = index + 1;
	philo->last_meal = data->start_time;
	philo->terminate = false;
	create_terminate_sem_name(philo->terminate_sem_name,
		sizeof(philo->terminate_sem_name), index + 1);
	sem_unlink(philo->terminate_sem_name);
	philo->terminate_lock
		= sem_open(philo->terminate_sem_name, O_CREAT, 0644, 1);
	if (philo->terminate_lock == SEM_FAILED)
		return (write(2, "Error: Failed to create terminate sem\n", 39), 1);
	if (data->num_philos % 2 == 0)
	{
		if (index >= data->num_philos / 2)
			philo->delay = data->time_to_eat;
		else
			philo->delay = 0;
	}
	else if (data->num_philos != 1)
	{
		delay = data->time_to_eat / (data->num_philos / 2);
		philo->delay = delay * index;
	}
	return (0);
}

int	initialize_philosophers(t_data *data)
{
	int	i;

	if (initialize_philosopher_array(data))
		return (1);
	i = 0;
	while (i < data->num_philos)
	{
		data->philo[i].meals_eaten = 0;
		data->philo[i].data = data;
		if (initialize_philosopher(&data->philo[i], data, i))
		{
			while (i >= 0)
			{
				sem_close(data->philo[i].terminate_lock);
				sem_unlink(data->philo[i].terminate_sem_name);
				i--;
			}
			free(data->philo);
			return (1);
		}
		i++;
	}
	return (0);
}
