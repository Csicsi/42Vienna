/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcsicsak <dcsicsak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 08:54:56 by dcsicsak          #+#    #+#             */
/*   Updated: 2024/11/27 09:09:37 by dcsicsak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_bonus.h"

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
		if (is_terminated(philo))
			break ;
		handle_sleep_and_think(philo);
		if (is_terminated(philo))
			break ;
	}
	cleanup_resources(philo, &monitoring_thread, &kill_thread);
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
			exit (0);
		}
		else if (data->pids[i] < 0)
		{
			write(2, "Error: Failed to create philosopher process\n", 44);
			break ;
		}
		i++;
	}
}

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

void	start_simulation(t_data *data, pthread_t *monitor_thread)
{
	int	i;

	if (pthread_create(monitor_thread, NULL, monitor, data))
		return ;
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
