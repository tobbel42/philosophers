/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrossma <tgrossma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 13:22:05 by tgrossma          #+#    #+#             */
/*   Updated: 2021/09/21 16:19:10 by tgrossma         ###   ########.fr       */
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

int	philo_atoi(char *s, t_data *data, int min, int max)
{
	int		i;
	long	nbr;

	i = 0;
	nbr = 0;
	while ((s[i] >= 9 && s[i] <= 15) || s[i] == 32)
		i++;
	if (s[i] < '0' || s[i] > '9')
	{
		data->error_flag = 1;
		return (-1);
	}
	while (s[i] >= '0' && s[i] <= '9')
	{
		nbr = (nbr * 10) + (s[i] - '0');
		i++;
	}
	if (s[i] != '\0' || nbr > max || nbr < min)
	{
		data->error_flag = 1;
		return (-1);
	}
	return (nbr);
}
