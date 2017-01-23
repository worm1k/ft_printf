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

void				data_init(t_data **data)
{
	*data = (t_data *)malloc(sizeof(t_data));
	(*data)->flags = ft_strnew(4);
	(*data)->width = 0;
	(*data)->prec = 0;
	(*data)->length = ft_strnew(2);
	(*data)->spec = 0;
}

void	print_pattern(const char **format, int *count, va_list valist)
{
		t_data		*data;
		int			i;
		int			found = 1;

		i = 0;
		data_init(&data);
		while (found && i++ < 10)
		{
			found = 0;
			data_flags(format, data, &found);
			data_width(format, data, &found);
			data_prec(format, data, &found);
			data_length(format, data, &found);
			//data->spec = data_spec(format);
			//proc_data(data, count);
			//else
			//	break ;
		}
		printf("I:[%d]\n", i);
		ft_putstr("DATA:");
		print_data(data);
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
		{
			format++;
			print_pattern(&format, &count, valist);
		}

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

void	sizes_print()
{
	long long int lld;
	long int ld;
	int d;
	size_t zu;
	short h;
	signed short int hh;
	unsigned long int ui;
	unsigned long u;
	intmax_t jd;

	printf("LLD:[%3lu]\n", sizeof(lld));
	printf("LD :[%3lu]\n", sizeof(ld));
	printf("D  :[%3lu]\n", sizeof(d));
	printf("H  :[%3lu]\n", sizeof(short int));
	printf("HH :[%3lu]\n", sizeof(signed char));
	printf("ZU :[%3lu]\n", sizeof(zu));
	printf("JD :[%3lu]\n", sizeof(jd));
	printf("ULI:[%3lu]\n", sizeof(ui));
	printf("UL :[%3lu]\n", sizeof(u));
}

int main(int argc, char **argv)
{
	//ft_printf("[% 45 .12.13.11  ##   0 21. ## 42d$dTRASH]", 142);

	//sizes_print();
	t_len a;
	a = H;
	printf("[%3d]HUI\n", a);

	return 0;
}











