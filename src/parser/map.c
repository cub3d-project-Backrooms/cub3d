#include "parser.h"
#include "renderer.h"
#include "std__system.h"
#include "std__string.h"
#include "std__math.h"
#include "types__renderer.h"
#include <stdio.h>

static void	world__init(t_world *this, t_string_arr raw_map, t_sizevec map_size)
{
	t_i64vec	it;

	this->camera = (t_camera){
		.pos = {UNSET, UNSET},
		.dir = {0, 1},
		.plane = {0.66, 0},
	};
	this->world_height = map_size.height;
	this->world_width = map_size.width;
	this->worldmap = std__allocate(map_size.height, sizeof(int *));
	it.y = -1;
	while (++it.y < map_size.height)
	{
		it.x = -1;
		this->worldmap[it.y] = std__allocate(map_size.width, sizeof(int));
		while (++it.x < map_size.width)
		{
			this->worldmap[it.y][it.x]
				= (raw_map[it.y][it.x] == MAPFMT__WALL);
			if (mapformat__is_player(raw_map[it.y][it.x]))
				this->camera.pos = (t_vec){it.y, it.x}; // FIXME: ADD doc and func for why y and x is inverted here
			// TODO: setup func for player position
		}
	}
}

void	parser__parse__map(t_parser *this, t_world *world)
{
	t_string_arr	raw_map_arr;
	t_sizevec		map_size;

	raw_map_arr = parser__new_raw_map_arr(this);
	raw_map_arr__check_valid(raw_map_arr);
	map_size = (t_sizevec){
		.width = raw_map_arr__max_width(raw_map_arr),
		.height = str__len__arr(raw_map_arr),
	};
	raw_map_arr__pad(raw_map_arr, map_size);
	raw_map_arr__check_valid(raw_map_arr);
	world__init(world, raw_map_arr, map_size);
	str__delete__arr(&raw_map_arr);
}
