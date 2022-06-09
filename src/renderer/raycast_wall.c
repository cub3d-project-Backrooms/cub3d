/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_wall.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youkim    <youkim@student.42seoul.kr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 10:13:06 by youkim            #+#    #+#             */
/*   Updated: 2022/05/04 10:13:06 by youkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"
#include "renderer.h"
#include "types__parser.h"
#include "std__math.h"
#include <math.h>

void	renderer__draw__vertical_wall(t_renderer *this,
									int lineheight,
									t_rgb color,
									int x)
{
	const int	draw_start = math__max(-lineheight / 2 + HEIGHT / 2, 0);
	const int	draw_end = math__min(lineheight / 2 + HEIGHT / 2, HEIGHT - 1);
	int			y;

	y = draw_start - 1;
	while (++y < draw_end)
		this->buf[y][x] = color;
}

void	walldata__raycast__set_dda_vector(
	t_walldata *this, t_camera *camera, int current_x, t_world *world)
{
	this->camera_x = dda__normalized_plane_x(current_x);
	this->ray_dir = camera__ray_dir_at_position(camera, this->camera_x);
	this->map_pos = camera__to_pos_at_map(camera);
	this->delta_dist = dda__dist_to_next_closest_grid(&this->ray_dir);
	this->step = dda__initial_step(
			camera, &this->map_pos, &this->ray_dir, &this->delta_dist);
	dda__advance_step_until_hit(
		&this->step, &this->map_pos, &this->delta_dist, world);
	this->perp_wall_dist = dda__perpendicular_dist_to_closest_grid(
			&this->step, camera, &this->map_pos, &this->ray_dir);
}

void	walldata__draw__set_wall_data(t_walldata *this, t_camera *camera)
{
	this->lineheight = (int)(HEIGHT / this->perp_wall_dist * 1);
	this->draw_start = math__max(-this->lineheight / 2 + HEIGHT / 2, 0);
	this->draw_end = math__min(this->lineheight / 2 + HEIGHT / 2, HEIGHT - 1);
	if (this->step.is_hit_y_side)
		this->wallx = camera->pos.x + this->perp_wall_dist * this->ray_dir.x;
	else
		this->wallx = camera->pos.y + this->perp_wall_dist * this->ray_dir.y;
	this->wallx -= floor(this->wallx);
}

void	walldata__draw__set_texture_data(t_walldata *this)
{
	this->texx = (int)(this->wallx * (double)TEX__WIDTH);
	if (!this->step.is_hit_y_side && this->ray_dir.x > 0)
		this->texx = TEX__WIDTH - this->texx - 1;
	if (this->step.is_hit_y_side && this->ray_dir.y < 0)
		this->texx = TEX__WIDTH - this->texx - 1;
	this->step_val = 1.0 * TEX__HEIGHT / this->lineheight;
	this->tex_pos
		= (this->draw_start - HEIGHT / 2 + this->lineheight / 2)
		* this->step_val;
}

t_texdata	walldata__get_texdata(t_walldata *data, t_mapfmt tile_type)
{
	t_texdata			texdata;

	if (tile_type == MAPFMT__DOOR)
		texdata = TEX__DOOR;
	else if (data->step.is_hit_y_side && (data->step.y_sign == POSITIVE))
		texdata = TEX__WALL__NORTH;
	else if (data->step.is_hit_y_side && (data->step.y_sign == NEGATIVE))
		texdata = TEX__WALL__SOUTH;
	else if (!data->step.is_hit_y_side && (data->step.x_sign == POSITIVE))
		texdata = TEX__WALL__EAST;
	else
		texdata = TEX__WALL__WEST;
	return (texdata);
}

t_rgb	renderer__draw__wall_texture(t_renderer *this, t_walldata *data)
{
	const int			tex_y = (int)data->tex_pos & (TEX__HEIGHT - 1);
	const t_mapfmt		tile_type = get_tile_type(&this->world, &data->map_pos);
	const t_texdata		texdata
		= walldata__get_texdata(data, tile_type);
	const t_rgb			color
		= this->world.texture[texdata][TEX__HEIGHT * tex_y + data->texx];

	data->tex_pos += data->step_val;
	return (distance_shade(color, data->perp_wall_dist));
}
