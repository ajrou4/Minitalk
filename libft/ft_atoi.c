/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majrou <majrou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 03:11:26 by majrou            #+#    #+#             */
/*   Updated: 2022/10/22 18:49:50 by majrou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

int	ft_atoi(const char *str)
{
	char	*s;
	int		sign;
	int		result;
	int		i;

	s = (char *)str;
	sign = 1;
	i = 0;
	result = 0;
	while ((s[i] == ' ') || (s[i] >= 9 && s[i] <= 13))
		i++;
	if (s[i] == '-')
	{
		sign *= -1;
		i++;
	}
	else if (s[i] == '+')
		i++;
	while (s[i] && (s[i] >= '0' && s[i] <= '9'))
	{
		result = (result * 10) + (s[i] - '0');
		i++;
	}
	return (result * sign);
}

// int main()
// {
// 	int ori;
// 	int cre;

// 	ori = atoi("-52");
// 	cre = ft_atoi("-52");
// 	printf("original atoi : %d\n", ori);
// 	printf("my atoi : %d", cre);
// }
