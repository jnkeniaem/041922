/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nbr.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeekim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 17:44:06 by jeekim            #+#    #+#             */
/*   Updated: 2022/02/17 16:02:02 by jeekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_16_print(unsigned long nbr, int *cnt)
{
	char			a;
	char			*base;

	base = "0123456789abcdef";
	if (nbr >= 16)
		ft_putnbr_16_print(nbr / 16, cnt);
	a = base[nbr % 16];
	ft_putchar(a, cnt);
}

void	ft_putnbr(int n, int *cnt)
{
	if (n == -2147483648)
	{
		ft_putnbr(n / 10, cnt);
		ft_putchar('8', cnt);
	}
	else if (n < 0)
	{
		ft_putchar('-', cnt);
		ft_putnbr(-n, cnt);
	}
	else
	{
		if (n > 9)
			ft_putnbr(n / 10, cnt);
		ft_putchar(n % 10 + '0', cnt);
	}
}

void	ft_putunbr(unsigned int n, int *cnt)
{
	if (n > 9)
		ft_putunbr(n / 10, cnt);
	ft_putchar(n % 10 + '0', cnt);
}

void	ft_putnbr_16_print_u(unsigned int nbr, int *cnt)
{
	char			a;
	char			*base;

	base = "0123456789abcdef";
	if (nbr >= 16)
		ft_putnbr_16_print_u(nbr / 16, cnt);
	a = base[nbr % 16];
	ft_putchar(a, cnt);
}

void	ft_putnbr_16_cap_print_u(unsigned int nbr, int *cnt)
{
	char			a;
	char			*base;

	base = "0123456789ABCDEF";
	if (nbr >= 16)
		ft_putnbr_16_cap_print_u(nbr / 16, cnt);
	a = base[nbr % 16];
	ft_putchar(a, cnt);
}
