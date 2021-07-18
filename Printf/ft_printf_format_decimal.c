/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_format_decimal.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkelmani <rkelmani@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/18 18:44:42 by rkelmani          #+#    #+#             */
/*   Updated: 2020/09/24 19:15:33 by rkelmani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_is_neg(long n)
{
	if (n < 0)
		return (-1);
	return (0);
}

static int	ft_int_precision_interfer(t_flags *flags, char *str)
{
	int		required;
	int		len;

	len = (int)ft_strlen(str);
	required = 0;
	if (str[0] == '0' && flags->precision_value == 0 &&
		flags->precision_enabled)
		required = flags->width_value;
	else if (flags->width_enabled && flags->precision_negative)
		required = flags->width_value - len;
	else if (flags->precision_enabled && flags->precision_value == 0)
		required = flags->width_value - len;
	else if (flags->precision_value <= len && !flags->width_enabled)
		required = flags->width_value - len;
	else if (flags->precision_value > len && flags->width_enabled)
		required = flags->width_value - flags->precision_value;
	else if (flags->precision_value <= len && flags->width_enabled)
		required = flags->width_value - len;
	return (required);
}

static void	ft_check_width_enabled(t_arg *args, int neg, int req)
{
	if ((!args->flags->width_enabled || req <= 0) && neg == -1)
		ft_printf_putchar(args->arguments, '-');
	else if (args->flags->side && neg == -1 && req <= 0)
		ft_printf_putchar(args->arguments, '-');
	else if (args->flags->side && neg == -1)
		ft_printf_putchar(args->arguments, '-');
}

void		ft_printf_format_decimal(t_arg *args)
{
	int				num;
	char			*str;
	int				required;

	num = va_arg(args->arguments->arguments, int);
	required = ft_is_neg(num);
	str = ft_itoa_base(ft_abs(num), "0123456789");
	required += ft_int_precision_interfer(args->flags, str);
	if (args->flags->side || args->flags->width_negative)
	{
		ft_check_width_enabled(args, ft_is_neg(num), required);
		ft_printf_putdecimal(args, str);
		ft_printf_width_handler_num(required, args, ft_is_neg(num));
	}
	else
	{
		ft_printf_width_handler_num(required, args, ft_is_neg(num));
		ft_check_width_enabled(args, ft_is_neg(num), required);
		ft_printf_putdecimal(args, str);
	}
	free(str);
}
