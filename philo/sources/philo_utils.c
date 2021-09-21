/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrossma <tgrossma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 13:22:05 by tgrossma          #+#    #+#             */
/*   Updated: 2021/09/21 15:01:01 by tgrossma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	philo_print(t_data *data, int mode, long time, int id)
{
	char	*s;

	if (data->death)
		return ;
	if (mode == 1)
		s = "is sleeping";
	else if (mode == 2)
		s = "is thinking";
	else if (mode == 3)
		s = "has taken a fork";
	else if (mode == 4)
		s = "is eating";
	else if (mode == 5)
		s = "died";
	pthread_mutex_lock(&data->print);
	usleep(1);
	if (!data->death)
	{
		if (mode == 5)
			data->death = 1;
		printf("%ld\t%i\t%s\n", time, id, s);
	}
	pthread_mutex_unlock(&data->print);
}
