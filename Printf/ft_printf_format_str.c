/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_format_str.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkelmani <rkelmani@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/18 18:46:00 by rkelmani          #+#    #+#             */
/*   Updated: 2020/09/24 19:15:47 by rkelmani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_str_precision_interfer(t_flags *flags, char *str)
{
	int		required;
	int		len;

	len = (int)ft_strlen(str);
	if (flags->precision_value >= len || (flags->precision_value == 0 &&
		!flags->precision_enabled))
		required = flags->width_value - len;
	else if (flags->precision_value == 0 && flags->width_enabled)
		required = flags->width_value;
	else if (flags->precision_negative)
		required = flags->width_value - len;
	else
		required = flags->width_value - flags->precision_value;
	return (required);
}

void		ft_printf_format_str(t_arg *args)
{
	char			*str;
	int				required;

	str = va_arg(args->arguments->arguments, char*);
	if (str == NULL)
		str = "(null)";
	required = ft_str_precision_interfer(args->flags, str);
	if (args->flags->side)
	{
		ft_printf_putstr(args, str);
		ft_printf_width_handler(required, args);
	}
	else
	{
		ft_printf_width_handler(required, args);
		ft_printf_putstr(args, str);
	}
}
