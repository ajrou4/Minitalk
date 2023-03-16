/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majrou <majrou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 20:24:11 by majrou            #+#    #+#             */
/*   Updated: 2023/03/16 00:48:53 by majrou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	signal_handler(int signal, siginfo_t *info)
{
	static int				i = 7;
	static unsigned char	c;

	ft_printf("Received signal %d from process %d\n", signal, info->si_pid);
	if (signal == SIGUSR1)
		c ^= 1 << i;
	i--;
	if (i == -1)
	{
		write(1, &c, 2);
		i = 7;
		c = 0;
	}
}

int	main(void)
{
	pid_t	server_pid;
	// struct sigaction info;

	// info.sa_handler;
	server_pid = getpid();
	ft_printf("Server PID: %d\n", server_pid);
	signal(SIGUSR1, signal_handler);
	signal(SIGUSR2, signal_handler);
	while (1)
	{
		pause();
	}
	return (0);
}
