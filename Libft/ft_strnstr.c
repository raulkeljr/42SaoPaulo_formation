/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkelmani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 13:18:24 by rkelmani          #+#    #+#             */
/*   Updated: 2020/03/03 18:54:32 by rkelmani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *h, const char *n, size_t l)
{
	unsigned int c1;
	unsigned int c2;

	c1 = 0;
	if (!*n)
		return ((char *)h);
	while (h[c1] && c1 < l)
	{
		c2 = 0;
		if (h[c1] == n[c2])
		{
			while (h[c1 + c2] == n[c2] && (c1 + c2) < l)
			{
				c2++;
				if (!n[c2])
					return ((char *)&h[c1]);
			}
		}
		c1++;
	}
	return (NULL);
}
