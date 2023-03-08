/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majrou <majrou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 06:56:07 by majrou            #+#    #+#             */
/*   Updated: 2022/10/31 06:10:46 by majrou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	checker(va_list arg, char f)
{
	int	len;

	len = 0;
	if (f == 'c')
		len += ft_putchar(va_arg(arg, int));
	if (f == '%')
		len += ft_putchar('%');
	else if (f == 's')
		len += ft_putstr(va_arg(arg, char *));
	else if (f == 'i' || f == 'd')
		len += ft_putnbr(va_arg(arg, int));
	else if (f == 'u')
		len += ft_putnbr_unsigned(va_arg(arg, int));
	else if (f == 'x' || f == 'X')
		len += ft_puthex(va_arg(arg, unsigned int), f);
	else if (f == 'p')
		len += ft_putadress(va_arg(arg, unsigned long));
	return (len);
}

int	ft_printf(const char *str, ...)
{
	int		len;
	int		i;
	va_list	arg;

	len = 0;
	i = 0;
	va_start(arg, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			len += checker(arg, str[i + 1]);
			i++;
		}
		else
			len += write(1, &str[i], 1);
		i++;
	}
	return (len);
}
