/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csicsi <csicsi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 19:18:20 by csicsi            #+#    #+#             */
/*   Updated: 2024/11/22 16:16:40 by csicsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <semaphore.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <sys/time.h>
# include <pthread.h>
# include <stdbool.h>
# include <stdint.h>

typedef struct s_philosopher
{
	int				id;
	long			last_meal;
	int				meals_eaten;
	long			delay;
	struct s_data	*data;
	pid_t			pid;
	bool			terminate;
	sem_t			*lock;
}				t_philosopher;

typedef struct s_data
{
	int				num_philos;
	long			time_to_die;
	long			time_to_eat;
	long			time_to_sleep;
	long			time_to_think;
	long			meals_required;
	long			start_time;
	sem_t			*forks;
	sem_t			*print_lock;
	sem_t			*state_lock;
	sem_t			*full;
	sem_t			*dead;
	sem_t			*kill;
	t_philosopher	*philo;
	pid_t			*pids;
	bool			simulation_running;
}				t_data;


#endif
