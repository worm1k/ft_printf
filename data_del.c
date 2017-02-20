/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_del.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abykov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 19:44:03 by abykov            #+#    #+#             */
/*   Updated: 2017/01/16 19:44:04 by abykov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	data_del(t_data **data)
{
	if (data && *data)
	{
		if((*data)->flags)
			free((*data)->flags);
		free(*data);
	}
}
