/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkelmani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 13:01:52 by rkelmani          #+#    #+#             */
/*   Updated: 2020/03/02 13:02:37 by rkelmani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char *dest;
	unsigned char *sour;

	sour = ((unsigned char *)src);
	dest = ((unsigned char *)dst);
	if (!n || dest == sour)
		return (dst);
	while (n--)
	{
		*dest++ = *sour++;
	}
	return (dst);
}
