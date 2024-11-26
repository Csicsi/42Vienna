/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csicsi <csicsi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 08:54:56 by dcsicsak          #+#    #+#             */
/*   Updated: 2024/11/26 06:44:44 by csicsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_bonus.h"

int	validate_input(int argc, char **argv)
{
	int	i;

	if (argc != 5 && argc != 6)
	{
		printf("Usage: ./philo num_philos time_to_die ");
		printf("time_to_eat time_to_sleep [meals_required]\n");
		return (1);
	}
	i = 1;
	while (i < argc)
	{
		if (!is_number(argv[i]))
		{
			write(2, "Error: All arguments must be valid numbers.\n", 44);
			return (1);
		}
		if (argv[i][0] == '-')
		{
			write(2, "Error: Negative numbers are not allowed.\n", 42);
			return (1);
		}
		i++;
	}
	return (0);
}

void	start_philo_processes(t_data *data)
{
	int	i;

	data->pids = malloc(sizeof(pid_t) * data->num_philos);
	if (!data->pids)
	{
		write(2, "Error: Failed to allocate memory for pids\n", 42);
		return ;
	}
	i = 0;
	while (i < data->num_philos)
	{
		data->pids[i] = fork();
		if (data->pids[i] == 0)
		{
			philo_routine(&data->philo[i]);
			exit(0);
		}
		else if (data->pids[i] < 0)
		{
			write(2, "Error: Failed to create philosopher process\n", 44);
			break ;
		}
		i++;
	}
}

void	start_simulation(t_data *data, pthread_t *monitor_thread)
{
	int	i;

	pthread_create(monitor_thread, NULL, monitor, data);
	start_philo_processes(data);
	i = -1;
	while (++i < data->num_philos)
		sem_wait(data->full);
	i = -1;
	while (++i < data->num_philos)
		sem_post(data->kill);
	wait_processes(data);
	sem_post(data->dead);
	pthread_join(*monitor_thread, NULL);
}

int	main(int argc, char **argv)
{
	t_data		data;
	pthread_t	monitor_thread;

	if (initialize_data(argc, argv, &data))
		return (1);
	if (initialize_semaphores(&data))
		return (1);
	if (initialize_philosophers(&data))
		return (1);
	start_simulation(&data, &monitor_thread);
	cleanup_semaphores(&data);
	free(data.philo);
	return (0);
}
