/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_d.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abykov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 19:44:03 by abykov            #+#    #+#             */
/*   Updated: 2017/01/16 19:44:04 by abykov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		print_signed(intmax_t n, int base, int reg)
{
	char	*str_l;
	char	*str_u;

	str_l = "0123456789abcdef";
	str_u = "0123456789ABCDEF";
	if (-base < n && n < base)
		(reg == LOW) ? ft_putchar(str_l[ABS(n)]) : ft_putchar(str_u[ABS(n)]);
	else
	{
		print_signed(n / base, base, reg);
		print_signed(n % base, base, reg);
	}
}

void		ft_printf_d(t_data *data, intmax_t n)
{
	int		len;
	int		minus;

	minus = (n < 0) ? (1) : (0);
	len = (data->prec < int_length(n, 8)) ? (int_length(n, 8)) : (data->prec);
	if (minus + len < data->width && (data->flags)[MINUS] == 0)
		print_n(' ', data->width - len - minus);
	if (minus == 1)
		write(1, "-", 1);
	if (data->prec > int_length(n, 10))
		print_n('0', data->prec - int_length(n, 10));
	print_signed(n, 10, LOW);
}
/*
void		ft_printf_s(t_data *data, char *s)
{
	int		i;
	int		len;

	len = (data->prec < ft_strlen(s)) ? (data->prec) : (ft_strlen(s));
	len = (len == -1) ? (ft_strlen(s)) : len;
	if (len < data->width && (data->flags)[MINUS] == 0)
			print_n(' ', data->width - len);
	i = 0;
	while (i < len)
		ft_putchar(s[i++]);
	if ((data->flags)[MINUS] == '-')
		print_n(' ', data->width - len);
}
*/