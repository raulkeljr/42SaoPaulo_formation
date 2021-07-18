/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkelmani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 11:51:10 by rkelmani          #+#    #+#             */
/*   Updated: 2020/03/04 11:59:41 by rkelmani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_lstsize(t_list *lst)
{
	int		a;
	t_list	*ptr;

	ptr = lst;
	a = 1;
	if (!lst)
		return (0);
	while (ptr->next != '\0')
	{
		a++;
		ptr = ptr->next;
	}
	return (a);
}
