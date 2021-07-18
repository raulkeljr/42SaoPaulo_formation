/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_putstr.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkelmani <rkelmani@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/18 18:47:25 by rkelmani          #+#    #+#             */
/*   Updated: 2020/09/24 19:16:03 by rkelmani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printf_putstr(t_arg *args, char *str)
{
	int	i;

	i = 0;
	if (args->flags->precision_enabled && !args->flags->precision_negative)
	{
		while (str[i] && i < args->flags->precision_value)
		{
			ft_putchar_fd(str[i], args->arguments->fd);
			args->arguments->return_value += 1;
			i++;
		}
	}
	else
	{
		while (str[i])
		{
			ft_putchar_fd(str[i], args->arguments->fd);
			args->arguments->return_value += 1;
			i++;
		}
	}
}
