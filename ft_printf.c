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

void	ft_putcount(char c)
{
	write(1, &c, 1);
	g_count += 1;
}

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
		select_func_1(data, valist);


//		exit (0);
}

int		ft_printf(const char *format, ...)
{
	va_list			valist;
	int 			count;
	char			*fmt;

	g_count = 0;
	va_start(valist, format);
	while (*format != '\0')
	{	
		while (*format != '%' && *format != '\0')
		{
			ft_putcount(*format);
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
	return (g_count);
}
/*
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
	int hhd = 100;

	//ft_printf("[%10.7ls]:%s\n", string, ft_itoa(i));
	//   printf("[%10.7ls]:%s\n", string, ft_itoa(i));
	ft_printf("[%+5.4d]\n", hhd);
	   printf("[%+5.4d]\n", hhd);
//	int n = printf("123%d123%2147483644d\n", 1,2);
//	printf("%d\n", n);
    return 0;
}*/

int     main(void)
{
    int n;
    int m;
    int nbr = 126;
    int longnbr = -123456;
/*
	m = ft_printf("[%#0o]\n", nbr);    
	n =    printf("[%#0o]\n", nbr);                                                                                      
	printf("%d\n", m);
	printf("%d\n", n);
	printf("============\n");
	fflush(stdout);
*/
    ft_printf("[%x]\n", -255);
       printf("[%x]\n", -255);

//ALL FLAGS       
    /*
	m = ft_printf("[% x]\n", nbr);//nothing      
	n =    printf("[% x]\n", nbr);                                                                                      
	printf("%d\n", m);
	printf("%d\n", n);
	printf("============\n");
	fflush(stdout);

	m = ft_printf("[%+ 6.2x]\n", nbr);//p < w && w > nbr       
	n =    printf("[%+ 6.2x]\n", nbr);                                                                       
	printf("%d\n", m);
	printf("%d\n", n);
	printf("============\n");
	fflush(stdout);

	m = ft_printf("[%+ 6.12x]\n", nbr);//p > w && w > nbr     
	n =    printf("[%+ 6.12x]\n", nbr);                                                                    
	printf("%d\n", m);
	printf("%d\n", n);
	printf("============\n");
	fflush(stdout);

	m = ft_printf("[%+ 1.7x]\n", nbr); //p > w && w < nbr    
	n =    printf("[%+ 1.7x]\n", nbr);                                                                        
	printf("%d\n", m);
	printf("%d\n", n);
	printf("============\n");
	fflush(stdout);

	m = ft_printf("[%+ 4.2x]\n", longnbr); //p < w && p < nbr      
	n =    printf("[%+ 4.2x]\n", longnbr);                                                                          
	printf("%d\n", m);
	printf("%d\n", n);
	printf("============\n");
	fflush(stdout);
	
	m = ft_printf("[%+ 2.4x]\n", longnbr); //p > w && w < nbr   
	n =    printf("[%+ 2.4x]\n", longnbr);                                                                         
	printf("%d\n", m);
	printf("%d\n", n);
	printf("============\n");
	fflush(stdout);
	
	m = ft_printf("[% 010x]\n", nbr);//no p && w > nbr  
	n =    printf("[% 010x]\n", nbr);                                                                         
	printf("%d\n", m);
	printf("%d\n", n);
	printf("============\n");
	fflush(stdout);
	
	m = ft_printf("[% 03x]\n", nbr);//no p && w == nbr 
	n =    printf("[% 03x]\n", nbr);                                                                         
	printf("%d\n", m);
	printf("%d\n", n);
	printf("============\n");
	fflush(stdout);
	
	m = ft_printf("[%+02x]\n", nbr);//no p && w < nbr       
	n =    printf("[%+02x]\n", nbr);                                                                        
	printf("%d\n", m);
	printf("%d\n", n);
	printf("============\n");
	fflush(stdout);
	
	m = ft_printf("[% .10x]\n", nbr);//no w && p > nbr     
	n =    printf("[% .10x]\n", nbr);                                                                          
	printf("%d\n", m);
	printf("%d\n", n);
	printf("============\n");
	fflush(stdout);
	
	m = ft_printf("[% .3x]\n", nbr);//no w && p == nbr   
	n =    printf("[% .3x]\n", nbr);                                                                          
	printf("%d\n", m);
	printf("%d\n", n);
	printf("============\n");
	fflush(stdout);
	
	m = ft_printf("[%.1x]\n", nbr);//no w && p < nbr    
	n =    printf("[%.1x]\n", nbr);                                                                       
	printf("%d\n", m);
	printf("%d\n", n);
	printf("============\n");
	fflush(stdout);
	
	m = ft_printf("[%+- 10.9x]\n", nbr);//p > nbr && p < w
	n =    printf("[%+- 10.9x]\n", nbr);                                                                     
	printf("%d\n", m);
	printf("%d\n", n);
	printf("============\n");
	fflush(stdout);
	
	m = ft_printf("[% 3.3x]\n", nbr);//p == w == nbr   
	n =    printf("[% 3.3x]\n", nbr);                                                                       
	printf("%d\n", m);
	printf("%d\n", n);
	printf("============\n");
	fflush(stdout);
	
	m = ft_printf("[%x]\n", nbr);    
	n =    printf("[%x]\n", nbr);                                                                
	printf("%d\n", m);
	printf("%d\n", n);
	printf("============\n");
	fflush(stdout);
	
	m = ft_printf("[%-10.5o]\n", nbr);
	n =    printf("[%-10.5o]\n", nbr);                                                                    
	printf("%d\n", m);
	printf("%d\n", n);
	printf("============\n");
	fflush(stdout);
	*/
    return (0);
}












