/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majrou <majrou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 04:32:30 by majrou            #+#    #+#             */
/*   Updated: 2023/03/15 23:30:23 by majrou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_atoi(char *str)
{
	long	nb;
	int		len;
	int		i;

	len = 0;
	while (str && str[len])
		len++;
	i = 0;
	nb = 0;
	while (i < len)
		nb = (nb * 10) + (str[i++] - 48);
	return (nb);
}

int	main(int ac, char **av)
{
	int	bit;

	if (ac != 3)
		write(1, "somting is error\n", 17);
	else
	{
		if (ac == 3 && ft_atoi(av[1]) > 0)
		{
			while (*av[2])
			{
				bit = 8;
				while (--bit >= 0)
				{
					if ((*av[2] >> bit) & 1)
						kill(ft_atoi(av[1]), SIGUSR1);
					else
						kill(ft_atoi(av[1]), SIGUSR2);
					usleep(100);
				}
				av[2]++;
			}
		}
	}
	return (0);
}
