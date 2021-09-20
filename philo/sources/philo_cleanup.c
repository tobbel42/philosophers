/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_cleanup.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrossma <tgrossma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 15:06:46 by tgrossma          #+#    #+#             */
/*   Updated: 2021/09/20 18:00:02 by tgrossma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	join_the_philos(t_philo **philos, t_data *data)
{
	int i;

	i = 0;
	while (i < data->n_philo)
	{
		pthread_mutex_unlock(&data->forks[i]);
		i++;
	}
	i = 0;
	while (i < data->n_philo)
	{
		pthread_join(philos[i]->thread, NULL);
		i++;
	}
}