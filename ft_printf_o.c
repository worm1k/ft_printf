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

static void		print_unsigned(uintmax_t n, int base, int reg)
{
	char	*str_l;
	char	*str_u;

	str_l = "0123456789abcdef";
	str_u = "0123456789ABCDEF";
	if (n < base)
		(reg == LOW) ? ft_putcount(str_l[ABS(n)]) : ft_putcount(str_u[ABS(n)]);
	else
	{
		print_unsigned(n / base, base, reg);
		print_unsigned(n % base, base, reg);
	}
}

void	ft_printf_o(t_data *data, uintmax_t n)
{
	int		len;

	len = (data->prec < int_length(n, 8)) ? (int_length(n, 8)) : (data->prec);
	if (len < data->width && (data->flags)[MINUS] == 0)
	{
		if ((data->flags)[ZERO] == '0' && data->prec == -1)
			print_n('0', data->width - len);
		else
			print_n(' ', data->width - len);
	}
	if (data->prec > int_length(n, 8))
		print_n('0', data->prec - int_length(n, 8));
	print_unsigned(n, 8, LOW);
	if ((data->flags)[MINUS] == '-')
		print_n(' ', data->width - len);

}
/*
void		ft_printf_d(t_data *data, intmax_t n)
{
	int		len;
	int		minus;

	minus = (n < 0) ? (1) : (0);
	len = (data->prec < int_length(n, 8)) ? (int_length(n, 8)) : (data->prec);
	if (minus + len < data->width && (data->flags)[MINUS] == 0)
	{
		if ((data->flags)[ZERO] == '0' && data->prec == -1)
		{
			if (minus == 1)
				ft_putcount('-');
			print_n('0', data->width - len - minus);
			minus = 0;
		}
		else
			print_n(' ', data->width - len - minus);
	}
	if (minus == 1)
		ft_putcount('-');
	if (data->prec > int_length(n, 10))
		print_n('0', data->prec - int_length(n, 10));
	print_signed(n, 10, LOW);
}
*/