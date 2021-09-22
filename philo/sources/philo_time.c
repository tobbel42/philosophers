/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_time.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrossma <tgrossma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 17:01:02 by tgrossma          #+#    #+#             */
/*   Updated: 2021/09/22 10:42:02 by tgrossma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

/*
//returns time since the start in ms
*/
long	philo_get_timestamp(t_data *data)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000) - data->s_t);
}

/*
//sets start time
*/
void	philo_get_start_time(t_data *data)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	data->s_t = (time.tv_sec * 1000) + (time.tv_usec / 1000);
}
