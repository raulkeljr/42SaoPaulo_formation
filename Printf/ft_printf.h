/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkelmani <rkelmani@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/18 18:47:53 by rkelmani          #+#    #+#             */
/*   Updated: 2020/09/24 19:26:29 by rkelmani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>

# include "libft/libft.h"

typedef struct	s_arguments
{
	int			return_value;
	const char	*format;
	va_list		arguments;
	int			fd;

}				t_arguments;

typedef struct	s_flags
{
	char		letter_format;
	int			hex_lower;
	int			side;
	int			minus_sign;
	int			width_value;
	int			width_enabled;
	int			width_negative;
	int			precision_value;
	int			precision_enabled;
	int			precision_negative;
	char		padding_char;
}				t_flags;

typedef struct	s_arg
{
	t_arguments	*arguments;
	t_flags		*flags;
	size_t		*i;
}				t_arg;

int				ft_printf(const char *format, ...);

void			ft_printf_manager(t_arguments *arguments);

void			ft_printf_putchar(t_arguments *arguments, char c);
void			ft_printf_putstr(t_arg *args, char *str);
void			ft_printf_putdecimal(t_arg *args, char *str);
void			ft_printf_putpointer(t_arg *args, char *str);
void			ft_printf_put_uint(t_arg *args, char *str);

void			ft_printf_format_handle(t_arguments *arguments, size_t *i);

void			ft_printf_flags_init(t_flags *flags);
void			ft_printf_parse_flags(t_arg *args,
				size_t start, size_t end);

void			ft_printf_format_char(t_arg *args);
void			ft_printf_format_str(t_arg *args);
void			ft_printf_format_decimal(t_arg *args);
void			ft_printf_format_percentage(t_arg *args);
void			ft_printf_format_pointer(t_arg *args);
void			ft_printf_format_int_hex(t_arg *args);
void			ft_printf_format_uint(t_arg *args);

size_t			ft_itoa_base_length(long number, size_t base);
char			*ft_itoa_base(long num, char *base);
long long int	ft_abs(long long int number);
size_t			ft_itoa_unsigned_base_len(unsigned long number, size_t base);
char			*ft_itoa_unsigned_base(unsigned long num, char *base);

char			*ft_chr_repeat(char c, size_t times);
void			ft_printf_width_handler(int required, t_arg *args);
void			ft_printf_width_handler_num(int required,
				t_arg *args, int neg);

char			*ft_empty_str(void);

#endif
