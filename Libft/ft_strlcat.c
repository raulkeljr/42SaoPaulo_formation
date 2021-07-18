/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkelmani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 18:30:48 by rkelmani          #+#    #+#             */
/*   Updated: 2020/03/05 18:32:44 by rkelmani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dest, const char *orig, size_t size)
{
	unsigned long int num1;
	unsigned long int num2;
	unsigned long int cont;

	cont = 0;
	num1 = ft_strlen(dest);
	num2 = ft_strlen(orig);
	if (size - 1 < num1 || size == 0)
		return (num2 + size);
	while ((num1 + cont < size - 1) && orig[cont] != '\0')
	{
		dest[num1 + cont] = orig[cont];
		++cont;
		dest[num1 + cont] = '\0';
	}
	return (num1 + num2);
}
