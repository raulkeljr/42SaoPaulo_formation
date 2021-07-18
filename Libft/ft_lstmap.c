/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkelmani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 15:02:25 by rkelmani          #+#    #+#             */
/*   Updated: 2020/03/04 17:45:23 by rkelmani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list *dup;

	if (lst == NULL)
		return (NULL);
	dup = ft_lstnew(lst->content);
	if (dup == NULL)
		return (NULL);
	dup = f(dup);
	dup->next = ft_lstmap(lst->next, f, del);
	if (dup->next == NULL && lst->next != NULL)
	{
		ft_lstclear((t_list **)&dup, del);
		return (NULL);
	}
	return (dup);
}
