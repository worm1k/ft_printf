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

// s+ S p d D i o O u U x X c C
void		select_func(t_data *data, va_list valist)
{
	if (ft_strchr("s", data->spec))
	{
		if (data->length == L)
			//return ;
			ft_printf_ls(data, va_arg(valist, wchar_t *));
		else
			ft_printf_s(data, va_arg(valist, char *));
	}
}