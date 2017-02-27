/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select_func.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abykov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 19:44:03 by abykov            #+#    #+#             */
/*   Updated: 2017/01/16 19:44:04 by abykov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void				select_func_n(t_data *data, va_list valist)
{
	signed char		*hhd;
	short int		*hd;

	if (data->spec == 'n')
	{
		if (data->length == HH)
			*(va_arg(valist, int *)) = g_count;
		else if (data->length == H)
			*(va_arg(valist, int *)) = g_count;
		else if (data->length == L)
			*(va_arg(valist, long int *)) = g_count;
		else if (data->length == Z)
			*(va_arg(valist, size_t *)) = g_count;
		else if (data->length == LL)
			*(va_arg(valist, long long int *)) = g_count;
		else if (data->length == J)
			*(va_arg(valist, intmax_t *)) = g_count;
		else
			*(va_arg(valist, int *)) = g_count;
	}
}
