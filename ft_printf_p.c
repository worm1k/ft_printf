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
// == #lx
void		ft_printf_p(t_data *data, void *p)
{
	long	n;
	char	*str;
	int		len;

	n = (long) p;
	str = ft_itoa_base(n, 16, &len);
	ft_putstr("0x");
	ft_putstr(str);
	ft_strdel(&str);
}
