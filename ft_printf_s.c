/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_s.c                                      :+:      :+:    :+:   */
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
		ft_putcount(c);
		i++;
	}
}

void		ft_printf_s(t_data *data, char *s)
{
	int		i;
	int		len;

	len = (data->prec < ft_strlen(s)) ? (data->prec) : (ft_strlen(s));
	len = (len == -1) ? (ft_strlen(s)) : len;
	if (len < data->width && (data->flags)[MINUS] == 0)
	{
		if ((data->flags)[ZERO] == '0')
			print_n('0', data->width - len);
		else
			print_n(' ', data->width - len);
	}
	i = 0;
	while (i < len)
		ft_putcount(s[i++]);
	if ((data->flags)[MINUS] == '-')
		print_n(' ', data->width - len);
}

void		ft_printf_ls(t_data *data, wchar_t *ws)
{
	int		i;
	int		j;
	int		len;
	char	*s;

	s = (char *)ws;
	len = (data->prec < ft_wcslen(ws)) ? (data->prec) : (ft_wcslen(ws));
	len = (len == -1) ? (ft_wcslen(ws)) : len;
	if ((len < data->width) && ((data->flags)[MINUS] == 0))
	{
		if ((data->flags)[ZERO] == '0')
			print_n('0', data->width - len);
		else
			print_n(' ', data->width - len);
	}
	i = 0;
	j = 0;
	while (i++ < len)
	{
		ft_putcount(*(s + j++));
		while (!s[j] && i < len)
			j++;
	}
	if ((data->flags)[MINUS] == '-')
		print_n(' ', data->width - len);
}