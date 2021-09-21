/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrossma <tgrossma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 12:49:41 by tgrossma          #+#    #+#             */
/*   Updated: 2021/09/21 13:24:53 by tgrossma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static int	ft_atoi(char *s)
{
	int		i;
	long	nbr;

	i = 0;
	nbr = 0;
	while ((s[i] >= 9 && s[i] <= 15) || s[i] == 32)
		i++;
	if (s[i] < '0' || s[i] > '9')
		return (-1);
	while (s[i] >= '0' && s[i] <= '9')
	{
		nbr = (nbr * 10) + (s[i] - '0');
		i++;
	}
	if (s[i] != '\0' || nbr > INT_MAX)
		return (-1);
	return (nbr);
}

static int	create_the_forks(t_data *data)
{
	int	i;

	i = 0;
	data->forks = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * data->n_philo);
	if (!data->forks)
		return (1);
	while (i < data->n_philo)
	{
		pthread_mutex_init(&data->forks[i], NULL);
		i++;
	}
	return (0);
}

/*
//initializes data with the input values, returns 1 on error
*/
int	philo_init(int argc, char **argv, t_data *data)
{
	data->n_philo = ft_atoi(argv[1]);
	if (data->n_philo < 1)
		return (1);
	data->die_t = ft_atoi(argv[2]);
	if (data->die_t < 0)
		return (1);
	data->eat_t = ft_atoi(argv[3]);
	if (data->eat_t < 0)
		return (1);
	data->sleep_t = ft_atoi(argv[4]);
	if (data->sleep_t < 0)
		return (1);
	data->eat_flag = 0;
	if (argc == 6)
	{
		data->n_to_eat = ft_atoi(argv[5]);
		if (data->n_to_eat < 0)
			return (1);
		data->eat_flag = 1;
	}
	data->forks = NULL;
	create_the_forks(data);
	pthread_mutex_init(&data->print, NULL);
	data->go = 0;
	data->death = 0;
	data->t_last_meal = (long *)malloc(sizeof(long) * data->n_philo);
	data->meals_eaten = (int *)malloc(sizeof(int) * data->n_philo);
	return (0);
}
