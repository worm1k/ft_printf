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

static void			select_func_x(t_data *data, va_list ap, int reg)
{
	unsigned char	hhd;
	short unsigned	hd;

	if (data->length == HH)
		ft_printf_x(data, hhd = va_arg(ap, int), reg);
	else if (data->length == H)
		ft_printf_x(data, hd = va_arg(ap, int), reg);
	else if (data->length == L)
		ft_printf_x(data, va_arg(ap, unsigned long), reg);
	else if (data->length == Z)
		ft_printf_x(data, va_arg(ap, size_t), reg);
	else if (data->length == LL)
		ft_printf_x(data, va_arg(ap, unsigned long long), reg);
	else if (data->length == J)
		ft_printf_x(data, va_arg(ap, uintmax_t), reg);
	else
		ft_printf_x(data, va_arg(ap, unsigned int), reg);
}

static void			select_func_ou(t_data *data, va_list ap, int base, int reg)
{
	unsigned char	hhd;
	short unsigned	hd;

	if (data->length == HH)
		ft_printf_ou(data, hhd = va_arg(ap, int), base, reg);
	else if (data->length == H)
		ft_printf_ou(data, hd = va_arg(ap, int), base, reg);
	else if (data->length == L)
		ft_printf_ou(data, va_arg(ap, unsigned long), base, reg);
	else if (data->length == Z)
		ft_printf_ou(data, va_arg(ap, size_t), base, reg);
	else if (data->length == LL)
		ft_printf_ou(data, va_arg(ap, unsigned long long), base, reg);
	else if (data->length == J)
		ft_printf_ou(data, va_arg(ap, uintmax_t), base, reg);
	else
		ft_printf_ou(data, va_arg(ap, unsigned int), base, reg);
}

static void			select_func_d(t_data *data, va_list valist)
{
	signed char		hhd;
	short int		hd;

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

static void			select_func_2(t_data *data, va_list valist)
{
	if (data->spec == 'x')
		select_func_x(data, valist, LOW);
	else if (data->spec == 'X')
		select_func_x(data, valist, UPP);
	else if (data->spec == 'c')
	{
		if (data->length == L)
			ft_printf_lc(data, va_arg(valist, wchar_t));
		else
			ft_printf_c(data, va_arg(valist, int));
	}
	else if (data->spec == 'C')
		ft_printf_lc(data, va_arg(valist, wchar_t));
	else if (data->spec == 'n')
		select_func_n(data, valist);
}

void				select_func_1(t_data *data, va_list valist)
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
		select_func_ou(data, valist, 8, LOW);
	else if (data->spec == 'O')
		ft_printf_ou(data, va_arg(valist, unsigned long), 8, LOW);
	else if (data->spec == 'u')
		select_func_ou(data, valist, 10, LOW);
	else if (data->spec == 'U')
		ft_printf_ou(data, va_arg(valist, unsigned long), 10, LOW);
	else
		select_func_2(data, valist);
}
