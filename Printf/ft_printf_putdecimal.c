/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_putdecimal.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkelmani <rkelmani@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/18 18:47:15 by rkelmani          #+#    #+#             */
/*   Updated: 2020/09/24 19:29:04 by rkelmani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_add_precision_zeros(t_arg *args, char *str)
{
	int	zeros_needed;

	zeros_needed = args->flags->precision_value - (int)ft_strlen(str);
	if (args->flags->precision_negative)
		return ;
	while (zeros_needed && zeros_needed > 0)
	{
		ft_printf_putchar(args->arguments, '0');
		zeros_needed--;
	}
}

void		ft_printf_putdecimal(t_arg *args, char *str)
{
	int	i;

	i = 0;
	if (args->flags->precision_value >= (int)ft_strlen(str) ||
		(args->flags->precision_enabled && args->flags->precision_value == 0))
	{
		ft_add_precision_zeros(args, str);
		if (str[i] == '0' && args->flags->precision_value == 0)
			return ;
		while (str[i])
		{
			ft_printf_putchar(args->arguments, str[i]);
			i++;
		}
	}
	else
	{
		while (str[i])
		{
			ft_printf_putchar(args->arguments, str[i]);
			i++;
		}
	}
}

void		ft_printf_putpointer(t_arg *args, char *str)
{
	int	i;

	i = 0;
	if (args->flags->precision_value >= (int)ft_strlen(str))
	{
		ft_add_precision_zeros(args, str);
		while (str[i])
		{
			ft_printf_putchar(args->arguments, str[i]);
			i++;
		}
	}
	else
	{
		while (str[i])
		{
			ft_printf_putchar(args->arguments, str[i]);
			i++;
		}
	}
}

void		ft_printf_put_uint(t_arg *args, char *str)
{
	int	i;

	i = 0;
	if (args->flags->precision_value >= (int)ft_strlen(str) ||
		(args->flags->precision_enabled && args->flags->precision_value == 0))
	{
		ft_add_precision_zeros(args, str);
		if (str[i] == '0' && args->flags->precision_value == 0)
			return ;
		while (str[i])
		{
			ft_printf_putchar(args->arguments, str[i]);
			i++;
		}
	}
	else
	{
		while (str[i])
		{
			ft_printf_putchar(args->arguments, str[i]);
			i++;
		}
	}
}
