/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_c.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abykov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 19:44:03 by abykov            #+#    #+#             */
/*   Updated: 2017/01/16 19:44:04 by abykov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_printf_lc(t_data *data, int c)
{
	ft_printf_c(data, c);
}

void		ft_printf_c(t_data *data, int c)
{
	int		len;

	len = (c == 0) ? (0) : (1);
	if (len < data->width && (data->flags)[MINUS] == 0)
	{
		if ((data->flags)[ZERO] == '0')
			print_n('0', data->width - len);
		else
			print_n(' ', data->width - len);
	}
	(c != 0) ? (ft_putcount(c)) : (0);
	if ((data->flags)[MINUS] == '-')
		print_n(' ', data->width - len);
}
