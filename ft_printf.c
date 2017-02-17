/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abykov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 19:44:03 by abykov            #+#    #+#             */
/*   Updated: 2017/01/16 19:44:04 by abykov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <wchar.h>

void			ft_putcount(char c)
{
	write(1, &c, 1);
	g_count += 1;
}

void			data_init(t_data **data)
{
	*data = (t_data *)malloc(sizeof(t_data));
	(*data)->flags = ft_strnew(4);
	(*data)->width = -1;
	(*data)->prec = -1;
	(*data)->length = NONE;
	(*data)->spec = 0;
}

void			print_pattern(const char **format, int *count, va_list valist)
{
		t_data	*data;
		int		found;

		found = 1;
		data_init(&data);
		while (found)
		{
			found = 0;
			data_flags(format, data, &found);
			data_width(format, data, &found);
			data_prec(format, data, &found);
			data_length(format, data, &found);
		}
		if (ft_strchr("sSpdDioOuUxXcC", **format))
		{
			data->spec = **format;
			(*format)++;
		}
		else
		{
			ft_printf_c(data, *((*format)++));
			return ;
		}
		select_func_1(data, valist);
}

int				ft_printf(const char *format, ...)
{
	va_list		valist;
	int 		count;
	char		*fmt;

	g_count = 0;
	va_start(valist, format);
	while (*format != '\0')
	{
		while (*format != '%' && *format != '\0')
		{
			ft_putcount(*format);
			format++;
		}
		if (*format == '%' && *(format + 1) == '%')
		{
			ft_putcount('%');
			format += 2;
		}
		if (*format == '%')
		{
			format++;
			print_pattern(&format, &count, valist);
		}
	}
	va_end(valist);
	return (g_count);
}
