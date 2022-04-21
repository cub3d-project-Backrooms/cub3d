#include "std__math.h"
#include "types__parser.h"
#include <stdio.h>

bool	mapformat__is_valid(t_mapformat this)
{
	return (this == MAPFMT__FLOOR || this == MAPFMT__WALL
		|| this == MAPFMT__NORTH || this == MAPFMT__SOUTH
		|| this == MAPFMT__WEST || this == MAPFMT__EAST
		|| this == MAPFMT__EMPTY);
}

void	mapformat__assert_valid(t_mapformat this)
{
	if (not (mapformat__is_valid(this)))
		std__panic__value__char(
			"raw_map_arr__check_valid: invalid tile", this);
}

// void	tile__check_neighbor(t_mapformat this, t_string_arr map)
// {

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
