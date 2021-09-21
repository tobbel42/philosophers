/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_death.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrossma <tgrossma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 12:35:58 by tgrossma          #+#    #+#             */
/*   Updated: 2021/09/21 16:19:05 by tgrossma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	*philo_death_routine(void *arg)
{
	t_data	*data;
	int		i;

	data = (t_data *)arg;
	philo_get_start_time(data);
	data->go = 1;
	i = 0;
	while (i < data->n_philo && !data->death)
	{
		data->c_t = philo_get_timestamp(data);
		if (data->c_t - data->t_last_meal[i] > data->die_t)
			philo_print(data, 5, data->c_t, i + 1);
		i++;
		if (i == data->n_philo)
			i = 0;
	}
	return (NULL);
}

void	*philo_eat_routine(void *arg)
{
	t_data	*data;
	int		i;
	int		eat_count;

	data = (t_data *)arg;
	i = 0;
	eat_count = 0;
	while (i < data->n_philo && !data->death)
	{
		if (data->meals_eaten[i] >= data->n_to_eat)
			eat_count++;
		i++;
		if (i == data->n_philo)
		{
			if (eat_count == data->n_philo)
				data->death = 1;
			else
				eat_count = 0;
			i = 0;
		}
	}
	return (NULL);
}
