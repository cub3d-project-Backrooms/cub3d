#include "engine.h"

t_mapfmt	get_tile_type(t_world *world, const t_ivec *pos)
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
