/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrossma <tgrossma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 12:13:50 by tgrossma          #+#    #+#             */
/*   Updated: 2021/09/22 10:38:16 by tgrossma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

/*
//for even philosophers, they start eating
*/
void	*philo_even_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (!philo->data->go)
		usleep(1);
	philo->data->t_last_meal[philo->id - 1] = philo->data->c_t;
	while (!philo->data->death)
	{
		philo_eat(philo);
		if (philo->data->death)
			break ;
		philo_sleep(philo);
	}
	return (NULL);
}

/*
//for odd philosophers, they start sleeping
*/
void	*philo_odd_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (!philo->data->go)
		usleep(1);
	philo->data->t_last_meal[philo->id - 1] = philo->data->c_t;
	while (!philo->data->death)
	{	
		philo_sleep(philo);
		if (philo->data->death)
			break ;
		philo_eat(philo);
	}
	return (NULL);
}

/*
//sleep routine, sleep, then think
*/
void	philo_sleep(t_philo *philo)
{
	long	s_t;

	s_t = philo_get_timestamp(philo->data);
	philo_print(philo->data, 1, s_t, philo->id);
	while (philo->data->c_t - s_t < philo->data->sleep_t && !philo->data->death)
		usleep(100);
	philo_print(philo->data, 2, philo->data->c_t, philo->id);
}

/*
//eat routine, grap 2 forks, then eat
*/
void	philo_eat(t_philo *philo)
{
	long	s_t;

	if (philo->id == philo->data->n_philo && !philo->data->death)
		pthread_mutex_lock(&philo->data->forks[0]);
	else if (!philo->data->death)
		pthread_mutex_lock(&philo->data->forks[philo->id]);
	philo_print(philo->data, 3, philo->data->c_t, philo->id);
	if (!philo->data->death)
		pthread_mutex_lock(&philo->data->forks[philo->id - 1]);
	philo_print(philo->data, 3, philo->data->c_t, philo->id);
	s_t = philo->data->c_t;
	philo->data->t_last_meal[philo->id - 1] = s_t;
	philo_print(philo->data, 4, s_t, philo->id);
	while (philo->data->c_t - s_t <= philo->data->eat_t && !philo->data->death)
		usleep(100);
	if (philo->id == philo->data->n_philo)
		pthread_mutex_unlock(&philo->data->forks[0]);
	else
		pthread_mutex_unlock(&philo->data->forks[philo->id]);
	pthread_mutex_unlock(&philo->data->forks[philo->id - 1]);
	if (philo->data->eat_flag)
		philo->data->meals_eaten[philo->id - 1]++;
}
