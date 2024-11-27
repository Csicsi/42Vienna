/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcsicsak <dcsicsak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 19:18:20 by csicsi            #+#    #+#             */
/*   Updated: 2024/11/27 08:57:47 by dcsicsak         ###   ########.fr       */
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
	sem_t			*terminate_lock;
	char			terminate_sem_name[32];
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
}				t_data;

//libft_bonus.c
int		is_number(char *str);
int		numlen(size_t n);
char	*ft_sttoa(size_t n);
size_t	ft_atost(const char *nptr);
size_t	ft_strlen(const char *s);

//libft2_bonus.c
int		ft_strncmp(const char *s1, const char *s2, size_t n);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
char	*ft_strjoin(char const *s1, char const *s2);

//sems_bonus.c
sem_t	*create_semaphore(char *name, int value);
void	close_and_unlink_semaphore(sem_t **sem, const char *name);
void	cleanup_semaphores(t_data *data);
bool	is_terminated(t_philosopher *philo);
void	set_terminate(t_philosopher *philo, bool value);

//utils_bonus.c

bool	ft_validate_number(const char *str, size_t *result);
long	get_time_in_ms(void);
int		sleep_for(long time_in_ms, t_philosopher *philo);
void	print_status(t_philosopher *philo, char *status);
void	wait_processes(t_data *data);
int		validate_input(int argc, char **argv);

//init_bonus.c
void	create_terminate_sem_name(char *terminate_sem_name,
			size_t size, int id);
int		initialize_philosopher_array(t_data *data);
int		initialize_philosopher(t_philosopher *philo, t_data *data, int index);
int		initialize_philosophers(t_data *data);

//init2_bonus.c
int		initialize_semaphores(t_data *data);
int		initialize_threads(t_philosopher *philo,
			pthread_t *monitoring_thread, pthread_t *kill_thread);
int		parse_arguments(int argc, char **argv, t_data *data);
int		initialize_data(int argc, char **argv, t_data *data);

//monitoring_bonus.c
void	*kill_philo(void *arg);
void	*check_death(void *arg);
void	*monitor(void *arg);

//simulation_bonus.c
void	handle_single_philosopher(t_philosopher *philo);
void	cleanup_resources(t_philosopher *philo,
			pthread_t *monitoring_thread, pthread_t *kill_thread);
int		handle_delay(t_philosopher *philo,
			pthread_t *monitoring_thread, pthread_t *kill_thread);
void	handle_eating(t_philosopher *philo);
void	handle_sleep_and_think(t_philosopher *philo);

#endif
