/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putadress.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majrou <majrou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 02:04:57 by majrou            #+#    #+#             */
/*   Updated: 2022/10/31 06:26:18 by majrou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex(unsigned long n, char c)
{
	int	len;

	len = ft_len(n);
	if (n >= 16)
	{
		ft_puthex(n / 16, c);
		ft_puthex(n % 16, c);
	}
	else if (n <= 9)
		ft_putchar(n + '0');
	else if (n > 9 && n < 16)
	{
		if (c == 'x')
			ft_putchar(n - 10 + 'a');
		if (c == 'X')
			ft_putchar(n - 10 + 'A');
	}
	return (len);
}

int	ft_putadress(unsigned long int nbr)
{
	int		len;

	len = 0;
	len += ft_putstr("0x");
	len += ft_puthex(nbr, 'x');
	return (len);
}
