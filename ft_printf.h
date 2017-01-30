/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abykov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 19:44:03 by abykov            #+#    #+#             */
/*   Updated: 2017/01/16 19:44:04 by abykov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdio.h>
# include "libft.h"

// todo: enum
/*
# define HASH 0
# define ZERO 1
# define MINUS 2
# define PLUS 3
# define SPACE 4
*/
typedef enum	e_len
{
	NONE, HH, H, L, Z, LL, J
}				t_len;

typedef enum	e_flag
{
	HASH, ZERO, MINUS, PLUS, SPACE
}				t_flag;

typedef struct	t_data
{
	char		*flags;
	int			width;
	int			prec;
	t_len		length;
	char		spec;
}				t_data;

int				ft_printf(const char *format, ...);
void			print_data(t_data *data);
void			data_flags(const char **format, t_data *data, int *found);
void			data_width(const char **format, t_data *data, int *found);
void			data_prec(const char **format, t_data *data, int *found);
void			data_length(const char **format, t_data *data, int *found);
void			select_func(t_data *data, va_list valist);
void			ft_printf_s(t_data *data, char *s);
void			ft_printf_ls(t_data *data, wchar_t *s);


#endif
