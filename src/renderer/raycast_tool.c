#include "renderer.h"

t_colors	get_color(t_renderer *renderer, t_ivec *map, bool is_hit_y_side)
{
	const int		index = renderer->world.worldmap[map->y][map->x];
	int				result;
	const t_colors	colors[] = {
		COLOR__YELLOW,
		COLOR__RED,
		COLOR__GREEN,
		COLOR__BLUE,
		COLOR__WHITE,
	};

	if (index > 4)
		result = colors[0];
	else
		result = colors[index];
	if (is_hit_y_side)
		result /= 2;
	return (result);
}

int	shade_color(int color, double divide)
{
	if (divide <= 1.)
		return (color);
	return (((int)(((0xFF0000 & color) >> 16) / divide) << 16)
		+ ((int)(((0x00FF00 & color) >> 8) / divide) << 8)
		+ ((int)((0x0000FF & color) / divide)));
}

int	distance_shade(int color, double distance)
{
	return (shade_color(color, distance / 1.5));
}


void	floordata__draw__checkerboard(t_floordata *this)
{
	bool	checkerboard;

	checkerboard = ((int)this->floor.x + (int)this->floor.y) % 2;
	if (checkerboard)
	{
		this->floorTexture = FLOOR;
		this->ceilingTexture = CEILING;
	}
	else
	{
		this->floorTexture = FLOOR;
		this->ceilingTexture = CEILING2;
	}
}
