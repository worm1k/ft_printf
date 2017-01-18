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

static int	ft_vacount(const char *format)
{
	int		i;
	int		res;

	i = 0;
	res = 0;
	while (format[i + 1])
	{
		if (format[i] == '%' && format[i + 1] != '%')
			res++;
		i++;
	}
	return (res);
}

int		ft_printf(const char *format, ...)
{
	va_list			valist;
	int 			count;
	int				i;

	count = ft_vacount(format);
	i = format;
	va_start(valist, format);
	while (format[i] != '\0')
	{
		while (format[i] != '%')
		{
			ft_putchar(format + i);
			i++;
		}
		i++;
		// crete node
		while (ft_strchar('#0-+ ', format[i]))
		{
			// flags
			i++;
		}
		while (ft_strchar('0123456789', format[i]))
		{
			// width
			i++;
		}
		if (format[i] == '.')
		{
			i++;
			while (ft_strchar('0123456789', format[i]))
			{
				// precision
				i++;
			}
		}
		if (ft_strchar('hljz', format[i]))
		{
			// length
			i++;
		}
		if (ft_strchar('sSpdDioOuUxXcC', format[i]))
		{
			// specificator
			i++;
		}
	}
	va_end(valist);
	return (0);
}

int main(int argc, char **argv)
{
	printf("[%s]", argv[1]);
	//ft_printf("huinya", "hui", 4422, "zhopa", (t_int)10);

	return 0;
}