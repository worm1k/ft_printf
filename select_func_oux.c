/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select_func_oux.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abykov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 19:44:03 by abykov            #+#    #+#             */
/*   Updated: 2017/01/16 19:44:04 by abykov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			select_func_oux(t_data *data, va_list valist, int base, int reg)
{
	unsigned char	hhd;
	short unsigned	hd;

	if (data->length == HH)
		ft_printf_oux(data, hhd = va_arg(valist, int), base, reg);
	else if (data->length == H)
		ft_printf_oux(data, hd = va_arg(valist, int), base, reg);
	else if (data->length == L)
		ft_printf_oux(data, va_arg(valist, unsigned long), base, reg);
	else if (data->length == Z)
		ft_printf_oux(data, va_arg(valist, size_t), base, reg);
	else if (data->length == LL)
		ft_printf_oux(data, va_arg(valist, unsigned long long), base, reg);
	else if (data->length == J)
		ft_printf_oux(data, va_arg(valist, uintmax_t), base, reg);
	else
		ft_printf_oux(data, va_arg(valist, unsigned int), base, reg);
}
