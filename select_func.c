/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abykov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 19:44:03 by abykov            #+#    #+#             */
/*   Updated: 2017/01/16 19:44:04 by abykov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// s + 
// S +
// p == #lx 
// d +
// D +
// i +
// o 
// O 
// u 
// U 
// x 
// X 
// c 
// C
void		select_func(t_data *data, va_list valist)
{
	if (data->spec == 's')
	{
		if (data->length == L)
			//return ;
			ft_printf_ls(data, va_arg(valist, wchar_t *));
		else
			ft_printf_s(data, va_arg(valist, char *));
	}
	else if (data->spec == 'S')
		ft_printf_ls(data, va_arg(valist, wchar_t *));
	else if (data->spec == 'p')
		ft_printf_p(data, va_arg(valist, void *));
	else if (data->spec == 'd' || data->spec == 'i')
	{
		if (data->length == HH)
			ft_printf_d(data, va_arg(valist, signed char));
		else if (data->length == H)
			ft_printf_d(data, va_arg(valist, short int));
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
	else if (data->spec == 'D')
		ft_printf_d(data, va_arg(valist, long int));
	else if (data->spec == 'o')
	{
		if (data->length == HH)
			ft_printf_d(data, va_arg(valist, signed char));
		else if (data->length == H)
			ft_printf_d(data, va_arg(valist, short int));
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