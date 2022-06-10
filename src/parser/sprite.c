#include "types__parser.h"
#include "types__renderer.h"
#include "engine.h"
#include "std__system.h"

static void	world__init__sprite(t_world *this, t_i64vec *pos, int index)
{
	const	t_sprite sprite = {
		.pos = (t_vec){pos->x + 0.5, pos->y + 0.5},
		.distance = UNSET
	};

	this->sprites[index] = sprite;
}

void	world__init__sprites(t_world *this)
{
	t_i64vec	it;
	int			index;

	this->sprites = std__allocate(this->num_sprites, sizeof(t_sprite));
	index = -1;
	it.y = -1;
	while (++it.y < this->world_height)
	{
		it.x = -1;
		while (++it.x < this->world_width)
			if (get_tile_type64(this, &it) == MAPFMT__SPRITE)
				world__init__sprite(this, &it, ++index);
	}
}
