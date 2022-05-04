#include "renderer.h"

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

void	floordata__draw__lights(t_floordata *this)
{
	const bool	is_tile_light
		= (int)this->floor.x % 2 && (int)this->floor.y % 2;

	this->floor_texture = TEX__FLOOR;
	if (is_tile_light)
		this->ceiling_texture = TEX__CEILING1;
	else
		this->ceiling_texture = TEX__CEILING0;
}
