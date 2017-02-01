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

int			ft_wcslen(wchar_t *ws)
{
	int 	i;
	int		res;

	i = 0;
	res = 0;
	while (ws[i])
	{
		res += ft_strlen((char *)ws);
		i++;
	}
	return (res);
}

void		print_n(char c, int len)
{
	int		i;

	i = 0;
	while (i < len)
	{
		write(1, &c, 1);
		i++;
	}
}

void		ft_printf_s(t_data *data, char *s)
{
	int		i;
	int		len;

	len = (data->prec == -1) ? (ft_strlen(s)) : (data->prec);
	if (len < data->width && (data->flags)[MINUS] == 0)
	{
		if ((data->flags)[ZERO] == '0')
			print_n('0', data->width - len);
		else
			print_n(' ', data->width - len);
	}
	i = 0;
	while (i < len)
		ft_putchar(s[i++]);
	if ((data->flags)[MINUS] == '-')
		print_n(' ', data->width - len);
}

void		ft_printf_ls(t_data *data, wchar_t *ws)
{
	int		i;
	int		len;
	int j = 0;
	char	*s;

	s = (char *)ws;
	//print_spaces_left(data, ft_wcslen(ws))
	i = 0;
	len = (data->prec == -1) ? (ft_wcslen(ws)) : (data->prec);
	if (len < data->width && (data->flags)[MINUS] == 0)
	{
		while (j++ < data->width - len)
			if ((data->flags)[ZERO] == '0')
				write(1, "0", 1);
			else
				write(1, " ", 1);
	}
	while (s[i])
	{
		write(1, ws + i, ft_strlen((char *) ws));
		i++;
	}
}