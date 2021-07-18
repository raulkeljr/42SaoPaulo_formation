/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkelmani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 12:41:26 by rkelmani          #+#    #+#             */
/*   Updated: 2020/03/04 17:49:31 by rkelmani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	unsigned char	*x;
	unsigned char	*sour;
	size_t			i;

	if (!(src) && !(dest))
		return (NULL);
	x = (unsigned char *)dest;
	sour = (unsigned char *)src;
	i = 0;
	if (sour < x)
		while (i++ < len)
			x[len - i] = sour[len - i];
	else
		while (len-- > 0)
			*x++ = *sour++;
	return (dest);
}
