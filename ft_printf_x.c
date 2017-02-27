/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_x.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abykov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 19:44:03 by abykov            #+#    #+#             */
/*   Updated: 2017/01/16 19:44:04 by abykov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		print_prefix(int reg)
{
	ft_putcount('0');
	if (reg == LOW)
		ft_putcount('x');
	else
		ft_putcount('X');
}

static void		print_unsigned(uintmax_t n, int reg)
{
	char		*str_l;
	char		*str_u;

	str_l = "0123456789abcdef";
	str_u = "0123456789ABCDEF";
	if (n < 16)
		(reg == LOW) ? ft_putcount(str_l[ABS(n)]) : ft_putcount(str_u[ABS(n)]);
	else
	{
		print_unsigned(n / 16, reg);
		print_unsigned(n % 16, reg);
	}
}

static int		ft_getlen(t_data *data, uintmax_t n)
{
	int			len;

	if (data->prec == 0 && n == 0)
		return (0);
	if (data->prec < uint_length(n, 16))
		len = uint_length(n, 16);
	else
		len = data->prec;
	if ((data->flags)[HASH] == '#')
		return ((n == 0) ? (len) : (len + 2));
	return (len);
}

void			ft_printf_x(t_data *data, uintmax_t n, int reg)
{
	int			len;

	len = ft_getlen(data, n);
	if (len < data->width && (data->flags)[MINUS] == 0
		&& ((data->flags)[ZERO] == 0 || data->prec != -1))
		print_n(' ', data->width - len);
	if ((data->flags)[HASH] == '#' && n != 0)
		print_prefix(reg);
	if (data->prec > uint_length(n, 16) && !(data->flags)[MINUS])
		print_n('0', data->prec - uint_length(n, 16));
	else if ((data->flags)[ZERO] && len < data->width && !(data->flags)[MINUS])
		print_n('0', data->width - len);
	if (len > 0)
		print_unsigned(n, reg);
	if ((data->flags)[MINUS] == '-')
		print_n(' ', data->width - len);
}
