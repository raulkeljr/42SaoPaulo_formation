/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkelmani <rkelmani@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 18:34:31 by rkelmani          #+#    #+#             */
/*   Updated: 2020/09/16 21:32:14 by rkelmani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	let;

	let = (char)c;
	while (*s != '\0')
	{
		if (*s == let)
			return ((char*)s);
		else
			++s;
	}
	if (let == '\0')
		return ((char*)s);
	return (NULL);
}
