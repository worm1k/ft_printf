/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_ou.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abykov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 19:44:03 by abykov            #+#    #+#             */
/*   Updated: 2017/01/16 19:44:04 by abykov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		print_filler(t_data *data, int len, int base, int flag)
{
	if ((data->flags)[ZERO] == '0' && data->prec == -1)
		print_n('0', data->width - len);
	else
		print_n(' ', data->width - len);
}

static void		print_prefix(int reg)
{
	ft_putcount('0');
	if (reg == LOW)
		ft_putcount('x');
	else
		ft_putcount('X');
}

static void		print_unsigned(uintmax_t n, int base)
{
	if (n < base)
		ft_putcount(ABS(n) + '0');
	else
	{
		print_unsigned(n / base, base);
		print_unsigned(n % base, base);
	}
}

static int		ft_getlen(t_data *data, uintmax_t n, int base)
{
	int			len;

	if (data->prec == 0 && n == 0)
	{
		if (base == 8 && (data->flags)[HASH] == '#')
			return (1);
		else
			return (0);
	}
	if (base == 8 && (data->flags)[HASH] == '#')
	{
		if (n == 0)
			return ((data->prec == -1) ? (1) : (data->prec));
		if (data->prec <= uint_length(n, base) && n != 0)
			data->prec = uint_length(n, base) + 1;
	}
	if (data->prec < uint_length(n, base))
		len = uint_length(n, base);
	else
		len = data->prec;
	return (len);
}

void			ft_printf_ou(t_data *data, uintmax_t n, int base, int reg)
{
	int			len;

	len = ft_getlen(data, n, base);
	if (len < data->width && (data->flags)[MINUS] == 0)
		print_filler(data, len, base, 0);
	if (data->prec > uint_length(n, base))
		print_n('0', data->prec - uint_length(n, base));
	if (len > 0)
		print_unsigned(n, base);
	if ((data->flags)[MINUS] == '-')
		print_n(' ', data->width - len);
}
