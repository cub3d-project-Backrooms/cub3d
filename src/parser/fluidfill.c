/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fluidfill.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youkim    <youkim@student.42seoul.kr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 10:13:06 by youkim            #+#    #+#             */
/*   Updated: 2022/05/04 10:13:06 by youkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "std__math.h"
#include "std__color.h"
#include "std__string.h"
#include "parser.h"
#include <stdio.h>

t_ivec	fluidfill__start_pos(t_string_arr this)
{
	t_ivec		it;
	t_mapformat	tile;

	it.y = -1;
	while (this[++it.y])
	{
		it.x = -1;
		while (this[it.y][++it.x])
		{
			tile = this[it.y][it.x];
			if (mapformat__is_valid_fluidfill(tile))
				return (it);
		}
	}
	return ((t_ivec){-100, -100});
}

void	fluidfill__recursive(t_string_arr this, t_ivec node)
{
	int				i;
	t_mapformat		tile;
	const t_ivec	neighbors[8] = {
	{node.x + 1, node.y},
	{node.x - 1, node.y},
	{node.x, node.y + 1},
	{node.x, node.y - 1},
	{node.x + 1, node.y + 1},
	{node.x + 1, node.y - 1},
	{node.x - 1, node.y + 1},
	{node.x - 1, node.y - 1},
	};

	if (node.x < 0 || node.y < 0 || !this[node.y] || !this[node.y][node.x])
		std__panic("Invalid map");
	tile = this[node.y][node.x];
	if (tile == MAPFMT__EMPTY || tile == MAPFMT__ERR)
		std__panic("Invalid map");
	if (tile == MAPFMT__FILL || tile == MAPFMT__WALL)
		return ;
	this[node.y][node.x] = MAPFMT__FILL;
	i = -1;
	while (++i < 8)
		fluidfill__recursive(this, neighbors[i]);
}

bool	raw_map_arr__fluidfill(t_string_arr this, t_sizevec map_size)
{
	t_ivec			start;
	t_string_arr	tmp;

	tmp = str__new__arr(map_size.height, this);
	while (true)
	{
		start = fluidfill__start_pos(tmp);
		if (start.x < 0)
			break ;
		fluidfill__recursive(tmp, start);
	}
	str__delete__arr(&tmp);
	return (true);
}
