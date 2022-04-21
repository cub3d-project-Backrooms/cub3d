#include "engine.h"
#include "renderer.h"
#include "std__math.h"
#include <math.h>

int	renderer__draw_minimap_color(
	t_renderer *this, t_ivec *pos_map, t_ivec *player_pos)
{
	int color;

	if (ivec__is_equal(pos_map, player_pos))
		color = COLOR__RED;
	else if (this->world.worldmap[pos_map->x][pos_map->y])
		color = COLOR__GRAY;
	else
		color = COLOR__WHITE;
	return (color);
}

void	renderer__draw_minimap_at(
	t_renderer *this, t_ivec player_pos, t_irange x_range, t_irange y_range)
{
	t_ivec		pos_map;
	t_irange	map_range_x;
	t_irange	map_range_y;
	t_ivec idx;

	map_range_x = (t_irange){0, this->world.world_width};
	map_range_y = (t_irange){0, this->world.world_height};
	idx = (t_ivec){x_range.start - 1, y_range.start - 1};
	while (++idx.x < x_range.end)
	{
		idx.y = y_range.start - 1;
		while (++idx.y < x_range.end)
		{
			pos_map = (t_ivec){
				math__normalize(idx.x, x_range, map_range_x),
				math__normalize(idx.y, y_range, map_range_y)};
			this->buf[idx.x][idx.y]
				= renderer__draw_minimap_color(this, &pos_map, &player_pos);
		}
	}
}

void	renderer__draw_minimap(t_renderer *this, t_camera *camera)
{
	t_ivec	pos;

	pos = camera__to_pos_at_map(camera);
	renderer__draw_minimap_at(
		this, pos, (t_irange){5, 96 +5}, (t_irange){5, 96 + 5});
}
