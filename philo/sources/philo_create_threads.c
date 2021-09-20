/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_create_threads.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrossma <tgrossma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 12:01:24 by tgrossma          #+#    #+#             */
/*   Updated: 2021/09/20 18:02:53 by tgrossma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static t_philo	*create_philo(int id, t_data *data)
{
	t_philo	*philo;

	philo = (t_philo *)malloc(sizeof(t_philo));
	if (!philo)
		return (NULL);
	philo->id = id + 1;
	philo->n_eat = 0;
	philo->data = data;
	philo->thread = NULL;
	return (philo);
}

int	philo_create_threads(t_data *data)
{
	int			i;
	pthread_t	death;
	t_philo		**philos;

	death = NULL;
	philos = (t_philo **)malloc(sizeof(t_philo *) * data->n_philo);
	if (!philos)
		return (1);
	i = 0;
	while (i < data->n_philo)
	{
		philos[i] = create_philo(i, data);
		if (!philos[i])
			break;
		if (i % 2)
			pthread_create(&philos[i]->thread, NULL, philo_odd_routine, philos[i]);
		else
			pthread_create(&philos[i]->thread, NULL, philo_even_routine, philos[i]);
		i++;
	}
	pthread_create(&death, NULL, philo_death_routine, data);
	pthread_join(death, NULL);
	join_the_philos(philos, data);
	return (0);
}
