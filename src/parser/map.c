#include "parser.h"
#include "std__system.h"
#include "std__string.h"
#include "std__math.h"
#include "types__renderer.h"

static t_grid	raw_map_arr__into_map(t_string_arr this, t_sizevec map_size)
{
	t_i64vec	it;
	t_grid		map;

	map = std__allocate(map_size.height, sizeof(int *));
	it.y = -1;
	while (++it.y < map_size.height)
	{
		it.x = -1;
		map[it.y] = std__allocate(map_size.width, sizeof(int));
		while (++it.x < map_size.width)
			map[it.y][it.x] = this[it.y][it.x] != MAPFMT__FLOOR;
	}
	return (map);
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
	world->worldmap = raw_map_arr__into_map(raw_map_arr, map_size);
}
