/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_s.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abykov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 19:44:03 by abykov            #+#    #+#             */
/*   Updated: 2017/01/16 19:44:04 by abykov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		print_filler(t_data *data, int len)
{
	if ((data->flags)[ZERO] == '0' && data->prec == -1)
		print_n('0', data->width - len);
	else
		print_n(' ', data->width - len);
}

static void		print_unsigned(uintmax_t n, int base, int reg, int prec)
{
	char		*str_l;
	char		*str_u;

	str_l = "0123456789abcdef";
	str_u = "0123456789ABCDEF";
	if (n < base)
		(reg == LOW) ? ft_putcount(str_l[ABS(n)]) : ft_putcount(str_u[ABS(n)]);
	else
	{
		print_unsigned(n / base, base, reg, prec);
		print_unsigned(n % base, base, reg, prec);
	}
}

static int		ft_getlen(t_data *data, long n, int base)
{
	if (data->prec < uint_length(n, base))
		return (uint_length(n, base) + 2);
	else
		return (data->prec + 2);
}

void			ft_printf_p(t_data *data, void *p)
{
	int			len;
	long		n;

	n = (long)p;
	len = ft_getlen(data, n, 16);
	if (len < data->width && (data->flags)[MINUS] == 0)
		print_filler(data, len);
	ft_putcount('0');
	ft_putcount('x');
	if (data->prec > uint_length(n, 16))
		print_n('0', data->prec - uint_length(n, 16));
	if (len > 0)
		print_unsigned(n, 16, LOW, data->prec);
	if ((data->flags)[MINUS] == '-')
		print_n(' ', data->width - len);
}
