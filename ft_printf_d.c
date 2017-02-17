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
// 0.0
#include "ft_printf.h"

static void		print_signed(intmax_t n, int base, int reg, int prec)
{
	char		*str_l;
	char		*str_u;

	if (prec == 0 && n == 0)
		return ;
	str_l = "0123456789abcdef";
	str_u = "0123456789ABCDEF";
	if (-base < n && n < base)
		(reg == LOW) ? ft_putcount(str_l[ABS(n)]) : ft_putcount(str_u[ABS(n)]);
	else
	{
		print_signed(n / base, base, reg, prec);
		print_signed(n % base, base, reg, prec);
	}
}

void			ft_printf_d(t_data *data, intmax_t n)
{
	int			len;
	char		sign;

	sign = ((data->flags)[SPACE]) ? ' ' : 0;
	((data->flags)[PLUS]) ? sign =  '+' : 0;
	(n < 0) ? sign = '-' : 0;
	len = (data->prec < int_length(n, 10)) ? (int_length(n, 10)) : (data->prec);
	len += (sign) ? (1) : (0);
	if (len < data->width && (data->flags)[MINUS] == 0)
	{
		if ((data->flags)[ZERO] == '0' && data->prec == -1)
		{
			sign ? ft_putcount(sign) : 0;
			print_n('0', data->width - len);
			sign = 0;
		}
		else
			print_n(' ', data->width - len);
	}
	sign ? ft_putcount(sign) : 0;
	if (data->prec > int_length(n, 10))
		print_n('0', data->prec - int_length(n, 10));
	print_signed(n, 10, LOW, data->prec);
	if ((data->flags)[MINUS] == '-')
		print_n(' ', data->width - len);
}
