/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkelmani <rkelmani@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/03 11:00:00 by rkelmani          #+#    #+#             */
/*   Updated: 2020/06/10 00:06:50 by rkelmani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void		ft_read(t_tab *tab, int fd)
{
	if (tab->validate == NULL)
	{
		tab->nread = read(fd, tab->str1, BUFFER_SIZE);
		if (tab->nread > 0)
			tab->value = 1;
		else if (tab->nread < 0)
			tab->value = -1;
		else
			tab->value = 0;
		tab->validate = tab->str1;
	}
	tab->cont2 = 0;
	tab->cont1 = 0;
}

char		*ft_wread(t_tab *tab, int fd)
{
	char	*ptr;
	char	*ptr2;

	tab->cont1 = tab->cont2;
	while (tab->str1[tab->cont1] != '\n' && (tab->cont1 < tab->nread))
		tab->cont1 += 1;
	ptr = ft_substr(tab->str1, tab->cont2, (tab->cont1 - tab->cont2));
	while (tab->str1[tab->cont1] != '\n' && tab->value > 0)
	{
		tab->validate = NULL;
		ft_read(tab, fd);
		while (tab->str1[tab->cont1] != '\n' && tab->cont1 < tab->nread)
			tab->cont1 += 1;
		ptr2 = ft_substr(tab->str1, tab->cont2, tab->cont1);
		tab->str2 = ptr;
		ptr = ft_strjoin(tab->str2, ptr2);
		free(tab->str2);
		free(ptr2);
	}
	tab->cont2 = tab->cont1;
	return (ptr);
}

int			get_next_line(int fd, char **line)
{
	static	t_tab tab;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (-1);
	if (tab.validate == NULL)
		ft_read(&tab, fd);
	if (tab.nread < 0)
		return (-1);
	*line = ft_wread(&tab, fd);
	if (tab.str1[tab.cont2] == '\n')
		tab.cont2 += 1;
	if (tab.nread < BUFFER_SIZE && tab.cont2 > tab.nread)
		tab.value = 0;
	return (tab.value);
}
