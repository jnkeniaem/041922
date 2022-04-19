/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cspdiu.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeekim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 17:40:03 by jeekim            #+#    #+#             */
/*   Updated: 2022/02/17 16:56:46 by jeekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	c_bring_print(const char **format, va_list ap, int *cnt)
{
	ft_putchar((char)va_arg(ap, int), cnt);
	(*format)++;
	return (*cnt);
}

int	s_bring_print(const char **format, va_list ap, int *cnt)
{
	char	*str;

	str = va_arg(ap, char *);
	if (str == NULL)
		ft_putstr("(null)", cnt);
	else
		ft_putstr(str, cnt);
	(*format)++;
	return (*cnt);
}

int	p_bring_print(const char **format, va_list ap, int *cnt)
{
	ft_putstr("0x", cnt);
	ft_putnbr_16_print((unsigned long)va_arg(ap, void *), cnt);
	(*format)++;
	return (*cnt);
}

int	di_bring_print(const char **format, va_list ap, int *cnt)
{
	ft_putnbr(va_arg(ap, int), cnt);
	(*format)++;
	return (*cnt);
}

int	u_bring_print(const char **format, va_list ap, int *cnt)
{
	ft_putunbr(va_arg(ap, unsigned int), cnt);
	(*format)++;
	return (*cnt);
}
