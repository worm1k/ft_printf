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

void				data_init(t_data *data)
{
	data = (t_data *)malloc(sizeof(t_data));
	data->flags = ft_strnew(4);
	data->width = 0;
	data->prec = 0;
	data->length = ft_strnew(2);
	data->spec = 0;
}

void	print_pattern(const char **format, int *count, va_list valist)
{
		t_data		*data;
		int i = 0;
		data_init(data);
		while (!ft_strchr("sSpdDioOuUxXcC", **format) && i++ < 10)
		{
			if (ft_strchr("#0-+ ", **format))
				data_flags(format, data);
			//data->width = data_width(format);
			//data->prec = data_prec(format);
			//data->length = data_length(format);
			//data->spec = data_spec(format);
			//proc_data(data, count);
			//else
			//	break ;
		}
		printf("DATA:[\n");
		print_data(data);
		printf("]\n");
		exit (0);
}

int		ft_printf(const char *format, ...)
{
	va_list			valist;
	int 			count;
	char			*fmt;

	va_start(valist, format);
	while (*format != '\0')
	{	
		while (*format != '%' && *format != '\0')
		{
			//ft_putchar(*format);
			format++;
			//count++;
		}
		if (*format == '%')
			print_pattern(&format, &count, valist);
		format++;
		/*
		// create node
		while (ft_strchar('#0-+ ', format[i]))
		{
			// flags
		}
		while (ft_strchar('0123456789', format[i]))
		{
			// width
		}
		if (format[i] == '.')
		{
			i++;
			while (ft_strchar('0123456789', format[i]))
			{
				// precision
			}
		}
		if (ft_strchar('hljz', format[i]))
		{
			// length
		}
		if (ft_strchar("sSpdDioOuUxXcC", format[i]))
		{
			// specificator
		}*/
	}

	va_end(valist);
	return (count);
}

int main(int argc, char **argv)
{
	ft_printf("[%    ##   0 d$dTRASH]", 142);
	//ft_printf("1:[%d]\n2:[%d]\n", 42, 52);
	//ft_printf("huinya", "hui", 4422, "zhopa", (t_int)10);
	//printf("%+.5d\n", 142);

	return 0;
}











