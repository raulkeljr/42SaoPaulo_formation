/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/12 12:31:19 by rkelmani          #+#    #+#             */
/*   Updated: 2020/11/25 19:28:52 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	setup_map(t_conf *conf)
{
	conf->map = ft_calloc(1, sizeof(t_map));
	conf->map->init_posit = NULL;
	conf->map->color_ceiling = -1;
	conf->map->color_floor = -1;
	conf->map->path = ft_calloc(5, sizeof(char *));
	conf->map->path[north] = NULL;
	conf->map->path[south] = NULL;
	conf->map->path[east] = NULL;
	conf->map->path[west] = NULL;
	conf->map->path[sprite] = NULL;
	conf->map->init_posit = NULL;
	conf->map->sprite_posit = NULL;
	conf->map->map_grid = NULL;
	conf->map->n_sprites = 0;
	conf->map->width = 0;
	conf->map->height = 0;
	conf->map->n_row = 0;
	conf->map->n_column = 0;
	if (!(conf->mlx = mlx_init()))
		return (ft_error(conf->map, -16));
	mlx_get_screen_size(conf->mlx, &conf->map->max_w, &conf->map->max_h);
	conf->win = NULL;
	return (1);
}

int			close_program(void)
{
	exit(0);
	return (0);
}

int			main(int argc, char **argv)
{
	t_conf	conf;

	check_args(argc, argv);
	setup_map(&conf);
	if (!read_file(argv[1], conf.map) || !(create_n_check(&conf)))
		return (0);
	init_game(&conf, argc);
	mlx_hook(conf.win, 2, (1l << 0), move_player_press, &conf);
	mlx_hook(conf.win, 17, (1l << 17), clean_before_close, &conf);
	mlx_loop_hook(conf.mlx, update_frame, &conf);
	mlx_loop(conf.mlx);
	return (0);
}
