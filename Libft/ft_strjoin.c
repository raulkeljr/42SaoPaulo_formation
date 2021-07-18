/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkelmani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 13:16:59 by rkelmani          #+#    #+#             */
/*   Updated: 2020/03/05 18:38:41 by rkelmani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strjoin(char const *s1, char const *s2)
{
	size_t	cont_s1;
	size_t	cont_s2;
	size_t	cont;
	char	*ptr;

	if (!s1 || !s2)
		return (NULL);
	cont_s1 = ft_strlen(s1);
	cont_s2 = ft_strlen(s2);
	ptr = 0;
	if (!(ptr = malloc(cont_s1 + cont_s2 + 1)))
		return (NULL);
	cont = 0;
	ptr[cont_s1 + cont_s2] = '\0';
	while (cont < (cont_s1 + cont_s2))
	{
		if (cont < cont_s1)
			ptr[cont] = s1[cont];
		else
			ptr[cont] = s2[cont - cont_s1];
		++cont;
	}
	return (ptr);
}
