/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcsicsak <dcsicsak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 17:23:09 by dcsicsak          #+#    #+#             */
/*   Updated: 2024/09/14 19:37:19 by dcsicsak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static int	create_threads(t_data *data, pthread_t *threads)
{
	int	i;
	int	ret;

	i = 0;
	while (i < data->num_philos)
	{
		ret = pthread_create(&threads[i], NULL,
				philo_routine, &data->philo[i]);
		if (ret != 0)
		{
			handle_error("Error: Failed to create philosopher thread\n");
			pthread_mutex_lock(&data->state_lock);
			data->simulation_running = 0;
			pthread_mutex_unlock(&data->state_lock);
			return (i);
		}
		i++;
	}
	return (-1);
}

static void	start_simulation(t_data *data)
{
	pthread_t	*threads;
	pthread_t	monitor_thread;
	int			num_created;

	threads = malloc(sizeof(pthread_t) * data->num_philos);
	if (!threads)
		return (handle_error("Error: Failed to allocate memory for threads\n"));
	data->start_time = get_time_in_ms();
	data->simulation_running = true;
	if (pthread_create(&monitor_thread, NULL, monitor_philos, data) != 0)
	{
		handle_error("Error: Failed to create monitor thread\n");
		pthread_mutex_lock(&data->state_lock);
		data->simulation_running = 0;
		pthread_mutex_unlock(&data->state_lock);
		return (free(threads));
	}
	num_created = create_threads(data, threads);
	if (num_created != -1)
		return (cleanup_threads(threads, num_created, monitor_thread));
	num_created = 0;
	while (num_created < data->num_philos)
		pthread_join(threads[num_created++], NULL);
	pthread_join(monitor_thread, NULL);
	free(threads);
}

static int	set_data(int argc, char **argv, t_data *data)
{
	size_t	temp;

	if (!ft_validate_number(argv[1], &temp))
		return (1);
	data->num_philos = temp;
	if (!ft_validate_number(argv[2], &temp))
		return (1);
	data->time_to_die = temp;
	if (!ft_validate_number(argv[3], &temp))
		return (1);
	data->time_to_eat = temp;
	if (!ft_validate_number(argv[4], &temp))
		return (1);
	data->time_to_sleep = temp;
	if (argc == 6)
	{
		if (!ft_validate_number(argv[5], &temp))
			return (1);
		data->meals_required = temp;
	}
	else
		data->meals_required = -1;
	if (data->meals_required == 0 || data->num_philos == 0)
		return (1);
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	data;
	int		ret;

	ret = validate_input(argc, argv);
	if (ret != 0)
		return (ret);
	ret = set_data(argc, argv, &data);
	if (ret != 0)
		return (ret);
	init_philosophers(&data);
	start_simulation(&data);
	free(data.forks);
	free(data.philo);
	return (0);
}
