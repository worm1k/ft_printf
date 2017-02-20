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
# include <stdlib.h>
# include "libft/libft.h"
# define ABS(x) (((x) < 0) ? (-(x)) : (x))
# define LOW 0
# define UPP 1

int				g_count;

typedef enum	e_len
{
	NONE, HH, H, L, Z, LL, J
}				t_len;

typedef enum	e_flag
{
	HASH, ZERO, MINUS, PLUS, SPACE
}				t_flag;

typedef struct	s_data
{
	char		*flags;
	int			width;
	int			prec;
	t_len		length;
	char		spec;
}				t_data;

void			ft_putcount(char c);
int				ft_printf(const char *format, ...);
void			print_data(t_data *data);
void			data_flags(const char **format, t_data *data, int *found);
void			data_width(const char **format, t_data *data, int *found);
void			data_prec(const char **format, t_data *data, int *found);
void			data_length(const char **format, t_data *data, int *found);
void			select_func_1(t_data *data, va_list valist);
char			*ft_itoa_base(long value, int base, int *len);
void			ft_printf_s(t_data *data, char *s);
void			ft_printf_ls(t_data *data, wchar_t *s);
void			ft_printf_p(t_data *data, void *p);
void			ft_printf_d(t_data *data, intmax_t n);
void			ft_printf_c(t_data *data, int c);
void			ft_printf_lc(t_data *data, int c);
void			ft_printf_ou(t_data *data, uintmax_t n, int base, int reg);
void			ft_printf_x(t_data *data, uintmax_t n, int reg);
void			print_n(char c, int len);
int 			int_length(intmax_t value, int base);
int 			uint_length(uintmax_t value, int base);
void			data_del(t_data **data);

#endif
