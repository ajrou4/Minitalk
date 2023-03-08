/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majrou <majrou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 06:43:54 by majrou            #+#    #+#             */
/*   Updated: 2022/10/31 06:23:52 by majrou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>

int			ft_putchar(char c);
int			ft_putstr(char *str);
int			ft_putnbr(int nbr);
int			ft_putnbr_unsigned( unsigned int nbr);
int			ft_puthex(unsigned long nbr, char c);
int			ft_printf(const char *str, ...);
int			ft_putadress(unsigned long int nbr);
int			ft_len(unsigned long n);
#endif
