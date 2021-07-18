/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkelmani <rkelmani@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/17 12:40:27 by rkelmani          #+#    #+#             */
/*   Updated: 2020/11/17 12:40:31 by rkelmani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*tmp;
	t_list	*ft_lst;
	t_list	*elem_f;

	if (!lst)
		return (NULL);
	ft_lst = ft_lstnew((*f)(lst->content));
	if (!ft_lst)
		return (NULL);
	tmp = lst->next;
	while (tmp)
	{
		if (!(elem_f = ft_lstnew((*f)(tmp->content))))
		{
			ft_lstclear(&ft_lst, del);
			return (NULL);
		}
		ft_lstadd_back(&ft_lst, elem_f);
		tmp = tmp->next;
	}
	return (ft_lst);
}
