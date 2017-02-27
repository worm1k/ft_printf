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

static void		print_prefix(void)
{
	ft_putcount('0');
	ft_putcount('x');
}

static void		print_unsigned(uintmax_t n)
{
	char		*str_l;

	str_l = "0123456789abcdef";
	if (n < 16)
		ft_putcount(str_l[n]);
	else
	{
		print_unsigned(n / 16);
		print_unsigned(n % 16);
	}
}

static int		ft_getlen(int prec, int intlen)
{
	if (prec < intlen)
		return (intlen + 2);
	else
		return (prec + 2);
}

void			ft_printf_p(t_data *data, void *p)
{
	int			len;
	long		n;

	n = (long)p;
	len = ft_getlen(data->prec, uint_length(n, 16));
	if (len < data->width && (data->flags)[MINUS] == 0
		&& ((data->flags)[ZERO] == 0 || data->prec != -1))
		print_n(' ', data->width - len);
	print_prefix();
	if (data->prec > uint_length(n, 16) && !(data->flags)[MINUS])
		print_n('0', data->prec - uint_length(n, 16));
	else if ((data->flags)[ZERO] && len < data->width && !(data->flags)[MINUS])
		print_n('0', data->width - len);
	if (!(n == 0 && data->prec == 0))
		print_unsigned(n);
	if ((data->flags)[MINUS] == '-')
		print_n(' ', data->width - len);
}
