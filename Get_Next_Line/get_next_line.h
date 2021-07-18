/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkelmani <rkelmani@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/04 11:19:59 by rkelmani          #+#    #+#             */
/*   Updated: 2020/06/10 00:07:00 by rkelmani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>

typedef struct	s_tab
{
	char		str1[BUFFER_SIZE];
	char		*str2;
	int			cont1;
	int			cont2;
	int			value;
	char		*validate;
	int			nread;
}				t_tab;

int				get_next_line(int fd, char **line);
void			ft_read(t_tab *tab, int fd);
char			*ft_wread(t_tab *tab, int fd);
size_t			ft_strlen(const	char *s);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_substr(char const *s, unsigned int start, size_t len);
void			ft_clear(t_tab *tab);
void			ft_read2(t_tab *tab, int fd);

#endif
