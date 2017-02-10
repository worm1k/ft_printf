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

// s + 
// S +
// p == #lx 
// d +
// D +
// i +
// o #
// O #
// u 
// U 
// x 
// X 
// c 
// C
// char ch = va_arg(ap, int);
void		select_func_1(t_data *data, va_list valist)
{
	if (data->spec == 's')
	{
		if (data->length == L)
			ft_printf_ls(data, va_arg(valist, wchar_t *));
		else
			ft_printf_s(data, va_arg(valist, char *));
	}
	else if (data->spec == 'S')
		ft_printf_ls(data, va_arg(valist, wchar_t *));
	else if (data->spec == 'p')
		ft_printf_p(data, va_arg(valist, void *));
	else if (data->spec == 'd' || data->spec == 'i')
		select_func_d(data, valist);
	else if (data->spec == 'D')
		ft_printf_d(data, va_arg(valist, long int));
	else if (data->spec == 'o')
		select_func_oux(data, valist, 8, LOW);
	else if (data->spec == 'O')
		ft_printf_oux(data, va_arg(valist, unsigned long), 8, LOW);
	else if (data->spec == 'u')
		select_func_oux(data, valist, 10, LOW);
	else if (data->spec == 'U')
		ft_printf_oux(data, va_arg(valist, unsigned long), 10, LOW);
	else
		select_func_2(data, valist);
}

void		select_func_2(t_data *data, va_list valist)
{
	if (data->spec == 'x')
		select_func_oux(data, valist, 16, LOW);
}