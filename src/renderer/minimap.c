/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youkim    <youkim@student.42seoul.kr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 10:13:06 by youkim            #+#    #+#             */
/*   Updated: 2022/05/04 10:13:06 by youkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"
#include "renderer.h"
#include "std__math.h"
#include "flags.h"
#include <math.h>

static void	renderer__draw_minimap_color(
	t_renderer *this, t_ivec *pos_map, t_ivec *player_pos, t_ivec *it)
{
	t_rgb		color;
	const int	tile = this->world.worldmap[pos_map->y][pos_map->x];

	if (tile == MAPFMT__EMPTY)
		return ;
	else if (ivec__is_equal(pos_map, player_pos))
		color = COLOR__RED;
	else if (tile == MAPFMT__DOOR || tile == MAPFMT__DOOR_OPEN)
		color = COLOR__BLUE;
	else if (tile == MAPFMT__SPRITE)
		color = COLOR__ORANGE;
	else if (tile == MAPFMT__WALL)
		color = COLOR__GRAY;
	else
		color = COLOR__WHITE;
	this->buf[it->y][it->x] = color;
}

void	renderer__draw_minimap_at(
	t_renderer *this, t_ivec player_pos, t_irange x_range, t_irange y_range)
{
	t_ivec			it;
	t_ivec			pos_map;
	const t_irange	map_range_x = (t_irange){0, this->world.world_width};
	const t_irange	map_range_y = (t_irange){0, this->world.world_height};

	it = (t_ivec){x_range.start - 1, y_range.start - 1};
	while (++it.y < y_range.end)
	{
		it.x = x_range.start - 1;
		while (++it.x < x_range.end)
		{
			pos_map = (t_ivec){
				math__normalize(it.x, x_range, map_range_x),
				math__normalize(it.y, y_range, map_range_y)};
			renderer__draw_minimap_color(this, &pos_map, &player_pos, &it);
		}
	}
}

void	renderer__draw_minimap(t_renderer *this, t_camera *camera)
{
	const t_ivec	pos = camera__to_pos_at_map(camera);
	const t_irange	xrange = (t_irange){
		4, math__min(4 + MINIMAP_PIX * (this->world.world_width), WIDTH / 2)};
	const t_irange	yrange = (t_irange){
		4, math__min(4 + MINIMAP_PIX * (this->world.world_height), HEIGHT / 2)};

	renderer__draw_minimap_at(this, pos, xrange, yrange);
}
