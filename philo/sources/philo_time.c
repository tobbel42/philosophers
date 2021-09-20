/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_time.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrossma <tgrossma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 17:01:02 by tgrossma          #+#    #+#             */
/*   Updated: 2021/09/20 17:27:46 by tgrossma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

long	philo_get_timestamp(t_data *data)
{
	long			temp;
	struct timeval	time;

	gettimeofday(&time, NULL);
	temp = (time.tv_sec * 1000) + (time.tv_usec / 1000);
	return (temp - data->start_time); 
}

void	philo_get_start_time(t_data *data)
{
	long			temp;
	struct timeval	time;

	gettimeofday(&time, NULL);
	temp = (time.tv_sec * 1000) + (time.tv_usec / 1000);
	data->start_time = temp; 
}