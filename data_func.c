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
	int	i;
	ft_putchar('%');
	i = 0;
	while (i < 5)
		ft_putchar((data->flags)[i++]);
}

void		data_flags(const char **format, t_data *data)
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
	}
}