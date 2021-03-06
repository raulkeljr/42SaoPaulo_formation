/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clear.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkelmani <rkelmani@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/12 12:18:35 by rkelmani          #+#    #+#             */
/*   Updated: 2020/11/24 16:38:13 by rkelmani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_tex(void *mlx, t_tex **tex)
{
	int i;

	i = north;
	while (i <= sprite)
	{
		if (tex[i])
		{
			mlx_destroy_image(mlx, tex[i]->data->img);
			free(tex[i]->data);
			tex[i]->data = NULL;
			free(tex[i]);
			tex[i] = NULL;
		}
		i++;
	}
	free(tex);
	tex = NULL;
}

void	check_n_free(void *ptr)
{
	if (ptr)
	{
		free(ptr);
		ptr = NULL;
	}
}

int		free_map(t_map *map)
{
	check_n_free(map->path[north]);
	check_n_free(map->path[south]);
	check_n_free(map->path[east]);
	check_n_free(map->path[west]);
	check_n_free(map->path[sprite]);
	check_n_free(map->path);
	check_n_free(map->init_posit);
	if (map->sprite_posit)
		free_buffer((void **)map->sprite_posit, map->n_sprites);
	if (map->map_grid)
		free_buffer((void **)map->map_grid, map->n_row);
	check_n_free(map);
	return (0);
}

void	free_buffer(void **buffer, int n_arrays)
{
	int i;

	i = 0;
	while (i < n_arrays && buffer[i])
	{
		free(buffer[i]);
		buffer[i] = NULL;
		i++;
	}
	if (buffer)
	{
		free(buffer);
		buffer = NULL;
	}
}

void	free_sprite(t_conf *conf)
{
	int	i;

	i = 0;
	while (i < conf->map->n_sprites)
	{
		free(conf->sprite[i]->posit);
		conf->sprite[i]->posit = NULL;
		free(conf->sprite[i]);
		conf->sprite[i] = NULL;
		i++;
	}
	free(conf->sprite);
	conf->sprite = NULL;
}
