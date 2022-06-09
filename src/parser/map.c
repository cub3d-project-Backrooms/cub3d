/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youkim <youkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 10:13:06 by youkim            #+#    #+#             */
/*   Updated: 2022/05/04 13:24:47 by youkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "renderer.h"
#include "std__system.h"
#include "std__string.h"
#include "std__math.h"
#include "types__renderer.h"
#include <stdio.h>

/**
 * @brief set position && direction of player.
 *
 * 0.5 is added to x && y to avoid 'ghosting' thru walls.
 */
static void	world__init__player(
	t_world *this, t_string_arr raw_map, t_i64vec it)
{
	const t_mapfmt	fmt = raw_map[it.y][it.x];

	if (this->has_player)
		std__panic("duplicate player position");
	this->has_player = true;
	this->camera.pos = (t_vec){it.x + 0.5, it.y + 0.5};
	if (fmt == MAPFMT__SOUTH)
		camera__rotate(&this->camera, STD__PI);
	else if (fmt == MAPFMT__WEST)
		camera__rotate(&this->camera, -STD__PI / 2);
	else if (fmt == MAPFMT__EAST)
		camera__rotate(&this->camera, STD__PI / 2);
}

static void	world__init(t_world *this, t_string_arr raw_map, t_sizevec map_size)
{
	t_i64vec	it;

	this->has_player = false;
	this->camera = (t_camera){
		.pos = {UNSET, UNSET},
		.dir = {0, -1},
		.plane = {0.66, 0},
	};
	this->world_height = map_size.height;
	this->world_width = map_size.width;
	this->worldmap = std__allocate(map_size.height, sizeof(t_mapfmt *));
	it.y = -1;
	while (++it.y < map_size.height)
	{
		it.x = -1;
		this->worldmap[it.y] = std__allocate(map_size.width, sizeof(t_mapfmt));
		while (++it.x < map_size.width)
		{
			this->worldmap[it.y][it.x] = raw_map[it.y][it.x];
			if (mapformat__is_player(this->worldmap[it.y][it.x]))
				world__init__player(this, raw_map, it);
		}
	}
	if (!this->has_player)
		std__panic("player not in map");
}

void	parser__parse__map(t_parser *this, t_world *world)
{
	t_string_arr	raw_map_arr;
	t_sizevec		map_size;

	raw_map_arr = parser__new_raw_map_arr(this);
	map_size = (t_sizevec){
		.width = raw_map_arr__max_width(raw_map_arr),
		.height = str__len__arr(raw_map_arr),
	};
	raw_map_arr__pad(raw_map_arr, map_size);
	raw_map_arr__check_valid(raw_map_arr);
	raw_map_arr__fluidfill(raw_map_arr, map_size);
	world__init(world, raw_map_arr, map_size);
	str__delete__arr(&raw_map_arr);
}
