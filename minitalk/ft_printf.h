/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeekim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 12:00:20 by jeekim            #+#    #+#             */
/*   Updated: 2022/02/12 17:38:27 by jeekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

void	ft_putchar(char c, int *cnt);
void	ft_putstr(char *s, int *cnt);
int		c_bring_print(const char **format, va_list ap, int *cnt);
int		s_bring_print(const char **format, va_list ap, int *cnt);
int		p_bring_print(const char **format, va_list ap, int *cnt);
int		di_bring_print(const char **format, va_list ap, int *cnt);
int		u_bring_print(const char **format, va_list ap, int *cnt);
int		x_bring_print(const char **format, va_list ap, int *cnt);
int		cap_x_bring_print(const char **format, va_list ap, int *cnt);
void	ft_putnbr_16_print(unsigned long nbr, int *cnt);
void	ft_putnbr(int n, int *cnt);
void	ft_putunbr(unsigned int n, int *cnt);
void	ft_putnbr_16_print_u(unsigned int nbr, int *cnt);
void	ft_putnbr_16_cap_print_u(unsigned int nbr, int *cnt);
void	bring_print(const char **format, va_list ap, int *cnt);
int		ft_printf(const char *format, ...);

#endif
