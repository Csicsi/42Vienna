/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_rays_horizontal.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcsicsak <dcsicsak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 17:09:40 by icseri            #+#    #+#             */
/*   Updated: 2024/12/13 14:46:34 by dcsicsak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	init_ray_state(t_ray_trace_state *ray_state, double player_x,
	double player_y, t_ray *ray)
{
	ray_state->direction = (ray->angle > 0 && ray->angle < M_PI);
	if (ray_state->direction)
	{
		ray_state->y_intercept = floor(player_y) + 1;
		ray_state->y_step = 1;
	}
	else
	{
		ray_state->y_intercept = floor(player_y);
		ray_state->y_step = -1;
	}
	ray_state->x_intercept
		= player_x + (ray_state->y_intercept - player_y) / tan(ray->angle);
	ray_state->x_step = ray_state->y_step / tan(ray->angle);
	ray_state->cur_x = ray_state->x_intercept;
	ray_state->cur_y = ray_state->y_intercept;
}

static void	check_boundaries(t_ray_trace_state *ray_state, t_data *data)
{
	ray_state->map_x = (int)ray_state->cur_x;
	if (ray_state->direction)
		ray_state->map_y = (int)ray_state->cur_y;
	else
		ray_state->map_y = (int)(ray_state->cur_y - 1);
	if (ray_state->map_x < 0)
		ray_state->map_x = 0;
	else if (ray_state->map_x >= data->map.column)
		ray_state->map_x = data->map.column - 1;
	if (ray_state->map_y < 0)
		ray_state->map_y = 0;
	else if (ray_state->map_y >= data->map.row)
		ray_state->map_y = data->map.row - 1;
}

static void	process_hit(t_ray_trace_state *ray_state,
	t_ray *ray, t_data *data)
{
	ray->closest_distance = ray_state->dist;
	ray->hit_x = ray_state->cur_x;
	ray->hit_y = ray_state->cur_y;
	if (ray_state->direction)
	{
		data->ray_dir[ray->index] = SOUTH;
		data->texture_x[ray->index]
			= 1 - (ray->hit_x - floor(ray->hit_x));
	}
	else
	{
		data->ray_dir[ray->index] = NORTH;
		data->texture_x[ray->index]
			= ray->hit_x - floor(ray->hit_x);
	}
	if (data->map.map[ray_state->map_y][ray_state->map_x] == 'D')
		data->ray_dir[ray->index] = DOOR;
}

void	check_horizontal(t_data *data, double player_x,
	double player_y, t_ray *ray)
{
	t_ray_trace_state	ray_state;

	init_ray_state(&ray_state, player_x, player_y, ray);
	while (ray_state.cur_x >= 0 && ray_state.cur_x < data->map.column
		&& ray_state.cur_y >= 0 && ray_state.cur_y < data->map.row)
	{
		check_boundaries(&ray_state, data);
		if (data->map.map[ray_state.map_y][ray_state.map_x] == '1'
			|| data->map.map[ray_state.map_y][ray_state.map_x] == 'D')
		{
			ray_state.dist = sqrt(pow(ray_state.cur_x - player_x, 2)
					+ pow(ray_state.cur_y - player_y, 2));
			if (ray_state.dist < ray->closest_distance)
				process_hit(&ray_state, ray, data);
			break ;
		}
		ray_state.cur_x += ray_state.x_step;
		ray_state.cur_y += ray_state.y_step;
	}
}
