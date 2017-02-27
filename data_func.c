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

void		data_flags(const char **format, t_data *data, int *found)
{
	while (**format && ft_strchr("#0-+ ", **format))
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
	if (**format && ft_strchr("0123456789", **format))
		data->width = 0;
	while (**format && ft_strchr("0123456789", **format))
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
	if (data->length == H && length == H)
		data->length = HH;
	else if (data->length == HH && length == H)
		data->length = H;
	else if (data->length == L && length == L)
		data->length = LL;
	else if (data->length == LL && length == L)
		data->length = L;
	else if (data->length < length)
		data->length = length;
}

void		data_length(const char **format, t_data *data, int *found)
{
	while (**format && ft_strchr("hljz", **format))
	{
		if (ft_strnstr(*format, "l", 1))
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
