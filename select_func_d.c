/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select_func_d.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abykov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 19:44:03 by abykov            #+#    #+#             */
/*   Updated: 2017/01/16 19:44:04 by abykov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			select_func_d(t_data *data, va_list valist)
{
	signed char	hhd;
	short int	hd;

	if (data->spec == 'd' || data->spec == 'i')
	{
		if (data->length == HH)
			ft_printf_d(data, hhd = va_arg(valist, int));
		else if (data->length == H)
			ft_printf_d(data, hd = va_arg(valist, int));
		else if (data->length == L)
			ft_printf_d(data, va_arg(valist, long int));
		else if (data->length == Z)
			ft_printf_d(data, va_arg(valist, size_t));
		else if (data->length == LL)
			ft_printf_d(data, va_arg(valist, long long int));
		else if (data->length == J)
			ft_printf_d(data, va_arg(valist, intmax_t));
		else
			ft_printf_d(data, va_arg(valist, int));
	}
}
