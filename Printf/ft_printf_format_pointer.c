/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_format_pointer.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkelmani <rkelmani@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/18 18:45:33 by rkelmani          #+#    #+#             */
/*   Updated: 2020/09/24 19:15:45 by rkelmani         ###   ########.fr       */
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

static void	ft_printf_putzerox(t_arg *args, char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		ft_putchar_fd(str[i], args->arguments->fd);
		args->arguments->return_value += 1;
		i++;
	}
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

void		ft_printf_format_pointer(t_arg *args)
{
	unsigned long	ptr;
	char			*str;
	int				required;

	ptr = (unsigned long)va_arg(args->arguments->arguments, void *);
	str = ft_itoa_unsigned_base(ptr, "0123456789abcdef");
	str = ft_pf_check_empty(str, ptr, args);
	required = ft_int_precision_interfer(args->flags, str) - 2;
	if (args->flags->side)
	{
		ft_printf_putzerox(args, "0x");
		ft_printf_putpointer(args, str);
		ft_printf_width_handler_num(required, args, 0);
	}
	else
	{
		ft_printf_width_handler_num(required, args, 0);
		ft_printf_putzerox(args, "0x");
		ft_printf_putpointer(args, str);
	}
	free(str);
}
