/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_bmp_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkelmani <rkelmani@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/12 12:33:37 by rkelmani          #+#    #+#             */
/*   Updated: 2020/11/24 16:38:43 by rkelmani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	little_endian_int(unsigned char *addr, unsigned int value)
{
	addr[0] = (unsigned char)(value);
	addr[1] = (unsigned char)(value >> 8);
	addr[2] = (unsigned char)(value >> 16);
	addr[3] = (unsigned char)(value >> 24);
}

static int	store_color(t_conf *conf, int x, int y)
{
	unsigned int	color;
	unsigned char	addr_color[4];

	color = *(unsigned int *)(conf->data->addr +
	conf->map->width * (conf->map->height - y - 1) * 4 +
	x * 4);
	little_endian_int(&addr_color[0], color);
	return (*(unsigned int*)(addr_color));
}

static void	bmp_header(t_conf *conf, int fd)
{
	unsigned char	file[54];
	int				filesize;

	ft_bzero(&file, 54);
	filesize = 54 + conf->map->height * conf->map->width * conf->data->bpp / 8;
	file[0] = (unsigned char)('B');
	file[1] = (unsigned char)('M');
	little_endian_int(&file[2], filesize);
	file[10] = (unsigned char)(54);
	file[14] = (unsigned char)(40);
	little_endian_int(&file[18], conf->map->width);
	little_endian_int(&file[22], conf->map->height);
	file[26] = (unsigned char)(1);
	file[28] = (unsigned char)(32);
	write(fd, &file, 54);
}

int			save_bmp_file(t_conf *conf)
{
	int		fd;
	int		bmp[conf->map->height][conf->map->width];
	int		x;
	int		y;

	if ((fd = open("im.bmp", O_WRONLY | O_CREAT | O_TRUNC | O_APPEND, 777)) < 0)
		return (0);
	bmp_header(conf, fd);
	y = 0;
	while (y < conf->map->height)
	{
		x = 0;
		while (x < conf->map->width)
		{
			bmp[y][x] = store_color(conf, x, y);
			write(fd, &bmp[y][x], 4);
			x++;
		}
		y++;
	}
	close(fd);
	return (1);
}
