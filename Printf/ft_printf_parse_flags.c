/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_parse_flags.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkelmani <rkelmani@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/18 18:46:51 by rkelmani          #+#    #+#             */
/*   Updated: 2020/09/24 19:15:57 by rkelmani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_pf_parse_value(t_arg *args, char *str)
{
	int	value;

	if (str[*(args->i)] == '*')
	{
		value = va_arg(args->arguments->arguments, int);
		*(args->i) += 1;
	}
	else
	{
		value = ft_atoi(str + *(args->i));
		*(args->i) += ft_itoa_base_length(value, 10) - 1;
	}
	return (value);
}

static void	ft_pf_parse_width(t_arg *args, char *str)
{
	int	value;

	args->flags->width_enabled = 1;
	value = ft_pf_parse_value(args, str);
	if (value < 0)
	{
		args->flags->side = 1;
		value *= -1;
		args->flags->width_negative = 1;
		args->flags->padding_char = ' ';
	}
	args->flags->width_value = value;
}

static void	ft_pf_parse_precision(t_arg *args, char *str)
{
	int		value;
	size_t	skipped_zeros;

	*(args->i) += 1;
	skipped_zeros = 0;
	while ((str[*(args->i) + skipped_zeros]) == '0')
	{
		skipped_zeros++;
	}
	args->flags->precision_enabled = 1;
	value = ft_pf_parse_value(args, str);
	if (value < 0)
	{
		value *= -1;
		args->flags->precision_negative = 1;
	}
	args->flags->precision_value = value;
	*(args->i) += skipped_zeros;
	if (value == 0)
		*(args->i) -= 1;
}

static void	ft_printf_parse_handler(t_arg *args, char *str)
{
	char	c;

	c = str[*(args->i)];
	if (c == '-')
	{
		args->flags->minus_sign = 1;
		args->flags->padding_char = ' ';
		args->flags->side = 1;
	}
	else if (c == '0')
	{
		if (!args->flags->minus_sign)
			args->flags->padding_char = '0';
	}
	else
	{
		if ((c = str[*(args->i)]) != '.')
			ft_pf_parse_width(args, str);
		if ((c = str[*(args->i)]) == '.')
			ft_pf_parse_precision(args, str);
	}
}

void		ft_printf_parse_flags(t_arg *args, size_t start,
			size_t end)
{
	size_t	length;
	char	*str_flag;
	size_t	index;
	size_t	*old_index;

	length = end - start;
	if (!(str_flag = malloc((length + 1) * sizeof(char))))
		return ;
	ft_memcpy(str_flag, args->arguments->format + start, length);
	str_flag[length] = '\0';
	index = 0;
	old_index = args->i;
	args->i = &index;
	while (index < length)
	{
		ft_printf_parse_handler(args, str_flag);
		index++;
	}
	args->i = old_index;
	free(str_flag);
}
