/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrossma <tgrossma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 12:36:47 by tgrossma          #+#    #+#             */
/*   Updated: 2021/09/21 15:47:39 by tgrossma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

/*
//prints a defined error message to stderr
*/
int	philo_errors(int err_code)
{
	if (err_code == 1)
		write(2, "Error: incorrect number of arguments\n", 37);
	else if (err_code == 2)
		write(2, "Error: malloc error\n", 20);
	else if (err_code == 3)
		write(2, "Error: wrong input argument\n", 28);
	else if (err_code == 4)
		write(2, "Error: could not create threads\n", 32);
	else
		write(2, "Error\n", 6);
	return (1);
}
