/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkelmani <rkelmani@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/12 12:34:01 by rkelmani          #+#    #+#             */
/*   Updated: 2020/11/24 16:38:43 by rkelmani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static t_tex	*load_texture(void *mlx_ptr, char *path)
{
	t_tex	*tex;

	tex = ft_calloc(1, sizeof(t_tex));
	tex->data = ft_calloc(1, sizeof(t_data));
	if (!(tex->data->img = mlx_xpm_file_to_image(mlx_ptr, path, &tex->width,
	&tex->height)))
	{
		free(tex->data);
		free(tex);
		return (NULL);
	}
	tex->data->addr = mlx_get_data_addr(tex->data->img, &tex->data->bpp,
	&tex->data->size_line, &tex->data->endian);
	return (tex);
}

static t_tex	**create_texture(void *mlx_ptr, char **path)
{
	t_tex	**texture;

	texture = ft_calloc(5, sizeof(t_tex *));
	texture[north] = load_texture(mlx_ptr, path[north]);
	texture[south] = load_texture(mlx_ptr, path[south]);
	texture[east] = load_texture(mlx_ptr, path[east]);
	texture[west] = load_texture(mlx_ptr, path[west]);
	texture[sprite] = load_texture(mlx_ptr, path[sprite]);
	if (!(texture[north]) || !(texture[south]) || !(texture[east]) ||
	!(texture[west]) || !(texture[sprite]))
	{
		free_tex(mlx_ptr, texture);
		return (NULL);
	}
	return (texture);
}

static t_player	*create_player(t_map *map, int move_speed, double rotat_speed)
{
	t_player	*player;

	player = ft_calloc(1, sizeof(t_player));
	player->posit = ft_calloc(1, sizeof(t_point));
	player->turn_direction = 0;
	player->walk_direction = 0;
	player->move_speed = move_speed;
	player->rotation_speed = rotat_speed;
	player->rotation_angle = map->rotation_angle;
	assign_point(player->posit, map->init_posit->x, map->init_posit->y,
	RAYS_2D_COLOR);
	check_n_free(map->init_posit);
	return (player);
}

static t_sprite	**create_sprite(t_map *map)
{
	t_sprite	**spr;
	int			i;

	i = 0;
	spr = ft_calloc(map->n_sprites + 2, sizeof(t_sprite *));
	while (i < map->n_sprites)
	{
		spr[i] = ft_calloc(1, sizeof(t_sprite));
		spr[i]->posit = ft_calloc(1, sizeof(t_point));
		spr[i]->posit->x = map->sprite_posit[i]->x * TILE_SIZE + TILE_SIZE / 2;
		spr[i]->posit->y = map->sprite_posit[i]->y * TILE_SIZE + TILE_SIZE / 2;
		check_n_free(map->sprite_posit[i]);
		i++;
	}
	check_n_free(map->sprite_posit);
	return (spr);
}

int				create_n_check(t_conf *conf)
{
	if (!(conf->tex = create_texture(conf->mlx, conf->map->path)))
		return (ft_path_error(conf));
	conf->data = create_image(conf->mlx, conf->map);
	conf->point = create_point(OFFSET, OFFSET, WALL_2D_COLOR);
	conf->player = create_player(conf->map, MOVE_SPEED, ROTAT_SPEED);
	conf->sprite = create_sprite(conf->map);
	conf->minimap = TRUE;
	return (1);
}
