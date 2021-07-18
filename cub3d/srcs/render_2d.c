/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_2d.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkelmani <rkelmani@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/12 12:33:08 by rkelmani          #+#    #+#             */
/*   Updated: 2020/11/24 16:38:13 by rkelmani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	put_rays(t_conf *conf)
{
	int	posit[2];
	int	collision[2];
	int	i;

	i = 0;
	while (i < conf->map->num_rays)
	{
		posit[0] = conf->player->posit->x * MAP2D_SCALE + OFFSET;
		posit[1] = conf->player->posit->y * MAP2D_SCALE + OFFSET;
		collision[0] = conf->ray[i]->collision->x * MAP2D_SCALE + OFFSET;
		collision[1] = conf->ray[i]->collision->y * MAP2D_SCALE + OFFSET;
		ft_line(conf->data, posit, collision, conf->player->posit->color);
		i++;
	}
}

void	put_minimap(t_conf *conf)
{
	t_point	p;
	int		i;
	int		j;

	i = -1;
	p.x = conf->point->x;
	p.y = conf->point->y;
	while (++i < conf->map->n_row)
	{
		j = -1;
		conf->point->x = p.x;
		while (++j < conf->map->n_column)
		{
			if (conf->map->map_grid[i][j] == '1')
				ft_rectangle(conf->data, *conf->point,
				TILE_SIZE * MAP2D_SCALE, TILE_SIZE * MAP2D_SCALE);
			conf->point->x = conf->point->x + TILE_SIZE * MAP2D_SCALE;
		}
		conf->point->y = conf->point->y + TILE_SIZE * MAP2D_SCALE;
	}
	assign_point(conf->point, p.x, p.y, conf->point->color);
}

int		is_wall(t_map *map, int x, int y, char identf)
{
	int	grid_x;
	int	grid_y;

	if (is_end_window(map, x, y))
		return (TRUE);
	grid_x = floor(x / TILE_SIZE);
	grid_y = floor(y / TILE_SIZE);
	if (grid_x >= map->n_column || grid_y >= map->n_row)
		return (TRUE);
	if (map->map_grid[grid_y][grid_x] == identf)
		return (TRUE);
	return (FALSE);
}

int		is_end_window(t_map *map, double x, double y)
{
	if (x < 0 || x >= map->n_column * TILE_SIZE ||
		y < 0 || y >= map->n_row * TILE_SIZE)
		return (TRUE);
	return (FALSE);
}
