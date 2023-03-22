/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majrou <majrou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 05:51:55 by majrou            #+#    #+#             */
/*   Updated: 2023/03/22 03:28:14 by majrou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	message_valide(int sig, siginfo_t *info, void *message)
{
	(void)info;
	(void)message;
	if (sig == SIGUSR1)
		write(1, "vu\n", 3);
}

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
	int					bit;
	struct sigaction	info;

	info.sa_sigaction = &message_valide;
	info.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &info, NULL);
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
		kill('\0', SIGUSR1);
	}
	else
		write(1, "somting is error\n", 17);
	return (0);
}
