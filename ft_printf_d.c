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

static void		print_signed(intmax_t n)
{
	if (-10 < n && n < 10)
		ft_putcount(ABS(n) + '0');
	else
	{
		print_signed(n / 10);
		print_signed(n % 10);
	}
}

static int		ft_getlen(int prec, intmax_t n)
{
	int			len;

	if (prec == 0 && n == 0)
		return (0);
	if (prec < int_length(n, 10))
		return (int_length(n, 10));
	return (prec);
}

static char		get_sign(t_data *data, intmax_t n)
{
	char		res;

	res = ((data->flags)[SPACE]) ? (' ') : (0);
	((data->flags)[PLUS]) ? (res = '+') : (0);
	(n < 0) ? res = '-' : 0;
	return (res);
}

void			ft_printf_d(t_data *data, intmax_t n)
{
	int			len;
	char		sign;

	sign = get_sign(data, n);
	len = ft_getlen(data->prec, n);
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
	if (len > 0)
		print_signed(n);
	if ((data->flags)[MINUS] == '-')
		print_n(' ', data->width - len);
}
