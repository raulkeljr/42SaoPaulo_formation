/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkelmani <rkelmani@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/12 12:34:13 by rkelmani          #+#    #+#             */
/*   Updated: 2020/11/24 16:38:13 by rkelmani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_data		*create_image(void *mlx_ptr, t_map *map)
{
	t_data	*img;

	img = ft_calloc(1, sizeof(t_data));
	img->img = mlx_new_image(mlx_ptr, map->width, map->height);
	img->addr = mlx_get_data_addr(img->img, &img->bpp, &img->size_line,
	&img->endian);
	return (img);
}

t_point		*create_point(int x, int y, int color)
{
	t_point	*point;

	point = ft_calloc(1, sizeof(t_point));
	assign_point(point, x, y, color);
	return (point);
}

void		assign_point(t_point *point, int x, int y, int color)
{
	point->x = x;
	point->y = y;
	point->color = color;
}

t_ray		**allocate_ray(t_conf *conf)
{
	t_ray	**ray;
	int		i;

	i = 0;
	ray = ft_calloc(conf->map->num_rays, sizeof(t_ray *));
	while (i < conf->map->num_rays)
	{
		ray[i] = ft_calloc(1, sizeof(t_ray));
		ray[i]->collision = ft_calloc(1, sizeof(t_point));
		i++;
	}
	return (ray);
}
