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
void				data_init(t_data **data)
{
	*data = (t_data *)malloc(sizeof(t_data));
	(*data)->flags = ft_strnew(4);
	(*data)->width = -1;
	(*data)->prec = -1;
	(*data)->length = NONE;
	(*data)->spec = 0;
}

void	print_pattern(const char **format, int *count, va_list valist)
{
		t_data		*data;
		int			i;
		int			found = 1;

		i = 0;
		data_init(&data);
		while (found && i++ < 100)
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
			return ;
		//ft_putstr("DATA:");print_data(data);ft_putstr("\n");
		select_func(data, valist);


//		exit (0);
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
			ft_putchar(*format);
			format++;
			//count++;
		}
		if (*format == '%')
		{
			format++;
			print_pattern(&format, &count, valist);
		}
	}

	va_end(valist);
	return (count);
}

void	sizes_print()
{
	printf("LLD:[%3lu]\n", sizeof(long long));
	printf("LD :[%3lu]\n", sizeof(long));
	printf("D  :[%3lu]\n", sizeof(int));
	printf("H  :[%3lu]\n", sizeof(short int));
	printf("HH :[%3lu]\n", sizeof(char));
	printf("ZU :[%3lu]\n", sizeof(size_t));
	printf("JD :[%3lu]\n", sizeof(intmax_t));
}

int main(int argc, char **argv)
{
	size_t i = 1544;
	//ft_printf("%10.4s", "0123456789");
	//printf("%0 10.4s$\n", "Huinia\n");
	//printf("%hhs\n", "govno");
	//printf("[%d]\n", ZERO);
	//sizes_print();

	wchar_t string[100];
	size_t *p = malloc(8);

	//printf ("Enter a string: ");
	//scanf("%ls",string);
	i = wcslen(string);
	//printf("%010.4ls", string);
	//ft_printf("[%10.7ls]:%s\n", string, ft_itoa(i));
	//   printf("[%10.7ls]:%s\n", string, ft_itoa(i));
	ft_printf("[%12.11d]\n", -500);
	   printf("[%12.11d]\n", -500);

    return 0;
}











