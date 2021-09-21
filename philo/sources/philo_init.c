/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrossma <tgrossma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 12:49:41 by tgrossma          #+#    #+#             */
/*   Updated: 2021/09/21 15:39:10 by tgrossma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static int	create_the_forks(t_data *data)
{
	int	i;

	i = 0;
	data->forks = (pthread_mutex_t *)malloc(
			sizeof(pthread_mutex_t) * data->n_philo);
	if (!data->forks)
		return (1);
	while (i < data->n_philo)
	{
		if (pthread_mutex_init(&data->forks[i], NULL))
			data->error_flag = 1;
		i++;
	}
	return (0);
}

static void	init_the_nbrs(int argc, char **argv, t_data *data)
{
	data->error_flag = 0;
	data->n_philo = philo_atoi(argv[1], data, 1, INT_MAX);
	data->die_t = philo_atoi(argv[2], data, 0, INT_MAX);
	data->eat_t = philo_atoi(argv[3], data, 0, INT_MAX);
	data->sleep_t = philo_atoi(argv[4], data, 0, INT_MAX);
	data->eat_flag = 0;
	data->go = 0;
	data->death = 0;
	if (argc == 6)
	{
		data->n_to_eat = philo_atoi(argv[5], data, 1, INT_MAX);
		data->eat_flag = 1;
	}
	data->forks = NULL;
	data->t_last_meal = NULL;
	data->meals_eaten = NULL;
}

/*
//returns an initialized data struct, on any error the errorflag is set to 1
*/
t_data	*philo_init(int argc, char **argv)
{
	t_data	*data;

	data = (t_data *)malloc(sizeof(t_data));
	if (!data)
		return (NULL);
	init_the_nbrs(argc, argv, data);
	if (create_the_forks(data))
		data->error_flag = 1;
	if (pthread_mutex_init(&data->print, NULL))
		data->error_flag = 1;
	data->t_last_meal = (long *)malloc(sizeof(long) * data->n_philo);
	data->meals_eaten = (int *)malloc(sizeof(int) * data->n_philo);
	if (!data->t_last_meal || !data->meals_eaten)
		data->error_flag = 1;
	return (data);
}
