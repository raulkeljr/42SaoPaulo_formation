/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkelmani <rkelmani@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/12 12:33:48 by rkelmani          #+#    #+#             */
/*   Updated: 2020/11/24 16:38:43 by rkelmani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	is_end_window_3d(t_map *map, int x, int y)
{
	if (x < 0 || x >= map->width ||
		y < 0 || y >= map->height)
		return (1);
	return (0);
}

static void	draw_sprite(t_conf *conf, int s, int x0)
{
	t_point			tex;
	t_point			in;
	t_point			c;
	unsigned int	color;
	int				ray_sprite;

	in.x = x0 - conf->sprite[s]->width / 2;
	in.y = (conf->map->height / 2) - (conf->sprite[s]->height / 2);
	c.x = 0;
	while (c.x < conf->sprite[s]->width)
	{
		c.y = 0;
		tex.x = c.x * conf->tex[sprite]->width / conf->sprite[s]->width;
		ray_sprite = (in.x + c.x) / WALL_WIDTH;
		while (c.y < conf->sprite[s]->height)
		{
			tex.y = c.y * conf->tex[sprite]->height / conf->sprite[s]->height;
			if (!is_end_window_3d(conf->map, (in.x + c.x), (in.y + c.y)) &&
			conf->sprite[s]->dist < conf->ray[(int)(ray_sprite)]->dist_wall)
				(color = get_texture_color(conf->tex[sprite], tex.x, tex.y)) ?
				my_mlx_pixel_put(conf->data, in.x + c.x, in.y + c.y, color) : 0;
			c.y++;
		}
		c.x++;
	}
}

static void	calculate_sprite(t_conf *conf, int s)
{
	int xi;

	xi = 0;
	conf->sprite[s]->angle = atan2((conf->sprite[s]->posit->y - conf->player->
	posit->y), (conf->sprite[s]->posit->x - conf->player->posit->x));
	conf->sprite[s]->angle_dif = (conf->player->rotation_angle - conf->sprite[s]
	->angle);
	if (conf->sprite[s]->angle_dif < -1 * PI)
		conf->sprite[s]->angle_dif += 2 * PI;
	if (conf->sprite[s]->angle_dif > PI)
		conf->sprite[s]->angle_dif -= 2 * PI;
	conf->sprite[s]->angle_dif = fabs(conf->sprite[s]->angle_dif);
	conf->sprite[s]->dist *= (cos(conf->sprite[s]->angle_dif));
	if (conf->sprite[s]->angle_dif < FOV / 2)
	{
		conf->sprite[s]->height = (TILE_SIZE * conf->player->dist_proj_plane /
		conf->sprite[s]->dist);
		conf->sprite[s]->width = (conf->sprite[s]->height * conf->tex[sprite]->
		width / conf->tex[sprite]->height);
		xi = tan(conf->sprite[s]->angle - conf->player->rotation_angle) * conf->
		player->dist_proj_plane + (conf->map->width / 2);
		draw_sprite(conf, s, xi);
	}
}

static void	sort_sprite(t_conf *conf)
{
	t_sprite	*aux;
	int			i;

	i = 0;
	while (i < conf->map->n_sprites)
	{
		conf->sprite[i]->dist = dist_btw_points(
			conf->player->posit->x, conf->player->posit->y,
			conf->sprite[i]->posit->x, conf->sprite[i]->posit->y);
		i++;
	}
	i = 0;
	while (i < conf->map->n_sprites - 1)
	{
		if (conf->sprite[i]->dist < conf->sprite[i + 1]->dist)
		{
			aux = conf->sprite[i];
			conf->sprite[i] = conf->sprite[i + 1];
			conf->sprite[i + 1] = aux;
		}
		i++;
	}
}

void		put_sprites(t_conf *conf)
{
	int i;

	i = 0;
	sort_sprite(conf);
	while (i < conf->map->n_sprites)
	{
		calculate_sprite(conf, i);
		i++;
	}
}
