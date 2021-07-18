/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkelmani <rkelmani@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/17 12:42:49 by rkelmani          #+#    #+#             */
/*   Updated: 2020/11/17 12:42:52 by rkelmani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t		i;
	char		*dst_c;
	const char	*src_c;

	i = 0;
	dst_c = dst;
	src_c = src;
	if (!dst && !src)
		return (NULL);
	if (src_c < dst_c)
	{
		i = len;
		while (i > 0)
		{
			i--;
			dst_c[i] = src_c[i];
		}
	}
	else
		ft_memcpy(dst_c, src_c, len);
	return (dst_c);
}
