/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeekim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 17:44:04 by jeekim            #+#    #+#             */
/*   Updated: 2022/02/12 17:48:06 by jeekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "ft_printf.h"

void	bring_print(const char **format, va_list ap, int *cnt)
{
	if (**format)
	{
		if (**format == 'c')
			c_bring_print(format, ap, cnt);
		else if (**format == 's')
			s_bring_print(format, ap, cnt);
		else if (**format == 'p')
			p_bring_print(format, ap, cnt);
		else if (**format == 'd' || **format == 'i')
			di_bring_print(format, ap, cnt);
		else if (**format == 'u')
			u_bring_print(format, ap, cnt);
		else if (**format == 'x')
			x_bring_print(format, ap, cnt);
		else if (**format == 'X')
			cap_x_bring_print(format, ap, cnt);
		else
		{
			write (1, "%", 1);
			(*format)++;
			(*cnt)++;
		}
	}
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		cnt;

	va_start(ap, format);
	cnt = 0;
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			bring_print(&format, ap, &cnt);
		}
		else
		{
			ft_putchar(*((char *)format), &cnt);
			format++;
		}
	}
	va_end(ap);
	return (cnt);
}
