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

void	print_unsigned(int n)
{
	if (-10 < n && n < 10)
		ft_putchar(ABS(n) + '0');
	else
	{
		print_unsigned(n / 10);
		print_unsigned(n % 10);
	}
}

void		ft_printf_d(t_data *data, int n)
{
	int		i;
	int		len;
	int		minus;

	minus = (n < 0) ? (1) : (0);
	len = (data->prec < int_length(n, 10)) ? (int_length(n, 10)) : (data->prec);
	if (minus + len < data->width && (data->flags)[MINUS] == 0)
		print_n(' ', data->width - len - minus);
	i = 0;
	if (minus == 1)
		write(1, "-", 1);
	if (data->prec > int_length(n, 10))
		print_n('0', data->prec - int_length(n, 10));
	print_unsigned(n);
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