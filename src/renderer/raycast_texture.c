/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_floor.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youkim    <youkim@student.42seoul.kr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 10:13:06 by youkim            #+#    #+#             */
/*   Updated: 2022/05/04 10:13:06 by youkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"
#include "renderer.h"

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
