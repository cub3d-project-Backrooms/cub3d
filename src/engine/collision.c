/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkim <tkim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 13:26:05 by tkim              #+#    #+#             */
/*   Updated: 2022/06/10 13:26:08 by tkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"

t_mapfmt	get_tile_type(t_world *world, const t_ivec *pos)
{
	return (world->worldmap[pos->y][pos->x]);
}

t_mapfmt	get_tile_type64(t_world *world, const t_i64vec *pos)
{
	return (world->worldmap[pos->y][pos->x]);
}

bool	is_collision_with_wall(t_world *world, const t_ivec *pos)
{
	const t_mapfmt	tile_type = get_tile_type(world, pos);

	return (tile_type == MAPFMT__WALL
		|| tile_type == MAPFMT__DOOR);
}

bool	is_collision_with_door(t_world *world, const t_ivec *pos)
{
	const t_mapfmt	tile_type = get_tile_type(world, pos);

	return (tile_type == MAPFMT__DOOR
		|| tile_type == MAPFMT__DOOR_OPEN);
}
