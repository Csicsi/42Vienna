/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init2_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcsicsak <dcsicsak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 08:52:04 by dcsicsak          #+#    #+#             */
/*   Updated: 2024/11/27 08:52:08 by dcsicsak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_bonus.h"

int	initialize_semaphores(t_data *data)
{
	data->forks = create_semaphore("/forks", data->num_philos);
	if (!data->forks)
		return (write(2, "Error: Failed to create forks semaphore\n", 40), 1);
	data->print_lock = create_semaphore("/print_lock", 1);
	if (!data->print_lock)
		return (cleanup_semaphores(data),
			write(2, "Error: Failed to create print_lock semaphore\n", 45), 1);
	data->state_lock = create_semaphore("/state_lock", 1);
	if (!data->state_lock)
		return (write(2, "Error: Failed to create state_lock sem\n", 40), 1);
	data->full = create_semaphore("/full", 0);
	if (!data->full)
		return (cleanup_semaphores(data),
			write(2, "Error: Failed to create full semaphore\n", 39), 1);
	data->dead = create_semaphore("/dead", 0);
	if (!data->dead)
		return (cleanup_semaphores(data),
			write(2, "Error: Failed to create dead semaphore\n", 39), 1);
	data->kill = create_semaphore("/kill", 0);
	if (!data->kill)
		return (cleanup_semaphores(data),
			write(2, "Error: Failed to create kill semaphore\n", 39), 1);
	return (0);
}

int	initialize_threads(t_philosopher *philo,
	pthread_t *monitoring_thread, pthread_t *kill_thread)
{
	if (pthread_create(monitoring_thread, NULL, check_death, philo) != 0)
	{
		cleanup_semaphores(philo->data);
		free(philo->data->pids);
		free(philo->data->philo);
		return (-1);
	}
	if (pthread_create(kill_thread, NULL, kill_philo, philo) != 0)
	{
		cleanup_semaphores(philo->data);
		free(philo->data->pids);
		free(philo->data->philo);
		pthread_join(*monitoring_thread, NULL);
		return (-1);
	}
	return (0);
}

int	parse_arguments(int argc, char **argv, t_data *data)
{
	size_t	temp;

	*data = (t_data){0};
	if (validate_input(argc, argv))
		return (1);
	if (!ft_validate_number(argv[1], &temp) || temp == 0)
		return (write(2, "Error: Invalid number of philosophers\n", 38), 1);
	data->num_philos = temp;
	if (!ft_validate_number(argv[2], &temp))
		return (write(2, "Error: Invalid time to die\n", 27), 1);
	data->time_to_die = temp;
	if (!ft_validate_number(argv[3], &temp))
		return (write(2, "Error: Invalid time to eat\n", 27), 1);
	data->time_to_eat = temp;
	if (!ft_validate_number(argv[4], &temp))
		return (write(2, "Error: Invalid time to sleep\n", 29), 1);
	data->time_to_sleep = temp;
	if (argc == 6 && ft_validate_number(argv[5], &temp))
		data->meals_required = temp;
	else
		data->meals_required = -1;
	return (0);
}

int	initialize_data(int argc, char **argv, t_data *data)
{
	long	thinking_time;

	if (parse_arguments(argc, argv, data))
		return (1);
	if (data->num_philos % 2 == 1 && data->num_philos > 1)
	{
		thinking_time = data->time_to_eat / (float)(data->num_philos / 2);
		data->time_to_think = data->time_to_eat
			- data->time_to_sleep + thinking_time;
	}
	else
		data->time_to_think = data->time_to_eat - data->time_to_sleep;
	data->start_time = get_time_in_ms();
	return (0);
}
