/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkelmani <rkelmani@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/12 12:32:35 by rkelmani          #+#    #+#             */
/*   Updated: 2020/11/24 16:38:43 by rkelmani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	assign_ray(t_ray *ray, t_point *collis, double dist_wall, int coord)
{
	ray->collision->x = collis->x;
	ray->collision->y = collis->y;
	ray->dist_wall = dist_wall;
	ray->coord = coord;
}

static void	check_closest_wall(t_conf *conf, t_ray *ray, double ray_angle)
{
	t_point	horz_intercept;
	t_point	vert_intercept;
	double	dist_horz;
	double	dist_vert;

	cast_ray(conf, ray_angle, HORZ, &horz_intercept);
	cast_ray(conf, ray_angle, VERT, &vert_intercept);
	dist_horz = is_end_window(conf->map, horz_intercept.x, horz_intercept.y) ?
	INT_MAX : dist_btw_points(conf->player->posit->x, conf->player->posit->y,
	horz_intercept.x, horz_intercept.y);
	dist_vert = is_end_window(conf->map, vert_intercept.x, vert_intercept.y) ?
	INT_MAX : dist_btw_points(conf->player->posit->x, conf->player->posit->y,
	vert_intercept.x, vert_intercept.y);
	if (dist_horz < dist_vert)
		assign_ray(ray, &horz_intercept, dist_horz, HORZ);
	else
		assign_ray(ray, &vert_intercept, dist_vert, VERT);
}

int			**ft_raycast(t_conf *conf)
{
	int		i;

	i = 0;
	conf->player->dist_proj_plane = (conf->map->width / 2) / (tan(FOV / 2));
	while (i < conf->map->num_rays)
	{
		conf->ray[i]->ray_angle = conf->player->rotation_angle +
			atan2(i - conf->map->num_rays / 2, conf->player->dist_proj_plane);
		conf->ray[i]->ray_angle = ft_normalize_angle(conf->ray[i]->ray_angle);
		check_closest_wall(conf, conf->ray[i], conf->ray[i]->ray_angle);
		i++;
	}
	return (0);
}
