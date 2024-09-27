/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcsicsak <dcsicsak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 19:18:20 by csicsi            #+#    #+#             */
/*   Updated: 2024/09/27 10:13:16 by dcsicsak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/time.h>
#include <signal.h>
#include <semaphore.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <string.h>

typedef struct s_data
{
	int		num_philos;
	long	time_to_die;
	long	time_to_eat;
	long	time_to_sleep;
	long	time_to_think;
	int		meals_required;
	long	start_time;
	sem_t	*forks;
	sem_t	*print_lock;
	sem_t	*state_lock;
	sem_t	*meals_lock;
	sem_t	*done_lock;
	sem_t	*meal_time_lock;
	int		all_philos_done;
	pid_t	*pids;
}	t_data;

typedef struct s_philosopher
{
	int		id;
	long	last_meal;
	long	delay;
	int		meals_eaten;
	t_data	*data;
}	t_philosopher;


#endif
