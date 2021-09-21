/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrossma <tgrossma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 14:52:35 by tgrossma          #+#    #+#             */
/*   Updated: 2021/09/21 12:29:23 by tgrossma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	main(int argc, char **argv)
{
	t_data	*data;

	if (argc != 5 && argc != 6)
		return (philo_errors(1));
	data = (t_data *)malloc(sizeof(t_data));
	if (!data)
		return (philo_errors(2));
	if (philo_init(argc, argv, data))
	{
		free(data);
		return (philo_errors(3));
	}
	philo_create_threads(data);
	burn_the_evidence(data);
	system("leaks philo");
	return (0);
}
