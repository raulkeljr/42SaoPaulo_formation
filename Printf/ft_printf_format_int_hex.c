/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_format_int_hex.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkelmani <rkelmani@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/18 18:45:00 by rkelmani          #+#    #+#             */
/*   Updated: 2020/09/24 19:15:40 by rkelmani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_pf_check_empty(char *str, unsigned long ptr,
			t_arg *args)
{
	if (ptr == 0 && args->flags->precision_enabled &&
			args->flags->precision_value == 0)
	{
		free(str);
		return (ft_empty_str());
	}
	return (str);
}

static int	ft_int_precision_interfer(t_flags *flags, char *str)
{
	int		required;
	int		len;

	len = (int)ft_strlen(str);
	required = 0;
	if (flags->precision_enabled && flags->precision_value == 0)
		required = flags->width_value - len;
	else if (flags->precision_value <= len && !flags->width_enabled)
		required = flags->width_value - len;
	else if (flags->precision_value > len && flags->width_enabled)
		required = flags->width_value - flags->precision_value;
	else if (flags->precision_value <= len && flags->width_enabled)
		required = flags->width_value - len;
	return (required);
}

void		ft_printf_format_int_hex(t_arg *args)
{
	unsigned int	num;
	char			*str;
	int				required;

	num = va_arg(args->arguments->arguments, unsigned int);
	if ((args->flags->hex_lower = args->flags->letter_format == 'x'))
		str = ft_itoa_unsigned_base(num, "0123456789abcdef");
	else
		str = ft_itoa_unsigned_base(num, "0123456789ABCDEF");
	str = ft_pf_check_empty(str, num, args);
	required = ft_int_precision_interfer(args->flags, str);
	if (args->flags->side)
	{
		ft_printf_putdecimal(args, str);
		ft_printf_width_handler_num(required, args, 0);
	}
	else
	{
		ft_printf_width_handler_num(required, args, 0);
		ft_printf_putdecimal(args, str);
	}
	free(str);
}
