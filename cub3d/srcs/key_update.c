/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_update.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkelmani <rkelmani@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/12 12:30:57 by rkelmani          #+#    #+#             */
/*   Updated: 2020/11/24 16:38:43 by rkelmani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int			update_frame(t_conf *conf)
{
	put_game(conf);
	mlx_put_image_to_window(conf->mlx, conf->win, conf->data->img, 0, 0);
	return (0);
}

static void	calculate_offset_player(int keycode, t_conf *conf)
{
	t_point	next_posit;
	t_point	offset;
	int		move_step;

	move_step = conf->player->walk_direction * conf->player->move_speed;
	offset.x = (keycode == W_KEY || keycode == S_KEY) ?
		cos(conf->player->rotation_angle) * move_step :
		cos(conf->player->rotation_angle + SOUTH) * move_step;
	offset.y = (keycode == W_KEY || keycode == S_KEY) ?
		sin(conf->player->rotation_angle) * move_step :
		sin(conf->player->rotation_angle + SOUTH) * move_step;
	next_posit.x = conf->player->posit->x + offset.x;
	next_posit.y = conf->player->posit->y + offset.y;
	if (!(is_wall(conf->map, next_posit.x + offset.x, next_posit.y + offset.y,
	'1')) && !(is_wall(conf->map, next_posit.x, next_posit.y, '2')))
	{
		conf->player->posit->x = next_posit.x;
		conf->player->posit->y = next_posit.y;
	}
}

static int	new_position_player(int keycode, t_conf *conf)
{
	if (keycode == W_KEY || keycode == S_KEY ||
		keycode == A_KEY || keycode == D_KEY)
		calculate_offset_player(keycode, conf);
	else if (keycode == RIGHT_ARROW_KEY || keycode == LEFT_ARROW_KEY)
	{
		conf->player->rotation_angle +=
		conf->player->turn_direction * conf->player->rotation_speed;
		conf->player->rotation_angle =
		ft_normalize_angle(conf->player->rotation_angle);
	}
	return (update_frame(conf));
}

int			move_player_press(int keycode, t_conf *conf)
{
	if (keycode == W_KEY)
		conf->player->walk_direction = +1;
	else if (keycode == S_KEY)
		conf->player->walk_direction = -1;
	else if (keycode == D_KEY)
		conf->player->walk_direction = +1;
	else if (keycode == A_KEY)
		conf->player->walk_direction = -1;
	else if (keycode == RIGHT_ARROW_KEY)
		conf->player->turn_direction = +1;
	else if (keycode == LEFT_ARROW_KEY)
		conf->player->turn_direction = -1;
	else if (keycode == M_KEY)
		conf->minimap = conf->minimap == TRUE ? FALSE : TRUE;
	else if (keycode == ESC_KEY)
		return (clean_before_close(conf));
	return (new_position_player(keycode, conf));
}
