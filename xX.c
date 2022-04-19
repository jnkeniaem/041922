/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xX.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeekim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 17:44:19 by jeekim            #+#    #+#             */
/*   Updated: 2022/02/11 17:45:53 by jeekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	x_bring_print(const char **format, va_list ap, int *cnt)
{
	ft_putnbr_16_print_u(va_arg(ap, unsigned int), cnt);
	(*format)++;
	return (*cnt);
}

int	cap_x_bring_print(const char **format, va_list ap, int *cnt)
{
	ft_putnbr_16_cap_print_u(va_arg(ap, unsigned int), cnt);
	(*format)++;
	return (*cnt);
}
