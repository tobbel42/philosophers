/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_create_threads.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrossma <tgrossma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 12:01:24 by tgrossma          #+#    #+#             */
/*   Updated: 2021/09/22 10:34:56 by tgrossma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static t_philo	*create_philo(int i, t_data *data)
{
	t_philo	*philo;

	philo = (t_philo *)malloc(sizeof(t_philo));
	if (!philo)
		return (NULL);
	philo->id = i + 1;
	philo->data = data;
	philo->thread = NULL;
	return (philo);
}

static t_philo	**create_handle(int n)
{
	t_philo	**philos;

	philos = (t_philo **)malloc(sizeof(t_philo *) * n);
	if (!philos)
		return (NULL);
	memset(philos, '\0', sizeof(t_philo *) * n);
	return (philos);
}

static int	spawn_the_philos(t_philo **philos, t_data *data)
{
	int	i;

	i = 0;
	while (i < data->n_philo)
	{
		philos[i] = create_philo(i, data);
		if (!philos[i])
			return (1);
		if (i % 2)
			pthread_create(&philos[i]->thread, NULL,
				philo_odd_routine, philos[i]);
		else
			pthread_create(&philos[i]->thread, NULL,
				philo_even_routine, philos[i]);
		i++;
	}
	return (0);
}

/*
//creates the philosophers, the death and the eat thread(if needed)
*/
int	philo_create_threads(t_data *data)
{
	pthread_t	death;
	pthread_t	eat;
	t_philo		**philos;

	death = NULL;
	eat = NULL;
	philos = create_handle(data->n_philo);
	if (!philos)
		return (1);
	if (spawn_the_philos(philos, data))
	{
		data->death = 1;
		data->go = 1;
	}
	else
	{
		if (data->eat_flag)
			pthread_create(&death, NULL, philo_eat_routine, data);
		pthread_create(&death, NULL, philo_death_routine, data);
		pthread_join(eat, NULL);
		pthread_join(death, NULL);
	}
	join_the_philos(philos, data);
	vanish_the_corpses(philos, data);
	return (0);
}
