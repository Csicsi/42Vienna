/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcsicsak <dcsicsak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 08:47:04 by dcsicsak          #+#    #+#             */
/*   Updated: 2024/11/27 08:48:46 by dcsicsak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_bonus.h"

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
		write(2, "Error: Number too long!\n", 24);
		return (false);
	}
	free(converted_str);
	*result = number;
	return (true);
}

long	get_time_in_ms(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
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
