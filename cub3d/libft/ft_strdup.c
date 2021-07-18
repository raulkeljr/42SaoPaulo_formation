/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkelmani <rkelmani@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/17 12:44:35 by rkelmani          #+#    #+#             */
/*   Updated: 2020/11/17 12:44:39 by rkelmani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*s2;
	size_t	lenplus;

	lenplus = ft_strlen(s1) + 1;
	if (!(s2 = malloc(lenplus * sizeof(char))))
		return (NULL);
	ft_memcpy(s2, s1, lenplus);
	return (s2);
}
