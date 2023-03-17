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

void	signal_handler(int sig, siginfo_t *info, void *message)
{
	static int				i = 7;
	static unsigned char	c;
	static int				client_pid;

	(void)message;
	if (client_pid != info->si_pid)
	{
		client_pid = info->si_pid;
		i = 7;
	}
	if (sig == SIGUSR1)
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
	pid_t				server_pid;
	struct sigaction	info;

	info.sa_sigaction = &signal_handler;
	info.sa_flags = SA_SIGINFO;
	server_pid = getpid();
	ft_printf("Server PID: %d\n", server_pid);
	sigaction(SIGUSR1, &info, NULL);
	sigaction(SIGUSR2, &info, NULL);
	while (1)
	{
		pause();
	}
	return (0);
}
