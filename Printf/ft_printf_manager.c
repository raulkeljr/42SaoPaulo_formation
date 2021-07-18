/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_manager.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkelmani <rkelmani@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/18 18:46:29 by rkelmani          #+#    #+#             */
/*   Updated: 2020/09/24 19:15:51 by rkelmani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printf_manager(t_arguments *arguments)
{
	size_t			i;
	unsigned char	c;

	i = 0;
	while ((c = arguments->format[i]))
	{
		i++;
		if (c != '%')
			ft_printf_putchar(arguments, (char)c);
		else
			ft_printf_format_handle(arguments, &i);
	}
}
