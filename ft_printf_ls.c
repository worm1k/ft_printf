/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_oux.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abykov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 19:44:03 by abykov            #+#    #+#             */
/*   Updated: 2017/01/16 19:44:04 by abykov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	count_bytes(int	wc)
{
	if (0 <= wc && wc <= 127)
		return (1);
	else if (128 <= wc && wc <= 2047)
		return (2);
	else if (2048 <= wc && wc <= 65535)
		return (3);
	else if (65536 <= wc && wc <= 2097151)
		return (4);
	else
		return (-1);
}

static int	ft_wslen(wchar_t *ws, int prec, int *chars)
{
	int		i;
	int		res;

	res = 0;
	i = 0;
	*chars = 0;
	while (ws[i] != 0)
	{
//		printf("[%d]:[%d]\n", i, ws[i]);
		res += count_bytes(ws[i]);
		*chars += 1;
		if (prec != -1 && res > prec)
		{
			res -= count_bytes(ws[i]);
			*chars -= 1;
			return (res);
		}
		i++;
	}
	return (res);
}

static void	ft_putletter(wchar_t ws, int bytes)
{
	char	c;

	if (bytes == 1)
		ft_putcount(ws);
	else if (bytes == 2)
	{
		ft_putcount(0xC0 | (ws >> 6));
		ft_putcount(0x80 | (ws & 0x3F));
	}
	else if (bytes == 3)
	{
		ft_putcount(0xE0 | (ws >> 12));
		ft_putcount(0x80 | ((ws >> 6) & 0x3F));
		ft_putcount(0x80 | (ws & 0x3F));
	}
	else if (bytes == 4)
	{
		ft_putcount(0xF0 | (ws >> 18));
		ft_putcount(0x80 | ((ws >> 12) & 0x3F));
		ft_putcount(0x80 | ((ws >> 6) & 0x3F));
		ft_putcount(0x80 | (ws & 0x3F));
	}
}

void		ft_printf_ls(t_data *data, wchar_t *ws)
{
	int		i;
	int		len;
	int		chars;

	len = ft_wslen(ws, data->prec, &chars);
	if ((len < data->width) && ((data->flags)[MINUS] == 0))
	{
		if ((data->flags)[ZERO] == '0')
			print_n('0', data->width - len);
		else
			print_n(' ', data->width - len);
	}
	i = 0;
	while (i < chars)
	{
		ft_putletter(ws[i], count_bytes(ws[i]));
		i++;
	}
	if ((data->flags)[MINUS] == '-')
		print_n(' ', data->width - len);
}