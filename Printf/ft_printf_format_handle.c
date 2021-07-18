/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_format_handle.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkelmani <rkelmani@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 18:18:26 by lniehues          #+#    #+#             */
/*   Updated: 2020/09/24 19:14:04 by rkelmani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		ft_strchr_printf(const char *s, int c)
{
	char	let;

	let = (char)c;
	while (*s != '\0')
	{
		if (*s == let)
			return (1);
		else
			++s;
	}
	if (let == '\0')
		return (0);
	return (0);
}

static void		ft_printf_select_formats(t_arg *args)
{
	unsigned char		c;

	c = args->flags->letter_format;
	if (c == '%')
		ft_printf_format_percentage(args);
	else if (c == 'c')
		ft_printf_format_char(args);
	else if (c == 's')
		ft_printf_format_str(args);
	else if (c == 'd' || c == 'i')
		ft_printf_format_decimal(args);
	else if (c == 'p')
		ft_printf_format_pointer(args);
	else if (c == 'x' || c == 'X')
		ft_printf_format_int_hex(args);
	else if (c == 'u')
		ft_printf_format_uint(args);
}

void			ft_printf_format_handle(t_arguments *arguments, size_t *i)
{
	t_flags				flags;
	t_arg				args;
	size_t				start;

	args = (t_arg) {arguments, &flags, i};
	ft_printf_flags_init(&flags);
	start = *i;
	flags.letter_format = arguments->format[*i];
	while (!(ft_strchr_printf("cspdiuxX%", flags.letter_format)))
	{
		*i += 1;
		flags.letter_format = arguments->format[*i];
	}
	if (start != *i)
	{
		ft_printf_parse_flags(&args, start, *i);
		ft_printf_select_formats(&args);
		*i += 1;
	}
	else
	{
		ft_printf_select_formats(&args);
		*i += 1;
	}
}
