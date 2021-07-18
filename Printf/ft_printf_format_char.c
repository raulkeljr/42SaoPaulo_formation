/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_format_char.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkelmani <rkelmani@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/18 18:44:24 by rkelmani          #+#    #+#             */
/*   Updated: 2020/09/24 19:15:31 by rkelmani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printf_format_char(t_arg *args)
{
	char	c;
	int		required;

	c = (char)va_arg(args->arguments->arguments, int);
	required = args->flags->width_value - 1;
	if (args->flags->side)
	{
		ft_putchar_fd(c, args->arguments->fd);
		args->arguments->return_value += 1;
		ft_printf_width_handler(required, args);
	}
	else
	{
		ft_printf_width_handler(required, args);
		ft_putchar_fd(c, args->arguments->fd);
		args->arguments->return_value += 1;
	}
}
