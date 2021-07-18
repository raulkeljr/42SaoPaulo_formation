/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkelmani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 13:00:22 by rkelmani          #+#    #+#             */
/*   Updated: 2020/03/04 17:28:39 by rkelmani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_sizenumber(long int n)
{
	int			a;
	long int	b;

	a = 1;
	b = n;
	if (n < 0)
	{
		b = b * (-1);
		a = a + 1;
	}
	while (b > 9)
	{
		b = b / 10;
		a++;
	}
	return (a);
}

char	*ft_itoa(int n)
{
	char		*ptr;
	int			a;
	long int	b;

	a = ft_sizenumber(n);
	if (!(ptr = ((char *)malloc(sizeof(char) * a + 1))))
		return (NULL);
	ptr[a] = '\0';
	a = a - 1;
	b = n;
	b = n < 0 ? b * (-1) : b;
	while (b > 9)
	{
		ptr[a] = (b % 10 + 48);
		a--;
		b = b / 10;
	}
	if (b < 10)
	{
		ptr[a] = (b % 10 + 48);
		a--;
	}
	if (n < 0)
		ptr[a] = '-';
	return (ptr);
}
