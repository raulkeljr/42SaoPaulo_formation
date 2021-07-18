/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_3d.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkelmani <rkelmani@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/12 12:33:21 by rkelmani          #+#    #+#             */
/*   Updated: 2020/11/24 16:38:43 by rkelmani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int			get_texture_color(t_tex *tex, int x, int y)
{
	int		offset;

	offset = (y * tex->data->size_line + x * (tex->data->bpp / 8));
	return (*(unsigned int *)(tex->data->addr + offset + 2) << 16 |
			*(unsigned int *)(tex->data->addr + offset + 1) << 8 |
			*(unsigned int *)(tex->data->addr + offset + 0) << 0);
}

void		apllication(double *ymin, double *ymax, double *limit)
{
	*ymin = limit[0];
	*ymax = limit[1];
}

static int	put_text(t_conf *conf, int y, int i, double *limit)
{
	t_ray	*ray;
	double	ymin;
	double	ymax;

	apllication(&ymin, &ymax, limit);
	ray = NULL;
	ray = conf->ray[i];
	if (ray_facing(ray->ray_angle, ray_up) && ray->coord == HORZ)
		return (get_texture_color(conf->tex[north],
			(int)ray->collision->x % conf->tex[north]->width,
			(y - ymin) * (conf->tex[north]->height) / (ymax - ymin)));
	else if (ray_facing(ray->ray_angle, ray_down) && ray->coord == HORZ)
		return (get_texture_color(conf->tex[south],
			(int)ray->collision->x % conf->tex[south]->width,
			(y - ymin) * (conf->tex[south]->height) / (ymax - ymin)));
	else if (ray_facing(ray->ray_angle, ray_right) && ray->coord == VERT)
		return (get_texture_color(conf->tex[east],
			(int)ray->collision->y % conf->tex[east]->width,
			(y - ymin) * (conf->tex[east]->height) / (ymax - ymin)));
	else if (ray_facing(ray->ray_angle, ray_left) && ray->coord == VERT)
		return (get_texture_color(conf->tex[west],
			(int)ray->collision->y % conf->tex[west]->width,
			(y - ymin) * (conf->tex[west]->height) / (ymax - ymin)));
	else
		return (0);
}

static void	put_colors(t_conf *conf, double wall_proj_height, int i)
{
	double	limit_y[2];
	int		x;
	int		y;

	limit_y[0] = (conf->map->height / 2) - (wall_proj_height / 2);
	limit_y[1] = (conf->map->height / 2) + (wall_proj_height / 2);
	x = i * WALL_WIDTH;
	while (x < (i + 1) * WALL_WIDTH)
	{
		y = -1;
		while (++y <= limit_y[0] && y < conf->map->height)
			my_mlx_pixel_put(conf->data, x, y, conf->map->color_ceiling);
		y--;
		while (++y <= limit_y[1] && y < conf->map->height)
			my_mlx_pixel_put(conf->data, x, y, put_text(conf, y, i, limit_y));
		y--;
		while (++y < conf->map->height)
			my_mlx_pixel_put(conf->data, x, y, conf->map->color_floor);
		x++;
	}
}

void		put_3dmap(t_conf *conf)
{
	double	correct_dist_plane;
	double	wall_proj_height;
	int		i;

	i = 0;
	while (i < conf->map->num_rays)
	{
		correct_dist_plane = conf->ray[i]->dist_wall *
					cos(conf->ray[i]->ray_angle - conf->player->rotation_angle);
		wall_proj_height = TILE_SIZE / correct_dist_plane *
							conf->player->dist_proj_plane;
		put_colors(conf, wall_proj_height, i);
		i++;
	}
}
