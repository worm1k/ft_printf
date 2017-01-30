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

void		print_data(t_data *data)
{
	int	i = 0;
	ft_putchar('%');
	
	ft_putchar('[');
	while (i < 5)
		ft_putchar((data->flags)[i++]);
	ft_putchar(']');

	ft_putchar('[');
	ft_putnbr(data->width);
	ft_putchar(']');

	ft_putchar('[');
	ft_putnbr(data->prec);
	ft_putchar(']');

	ft_putchar('[');
	if (data->length == HH)
		ft_putstr("hh");
	else if (data->length == H)
		ft_putstr("h");
	else if (data->length == L)
		ft_putstr("l");
	else if (data->length == Z)
		ft_putstr("z");
	else if (data->length == LL)
		ft_putstr("ll");
	else if (data->length == J)
		ft_putstr("j");
	else
		ft_putstr("0");
	ft_putchar(']');

	ft_putchar('[');
	ft_putchar(']');
}

void		data_flags(const char **format, t_data *data, int *found)
{
	while (ft_strchr("#0-+ ", **format))
	{
		if (**format == '#')
			(data->flags)[HASH] = '#';
		else if (**format == '0')
			(data->flags)[ZERO] = '0';
		else if (**format == '-')
			(data->flags)[MINUS] = '-';
		else if (**format == '+')
			(data->flags)[PLUS] = '+';
		else if (**format == ' ')
			(data->flags)[SPACE] = ' ';
		(*format)++;
		*found = 1;
	}
}

void		data_width(const char **format, t_data *data, int *found)
{
	if (ft_strchr("0123456789", **format))
		data->width = 0;
	while (ft_strchr("0123456789", **format))
	{
		data->width = data->width * 10 + **format - '0';
		(*format)++;
		*found = 1;
	}
}

void		data_prec(const char **format, t_data *data, int *found)
{
	if (**format == '.')
	{
		data->prec = 0;
		(*format)++;
		while (ft_strchr("0123456789", **format))
		{
			data->prec = data->prec * 10 + **format - '0';
			(*format)++;
		}
		*found = 1;
	}
}

void		len_try(t_data *data, t_len length)
{
	if (data->length < length)
		data->length = length;
}

void		data_length(const char **format, t_data *data, int *found)
{
	while (ft_strchr("hljz", **format))
	{
		if(ft_strnstr(*format, "hh", 2))
		{
			len_try(data, HH);
			(*format) += 1;
		}
		else if (ft_strnstr(*format, "ll", 2))
		{
			len_try(data, LL);
			(*format) += 1;
		}
		else if (ft_strnstr(*format, "l", 1))
			len_try(data, L);
		else if (ft_strnstr(*format, "h", 1))
			len_try(data, H);
		else if (ft_strnstr(*format, "j", 1))
			len_try(data, J);
		else if (ft_strnstr(*format, "z", 1))
			len_try(data, Z);
		(*format) += 1;
		(*found) += 2;
	}
}












