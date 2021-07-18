/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkelmani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 15:05:41 by rkelmani          #+#    #+#             */
/*   Updated: 2020/03/04 17:20:32 by rkelmani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t c;

	if (n == 0)
		return (0);
	c = 0;
	while ((s1[c]) && (s2[c]) && s1[c] == s2[c] && c < n - 1)
		c++;
	return ((unsigned char)s1[c] - (unsigned char)s2[c]);
}
