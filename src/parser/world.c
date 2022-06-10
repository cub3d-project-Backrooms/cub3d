#include "types__parser.h"
#include "renderer.h"
#include "std__system.h"
#include "parser.h"
#include "engine.h"

/**
 * @brief set position && direction of player.
 *
 * 0.5 is added to x && y to avoid 'ghosting' thru walls.
 */
static void	world__init__player(t_world *this, t_i64vec it)
{
	const t_mapfmt	tile = get_tile_type64(this, &it);

	if (!mapformat__is_player(tile))
		return ;
	if (this->has_player)
		std__panic("duplicate player position");
	this->has_player = true;
	this->camera.pos = (t_vec){it.x + 0.5, it.y + 0.5};
	if (tile == MAPFMT__SOUTH)
		camera__rotate(&this->camera, STD__PI);
	else if (tile == MAPFMT__WEST)
		camera__rotate(&this->camera, -STD__PI / 2);
	else if (tile == MAPFMT__EAST)
		camera__rotate(&this->camera, STD__PI / 2);
}

static void	world__count_sprites(t_world *this, t_i64vec it)
{
	if (get_tile_type64(this, &it) == MAPFMT__SPRITE)
		this->num_sprites++;
}

static t_camera	camera__init(void)
{
	const t_camera	camera = {
		.pos = {UNSET, UNSET},
		.dir = {0, -1},
		.plane = {0.66, 0},
	};

	return (camera);
}

void	world__init(t_world *this, t_string_arr raw_map, t_sizevec map_size)
{
	t_i64vec	it;

	this->has_player = false;
	this->camera = camera__init();
	this->world_height = map_size.height;
	this->world_width = map_size.width;
	this->num_sprites = 0;
	this->worldmap = std__allocate(map_size.height, sizeof(t_mapfmt *));
	it.y = -1;
	while (++it.y < map_size.height)
	{
		this->worldmap[it.y] = std__allocate(map_size.width, sizeof(t_mapfmt));
		it.x = -1;
		while (++it.x < map_size.width)
		{
			this->worldmap[it.y][it.x] = raw_map[it.y][it.x];
			world__init__player(this, it);
			world__count_sprites(this, it);
		}
	}
	if (!this->has_player)
		std__panic("player not in map");
}
