/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcsicsak <dcsicsak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 09:52:08 by dcsicsak          #+#    #+#             */
/*   Updated: 2024/09/14 19:41:23 by dcsicsak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>
# include <stdbool.h>
# include <stdint.h>

typedef struct s_philosopher
{
	int				id;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	long			last_meal;
	size_t			meals_eaten;
	size_t			delay;
	struct s_data	*data;
	pthread_mutex_t	meals_lock;
}				t_philosopher;

typedef struct s_data
{
	int				num_philos;
	size_t			time_to_die;
	size_t			time_to_eat;
	size_t			time_to_sleep;
	size_t			time_to_think;
	size_t			meals_required;
	long			start_time;
	pthread_mutex_t	*forks;
	pthread_mutex_t	print_lock;
	pthread_mutex_t	state_lock;
	t_philosopher	*philo;
	bool			simulation_running;
}				t_data;

void	init_philosophers(t_data *data);
void	*monitor_philos(void *arg);
void	*philo_routine(void *arg);
size_t	ft_strlen(const char *s);
void	handle_error(char *err);
long	get_time_in_ms(void);
int		sleep_for(long time_in_ms, t_data *data);
int		is_number(char *str);
void	print_status(t_philosopher *philo, char *status);
int		check_simulation_running(t_philosopher *philo);
void	cleanup_forks_and_locks(t_data *data, int i);
void	cleanup_threads(pthread_t *threads,
			int num_created, pthread_t monitor_thread);
int		validate_input(int argc, char **argv);
bool	ft_validate_number(const char *str, size_t *result);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_sttoa(size_t n);
size_t	ft_atost(const char *nptr);

#endif
