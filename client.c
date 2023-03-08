/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majrou <majrou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 00:58:49 by majrou            #+#    #+#             */
/*   Updated: 2023/03/08 01:36:39 by majrou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	send_Char_to_server(pid_t PID, unsigned char	string)
{
	unsigned char	bit;

	bit = 0b10000000;
	while (bit)
	{
		if (bit && string)
		{
			if (kill(PID, SIGUSR1) == -1)
				return (0);
		}
		else
		{
			if (kill(PID, SIGUSR2) == -1)
				return (0);
		}
		bit >>= 1;
		usleep(100);
	}
	return (1);
}

int	main(int ac, char **av)
{
	return (0);
}