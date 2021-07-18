/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkelmani <rkelmani@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/18 18:47:41 by rkelmani          #+#    #+#             */
/*   Updated: 2020/09/24 19:16:05 by rkelmani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	t_arguments	arguments;

	arguments.format = format;
	arguments.fd = 1;
	arguments.return_value = 0;
	va_start(arguments.arguments, format);
	ft_printf_manager(&arguments);
	va_end(arguments.arguments);
	return (arguments.return_value);
}
