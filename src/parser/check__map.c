#include "std__math.h"
#include "parser.h"
#include <stdio.h>

bool	mapformat__is_player(t_mapformat this)
{
	return (this == MAPFMT__NORTH || this == MAPFMT__SOUTH
		|| this == MAPFMT__WEST || this == MAPFMT__EAST);
}

bool	mapformat__is_valid(t_mapformat this)
{
	return (this == MAPFMT__FLOOR
		|| this == MAPFMT__WALL
		|| this == MAPFMT__EMPTY
		|| mapformat__is_player(this));
}

void	mapformat__assert_valid(t_mapformat this)
{
	if (not (mapformat__is_valid(this)))
		std__panic__value__char(
			"raw_map_arr__check_valid: invalid tile", this);
}

// t_neighbor_dirs	*tile__neighbors_to_check(
// 	t_mapformat this, t_ivec pos, t_string_arr map)
// {
// 	int				i;
// 	t_neighbor_dirs	dirs;

// 	i = -1;
// 	while (++i < 8)
// 		dirs[i] = true;
// 	if (is_first_row(pos))
// 	{
// 		dirs[NEIGHBOR__NW] = false;
// 		dirs[NEIGHBOR_] = false;
// 		dirs[] = false;
// 	}
// }

// void	tile__neighboris__assert_only_wall(char tile_at_map)
// {
// 	if (tile_at_map != MAPFMT__WALL)
// 		std__panic__value__char(
// 			"tile__neighboris__assert_only_wall: invalid tile", tile_at_map);
// }

// typedef void(*t_neighbor_check_func)(
// 	t_mapformat this, char tile_at_map);

// tile__check_neighbor(t_mapformat this,
// 	t_ivec pos, t_string_arr map, t_neighbor_check_func func)
// {
// 	// check northeast
// 	if (not is_first_column(pos) and not is_first_row(pos))
// 		if (func(this, pos + (t_ivec){-1, -1}, map))
// 			return (true);
// }

void	raw_map_arr__check_valid(t_string_arr this)
{
	t_ivec		it;
	t_mapformat	tile;

	it.y = -1;
	while (this[++it.y])
	{
		it.x = -1;
		while (this[it.y][++it.x])
		{
			tile = this[it.y][it.x];
			mapformat__assert_valid(tile);
		}
	}
}
