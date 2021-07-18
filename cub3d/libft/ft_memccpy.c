/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkelmani <rkelmani@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/17 12:42:10 by rkelmani          #+#    #+#             */
/*   Updated: 2020/11/17 12:42:14 by rkelmani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t				i;
	unsigned char		*dst_c;
	unsigned const char	*src_c;

	i = 0;
	dst_c = (unsigned char*)dst;
	src_c = (unsigned char*)src;
	while (i < n)
	{
		dst_c[i] = src_c[i];
		if (dst_c[i] == (unsigned char)c)
			return (&dst_c[i + 1]);
		i++;
	}
	return (NULL);
}
