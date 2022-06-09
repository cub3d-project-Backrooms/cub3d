#include "engine.h"

bool	is_collision_with_wall(t_world *world, const t_ivec *pos)
{
	const t_mapfmt	tile_type = world->worldmap[pos->y][pos->x];

	return (tile_type == MAPFMT__WALL
		|| tile_type == MAPFMT__DOOR);
}
