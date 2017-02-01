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
		(reg == LOW) ? ft_putchar(str_l[ABS(n)]) : ft_putchar(str_u[ABS(n)]);
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
		print_n(' ', data->width - len);
	if (data->prec > int_length(n, 8))
		print_n('0', data->prec - int_length(n, 8));
	print_unsigned(n, 8, LOW);

}