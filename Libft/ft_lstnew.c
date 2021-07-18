/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkelmani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 14:46:31 by rkelmani          #+#    #+#             */
/*   Updated: 2020/03/03 16:49:07 by rkelmani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*listn;

	if (!(listn = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	listn->content = (void *)content;
	listn->next = NULL;
	return (listn);
}
