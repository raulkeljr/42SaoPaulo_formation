/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_padders.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkelmani <rkelmani@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/18 18:46:39 by rkelmani          #+#    #+#             */
/*   Updated: 2020/09/24 19:15:53 by rkelmani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*ft_chr_repeat(char c, size_t times)
{
	char *str;

	if (!(str = malloc((times + 1) * sizeof(char))))
		return (NULL);
	ft_memset(str, c, times);
	str[times] = '\0';
	return (str);
}

static void	ft_check_neg_before(int neg, t_arg *args)
{
	if (neg == -1 && args->flags->padding_char == '0')
		ft_printf_putchar(args->arguments, '-');
}

static void	ft_check_neg_after(int neg, t_arg *args)
{
	if (neg == -1 && args->flags->padding_char == ' ' &&
			!args->flags->side)
		ft_printf_putchar(args->arguments, '-');
}

void		ft_printf_width_handler(int required, t_arg *args)
{
	char	*padding;
	size_t	i;

	i = 0;
	if (!args->flags->width_enabled || required < 0)
		return ;
	padding = ft_chr_repeat(args->flags->padding_char, required);
	if (!padding)
		return ;
	while (padding[i])
	{
		ft_putchar_fd(padding[i], args->arguments->fd);
		i++;
		args->arguments->return_value += 1;
	}
	free(padding);
}

void		ft_printf_width_handler_num(int required, t_arg *args,
			int neg)
{
	char	*padding;
	size_t	i;

	i = 0;
	if (args->flags->precision_enabled && !args->flags->precision_negative)
		args->flags->padding_char = ' ';
	if (!args->flags->width_enabled || required <= 0)
		return ;
	padding = ft_chr_repeat(args->flags->padding_char, required);
	ft_check_neg_before(neg, args);
	if (!padding)
		return ;
	while (padding[i])
	{
		ft_putchar_fd(padding[i], args->arguments->fd);
		i++;
		args->arguments->return_value += 1;
	}
	ft_check_neg_after(neg, args);
	free(padding);
}
