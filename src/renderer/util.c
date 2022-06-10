/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_tool.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youkim    <youkim@student.42seoul.kr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 10:13:06 by youkim            #+#    #+#             */
/*   Updated: 2022/05/04 10:13:06 by youkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "renderer.h"

t_rgb	shade_color(t_rgb color, double divide)
{
	if (divide <= 1.)
		return (color);
	return (((int)(((0xFF0000 & color) >> 16) / divide) << 16)
		+ ((int)(((0x00FF00 & color) >> 8) / divide) << 8)
		+ ((int)((0x0000FF & color) / divide)));
}

t_rgb	distance_shade(int color, double distance)
{
	return (shade_color(color, distance / 1.5));
}

t_rgb	make_colorful(t_rgb color, int by)
{
	if (by == 0)
		return (color);
	return (((int)(((0xFF0000 & color) >> 16) + by) << 16)
		+ ((int)(((0x00FF00 & color) >> 8) + by) << 8)
		+ ((int)((0x0000FF & color) + by)));
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
