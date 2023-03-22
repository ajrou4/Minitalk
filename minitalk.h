/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majrou <majrou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 04:28:25 by majrou            #+#    #+#             */
/*   Updated: 2023/03/22 03:24:53 by majrou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <unistd.h>
# include <signal.h>
# include "ft_printf/ft_printf.h"

int		ft_atoi(char *str);
void	signal_handler(int sig, siginfo_t *info, void *message);
void	message_valide(int sig, siginfo_t *info, void *message);

#endif
