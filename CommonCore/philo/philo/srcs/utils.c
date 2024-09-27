/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcsicsak <dcsicsak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 15:49:39 by dcsicsak          #+#    #+#             */
/*   Updated: 2024/09/14 19:51:44 by dcsicsak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	handle_error(char *err)
{
	write(2, err, ft_strlen(err));
}

long	get_time_in_ms(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

int	sleep_for(long time_in_ms, t_data *data)
{
	long	start_time;

	start_time = get_time_in_ms();
	while ((get_time_in_ms() - start_time) < time_in_ms)
	{
		pthread_mutex_lock(&data->state_lock);
		if (!data->simulation_running)
		{
			pthread_mutex_unlock(&data->state_lock);
			return (1);
		}
		pthread_mutex_unlock(&data->state_lock);
		usleep(100);
	}
	return (0);
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
			printf("Error: All arguments must be valid numbers.\n");
			return (1);
		}
		if (argv[i][0] == '-')
		{
			printf("Error: Negative numbers are not allowed.\n");
			return (1);
		}
		i++;
	}
	return (0);
}

bool	ft_validate_number(const char *str, size_t *result)
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
		printf("Error: Number too long!\n");
		return (false);
	}
	free(converted_str);
	*result = number;
	return (true);
}
