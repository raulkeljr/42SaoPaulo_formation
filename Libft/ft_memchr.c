/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkelmani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 18:05:35 by rkelmani          #+#    #+#             */
/*   Updated: 2020/03/02 13:01:46 by rkelmani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*ptr;
	unsigned char	c2;

	ptr = ((unsigned char *)s);
	c2 = ((unsigned char)c);
	while (n-- != 0)
	{
		if (*ptr == c2)
			return ((void *)ptr);
		ptr++;
	}
	return (NULL);
}
