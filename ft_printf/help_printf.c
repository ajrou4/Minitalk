/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_printf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majrou <majrou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 06:40:03 by majrou            #+#    #+#             */
/*   Updated: 2022/10/31 06:22:29 by majrou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	int	len;

	len = 0;
	len += write(1, &c, 1);
	return (len);
}

int	ft_putstr(char *str)
{
	int	i;
	int	len;

	len = 0;
	if (!str)
	{
		write (1, "(null)", 6);
		return (6);
	}
	i = 0;
	while (str[i])
	{
		len += ft_putchar(str[i]);
		i++;
	}
	return (len);
}

int	ft_putnbr(int nbr)
{
	int	len;

	len = 0;
	if (nbr == -2147483648)
	{
		len += write (1, "-2147483648", 11);
		return (len);
	}
	if (nbr < 0)
	{
		len += ft_putchar(45);
		nbr *= -1;
	}
	if (nbr >= 10)
	{
		len += ft_putnbr(nbr / 10);
		len += ft_putnbr(nbr % 10);
	}
	else
		len += ft_putchar(nbr + 48);
	return (len);
}

int	ft_putnbr_unsigned(unsigned int nbr)
{
	unsigned int	len;

	len = 0;
	if (nbr > 9)
	{
		len += ft_putnbr_unsigned(nbr / 10);
		len += ft_putchar(nbr % 10 + 48);
	}
	else
		len += ft_putchar(nbr + '0');
	return (len);
}

int	ft_len(unsigned long n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		len++;
		n = n / 16;
	}
	return (len);
}
