/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrossma <tgrossma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 14:52:35 by tgrossma          #+#    #+#             */
/*   Updated: 2021/09/21 16:19:57 by tgrossma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	main(int argc, char **argv)
{
	t_data	*data;

	if (argc != 5 && argc != 6)
		return (philo_errors(1));
	data = philo_init(argc, argv);
	if (!data)
		return (philo_errors(2));
	if (data->error_flag)
	{
		burn_the_evidence(data);
		return (philo_errors(3));
	}
	if (philo_create_threads(data))
	{
		burn_the_evidence(data);
		return (philo_errors(4));
	}
	burn_the_evidence(data);
	return (0);
}
