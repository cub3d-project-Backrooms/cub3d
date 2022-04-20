#include "engine.h"
#include "renderer.h"
#include "std__math.h"
#include <math.h>
#include <stdio.h>

const extern int	g_worldmap[24][24];

// TODO: use map struct for map range
void	renderer__draw_minimap_at(t_renderer *this,
								t_ivec player_pos,
								t_irange x_range,
								t_irange y_range)
{
	int			color;
	t_ivec		pos_map;
	t_irange	map_range_x;
	t_irange	map_range_y;

	map_range_x = (t_irange){0, 24};
	map_range_y = (t_irange){0, 24};
	for (int x = x_range.start; x < x_range.end; x++)
	{
		for (int y = y_range.start; y < x_range.end; y++)
		{
			// printf("%d %d\n", nx, ny);
			pos_map = (t_ivec){
				math__normalize(x, x_range, map_range_x),
				math__normalize(y, y_range, map_range_y)};
			if (ivec__is_equal(&pos_map, &player_pos))
				color = COLOR__RED;
			else if (!g_worldmap[pos_map.x][pos_map.y])
				color = 0xCCCCCC;
			else
				color = get_color(this, &pos_map, false);
			this->buf[y][x] = color;
		}
	}
}

// TODO: move camera to renderer
void	renderer__draw_minimap(t_renderer *this, t_camera *camera)
{
	t_ivec	pos;

	pos = camera__to_pos_at_map(camera);
	renderer__draw_minimap_at(this, pos, (t_irange){5, 96}, (t_irange){5, 96});
}
