/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeekim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 17:50:25 by jeekim            #+#    #+#             */
/*   Updated: 2021/12/13 11:28:16 by jeekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	isso(char c, char *str)
{
	while (*str)
	{
		if (c == *str)
			return (1);
		str++;
	}
	return (0);
}

int	ft_atoi(const char *str)
{
	long	minus;
	long	result;

	minus = 1;
	result = 0;
	while (isso(*str, "\t\n\v\f\r "))
		str++;
	if (*str == '-')
		minus *= -1;
	if (isso(*str, "+-"))
		str++;
	while (isso(*str, "0123456789"))
	{
		result *= 10;
		result += *str - '0';
		if (result > 2147483647 && minus == 1)
			return (-1);
		if (result > 2147483648 && minus == -1)
			return (0);
		str++;
	}
	return (result * minus);
}
