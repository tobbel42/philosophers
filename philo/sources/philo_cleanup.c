/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_cleanup.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrossma <tgrossma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 15:06:46 by tgrossma          #+#    #+#             */
/*   Updated: 2021/09/22 10:32:57 by tgrossma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

/*
//unlocks any philos stuck with a fork,
//then waits till all philo threads have ended
*/
void	join_the_philos(t_philo **philos, t_data *data)
{
	int	i;

	i = 0;
	while (i < data->n_philo)
	{
		pthread_mutex_unlock(&data->forks[i]);
		i++;
	}
	i = 0;
	while (i < data->n_philo && philos[i])
	{
		pthread_join(philos[i]->thread, NULL);
		i++;
	}
}

/*
//frees all the philosophers and then the array itself
*/
void	vanish_the_corpses(t_philo **philos, t_data *data)
{
	int	i;

	if (!philos)
		return ;
	i = 0;
	while (i < data->n_philo && philos[i])
	{
		free(philos[i]);
		i++;
	}
	free(philos);
	philos = NULL;
}

/*
//destroys all fork mutex locks
*/
static void	vanish_the_forks(t_data *data)
{
	int	i;

	i = 0;
	if (!data->forks)
		return ;
	while (i < data->n_philo)
	{
		pthread_mutex_destroy(&data->forks[i]);
		i++;
	}
	free(data->forks);
	data->forks = NULL;
}

/*
//cleans up the whole data struct
*/
void	burn_the_evidence(t_data *data)
{
	if (!data)
		return ;
	vanish_the_forks(data);
	if (data->t_last_meal)
	{
		free(data->t_last_meal);
		data->t_last_meal = NULL;
	}
	if (data->meals_eaten)
	{
		free(data->meals_eaten);
		data->meals_eaten = NULL;
	}
	pthread_mutex_unlock(&data->print);
	pthread_mutex_destroy(&data->print);
	free(data);
	data = NULL;
}
