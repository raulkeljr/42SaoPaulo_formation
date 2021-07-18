/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkelmani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 13:04:19 by rkelmani          #+#    #+#             */
/*   Updated: 2020/03/04 18:56:55 by rkelmani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*ptr;
	int		a;
	int		b;

	if (s)
	{
		a = 0;
		b = ft_strlen(s);
		if (!(ptr = (char *)malloc(b * sizeof(char) + 1)))
			return (NULL);
		while (s[a] != '\0')
		{
			ptr[a] = f(a, s[a]);
			a++;
		}
		ptr[a] = '\0';
		return (ptr);
	}
	return (NULL);
}
