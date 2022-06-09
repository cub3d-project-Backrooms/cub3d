/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda__step.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youkim    <youkim@student.42seoul.kr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 10:13:06 by youkim            #+#    #+#             */
/*   Updated: 2022/05/04 10:13:06 by youkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"
#include "renderer.h"
#include "types__renderer.h"
#include <math.h>

t_dda__step	dda__initial_step(t_camera *camera,
								t_ivec *map_pos,
								t_vec *ray_dir,
								t_vec *delta_dist)
{
	t_dda__step	step;

	if (ray_dir->x < 0)
	{
		step.x_sign = NEGATIVE;
		step.side_dist.x = (camera->pos.x - map_pos->x) * delta_dist->x;
	}
	else
	{
		step.x_sign = POSITIVE;
		step.side_dist.x = (map_pos->x + 1.0 - camera->pos.x) * delta_dist->x;
	}
	if (ray_dir->y < 0)
	{
		step.y_sign = NEGATIVE;
		step.side_dist.y = (camera->pos.y - map_pos->y) * delta_dist->y;
	}
	else
	{
		step.y_sign = POSITIVE;
		step.side_dist.y = (map_pos->y + 1.0 - camera->pos.y) * delta_dist->y;
	}
	return (step);
}

void	dda__advance_step(t_dda__step *step, t_ivec *map_pos, t_vec *delta_dist)
{
	if (step->side_dist.x < step->side_dist.y)
	{
		step->side_dist.x += delta_dist->x;
		map_pos->x += step->x_sign;
		step->is_hit_y_side = false;
	}
	else
	{
		step->side_dist.y += delta_dist->y;
		map_pos->y += step->y_sign;
		step->is_hit_y_side = true;
	}
}

// TODO: handle sprites too
bool	dda__is_ray_hit_wall(const t_ivec *pos, t_world *world)
{
	return (world->worldmap[pos->y][pos->x] > 0);
}

void	dda__advance_step_until_hit(t_dda__step *step,
									t_ivec *map_pos,
									t_vec *delta_dist, t_world *world)
{
	while (!dda__is_ray_hit_wall(map_pos, world))
	{
		dda__advance_step(step, map_pos, delta_dist);
	}
}
