/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrossma <tgrossma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 14:49:38 by tgrossma          #+#    #+#             */
/*   Updated: 2021/09/20 17:48:58 by tgrossma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>
# include <limits.h>

typedef struct data
{
	pthread_mutex_t	*forks;
	long			*t_last_meal;
	int				n_philo;
	long			sleep_t;
	long			die_t;
	long			eat_t;
	int				n_to_eat;
	int				go;
	int				death;
	long			curr_time;
	long			start_time;
}	t_data;

typedef struct philo
{
	pthread_t	thread;
	int			id;
	int			n_eat;
	t_data		*data;
}	t_philo;

int		philo_errors(int err_code);
int		philo_init(int argc, char **argv, t_data *data);
int		philo_create_threads(t_data *data);
void	join_the_philos(t_philo **philos, t_data *data);
void	*philo_death_routine(void *arg);
void	*philo_even_routine(void *arg);
void	*philo_odd_routine(void *arg);
void	philo_sleep(t_philo *philo);
void	philo_eat(t_philo *philo);
void	philo_get_start_time(t_data *data);
long	philo_get_timestamp(t_data *data);
#endif