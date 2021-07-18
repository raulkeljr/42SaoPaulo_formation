/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_flags_init.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkelmani <rkelmani@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/18 18:44:07 by rkelmani          #+#    #+#             */
/*   Updated: 2020/09/24 19:15:29 by rkelmani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printf_flags_init(t_flags *flags)
{
	flags->letter_format = '\0';
	flags->hex_lower = 0;
	flags->side = 0;
	flags->minus_sign = 0;
	flags->width_value = 0;
	flags->width_enabled = 0;
	flags->width_negative = 0;
	flags->precision_value = 0;
	flags->precision_enabled = 0;
	flags->precision_negative = 0;
	flags->padding_char = ' ';
}
