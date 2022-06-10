/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkim <tkim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 13:26:13 by tkim              #+#    #+#             */
/*   Updated: 2022/06/10 13:26:14 by tkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"
#include "std__math.h"

static void	toggle(t_mapfmt *tile_type, t_mapfmt on, t_mapfmt off)
{
	if (*tile_type == on)
		*tile_type = off;
	else if (*tile_type == off)
		*tile_type = on;
}

void	engine__toggle_door(t_engine *this)
{
	t_i64vec		it;
	const t_world	*world = &this->renderer.world;

	it.y = -1;
	while (++it.y < world->world_height)
	{
		it.x = -1;
		while (++it.x < world->world_width)
		{
			toggle(&world->worldmap[it.y][it.x],
				MAPFMT__DOOR, MAPFMT__DOOR_OPEN);
		}
	}
}

void	engine__handle_door(t_engine *this)
{
	const t_ivec	ipos = vec__to_ivec(&this->camera.pos);

	if (this->inputhandler.is_toggle_door
		&& !is_collision_with_door(&this->renderer.world, &ipos))
	{
		engine__toggle_door(this);
		this->inputhandler.is_toggle_door = false;
	}
}
