/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_game.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkelmani <rkelmani@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/11 12:22:06 by rkelmani          #+#    #+#             */
/*   Updated: 2020/11/24 16:38:43 by rkelmani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		put_game(t_conf *conf)
{
	ft_raycast(conf);
	put_3dmap(conf);
	put_sprites(conf);
	if (conf->minimap == TRUE)
	{
		put_minimap(conf);
		put_rays(conf);
	}
}

int			init_game(t_conf *conf, int argc)
{
	conf->ray = allocate_ray(conf);
	put_game(conf);
	if (argc == 2)
	{
		conf->win = mlx_new_window(conf->mlx, conf->map->width,
				conf->map->height, "Projeto 42 CUB3D RKELMANI");
		mlx_put_image_to_window(conf->mlx, conf->win, conf->data->img, 0, 0);
	}
	else
	{
		save_bmp_file(conf);
		clean_before_close(conf);
	}
	return (0);
}

int			clean_before_close(t_conf *conf)
{
	free_rays(conf);
	free_sprite(conf);
	free_tex(conf->mlx, conf->tex);
	free_buffer((void **)conf->map->map_grid, conf->map->n_row);
	free_buffer((void **)conf->map->path, 5);
	free(conf->map);
	free(conf->point);
	free(conf->player->posit);
	free(conf->player);
	mlx_destroy_image(conf->mlx, conf->data->img);
	free(conf->data);
	if (conf->win)
		mlx_destroy_window(conf->mlx, conf->win);
	free(conf->mlx);
	return (close_program());
}

void		free_rays(t_conf *conf)
{
	int i;

	i = 0;
	while (i < conf->map->num_rays)
	{
		free(conf->ray[i]->collision);
		conf->ray[i]->collision = NULL;
		free(conf->ray[i]);
		conf->ray[i] = NULL;
		i++;
	}
	free(conf->ray);
	conf->ray = NULL;
}
