/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrossma <tgrossma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 12:13:50 by tgrossma          #+#    #+#             */
/*   Updated: 2021/09/20 18:17:05 by tgrossma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	*philo_even_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (!philo->data->go)
		usleep(1);
	philo->data->t_last_meal[philo->id] = philo->data->curr_time;
	while (!philo->data->death)
	{
		philo_eat(philo);
		if (philo->data->death)
			break;
		philo_sleep(philo);
	}
	return (NULL);
}

void	*philo_odd_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;	
	while (!philo->data->go)
		usleep(1);
	philo->data->t_last_meal[philo->id] = philo->data->curr_time;
	while (!philo->data->death)
	{	
		philo_sleep(philo);
		if (philo->data->death)
			break;
		philo_eat(philo);
	}
	return (NULL);
}

void	philo_sleep(t_philo *philo)
{
	long	start_time;

	start_time = philo_get_timestamp(philo->data);
	if (!philo->data->death)
		printf("%ld\t%i\tis sleeping\n", start_time, philo->id);
	while (philo->data->curr_time - start_time < philo->data->sleep_t && !philo->data->death)
		usleep(100);		//mod here
	if (!philo->data->death)
		printf("%ld\t%i\tis thinking\n", philo->data->curr_time, philo->id);
}

void	philo_eat(t_philo *philo)
{
	long	start_time;

	if (philo->id == philo->data->n_philo && !philo->data->death)
		pthread_mutex_lock(&philo->data->forks[0]);
	else if (philo->data->death)
		pthread_mutex_lock(&philo->data->forks[philo->id]);
	if (!philo->data->death)
		printf("%ld\t%i\thas taken a fork\n", philo->data->curr_time , philo->id);
	if (!philo->data->death)
		pthread_mutex_lock(&philo->data->forks[philo->id - 1]);
	if (!philo->data->death)
		printf("%ld\t%i\thas taken a fork\n", philo->data->curr_time , philo->id);
	start_time = philo->data->curr_time;
	philo->data->t_last_meal[philo->id - 1] = start_time;
	if (!philo->data->death)
		printf("%ld\t%i\tis eating\n", start_time , philo->id);
	while (philo->data->curr_time - start_time <= philo->data->eat_t && !philo->data->death)
		usleep(100);		//mod here
	if (philo->id == philo->data->n_philo)
		pthread_mutex_unlock(&philo->data->forks[0]);
	else
		pthread_mutex_unlock(&philo->data->forks[philo->id]);
	pthread_mutex_unlock(&philo->data->forks[philo->id - 1]);
	philo->n_eat++;
}

void	*philo_death_routine(void *arg)
{
	t_data	*data;
	int 	i;

	data = (t_data *)arg;
	philo_get_start_time(data);
	data->go = 1;
	i = 0;
	while (i < data->n_philo)
	{
		data->curr_time = philo_get_timestamp(data);
		if (data->curr_time - data->t_last_meal[i] > data->die_t)
		{
			printf("%ld\t%i\thas died\n", data->curr_time, i + 1);
			data->death = 1;
			break ;
		}
		i++;
		if (i == data->n_philo)
			i = 0;
	}
	return (NULL);
}
