/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkelmani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 13:11:21 by rkelmani          #+#    #+#             */
/*   Updated: 2020/03/04 17:26:37 by rkelmani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*c;
	int		x;

	x = 0;
	if (!(c = (char *)malloc(ft_strlen(((char *)s1)) + 1)))
		return (NULL);
	if (!s1)
		return (NULL);
	while (*s1)
	{
		c[x] = *s1;
		s1++;
		x++;
	}
	c[x] = '\0';
	return (c);
}
