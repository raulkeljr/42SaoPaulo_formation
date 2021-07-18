/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkelmani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 14:03:21 by rkelmani          #+#    #+#             */
/*   Updated: 2020/03/04 14:33:23 by rkelmani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list *ptr;
	t_list *ptr2;

	if (lst)
	{
		while (*lst)
		{
			ptr2 = *lst;
			ptr = ptr2->next;
			del(ptr2->content);
			free(ptr2);
			(*lst) = ptr;
		}
	}
}
