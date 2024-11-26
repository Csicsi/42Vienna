/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csicsi <csicsi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 06:28:13 by csicsi            #+#    #+#             */
/*   Updated: 2024/11/26 06:45:16 by csicsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_bonus.h"

bool	validate_number(const char *str, size_t *result)
{
	size_t	number;
	char	*converted_str;

	number = ft_atost(str);
	converted_str = ft_sttoa(number);
	if (!converted_str)
		return (false);
	if (str[0] == '+')
		str++;
	if (ft_strncmp(str, converted_str, ft_strlen(str)) != 0)
	{
		free(converted_str);
		write(2, "Error: Number too long!\n", 24);
		return (false);
	}
	free(converted_str);
	*result = number;
	return (true);
}

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

void	wait_processes(t_data *data)
{
	int	i;
	int	status;

	i = 0;
	while (i < data->num_philos)
	{
		waitpid(data->pids[i], &status, 0);
		i++;
	}
	free(data->pids);
}

void	cleanup_resources(t_philosopher *philo,
	pthread_t *monitoring_thread, pthread_t *kill_thread)
{
	sem_post(philo->data->full);
	pthread_join(*monitoring_thread, NULL);
	pthread_join(*kill_thread, NULL);
	cleanup_semaphores(philo->data);
	free(philo->data->pids);
	free(philo->data->philo);
}

int	initialize_threads(t_philosopher *philo,
	pthread_t *monitoring_thread, pthread_t *kill_thread)
{
	if (pthread_create(monitoring_thread, NULL, check_death, philo) != 0)
		return (-1);
	if (pthread_create(kill_thread, NULL, kill_philo, philo) != 0)
	{
		pthread_cancel(*monitoring_thread);
		return (-1);
	}
	return (0);
}
