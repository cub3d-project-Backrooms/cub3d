/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check__map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youkim    <youkim@student.42seoul.kr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 10:13:06 by youkim            #+#    #+#             */
/*   Updated: 2022/05/04 10:13:06 by youkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "std__math.h"
#include "parser.h"
#include "flags.h"

bool	mapformat__is_player(t_mapfmt this)
{
	return (this == MAPFMT__NORTH || this == MAPFMT__SOUTH
		|| this == MAPFMT__WEST || this == MAPFMT__EAST);
}

bool	mapformat__is_valid(t_mapfmt this)
{
	return (this == MAPFMT__FLOOR
		|| this == MAPFMT__WALL
		|| this == MAPFMT__EMPTY
		|| mapformat__is_player(this));
}

bool	mapformat__is_valid_bonus(t_mapfmt this)
{
	return (mapformat__is_valid(this)
		|| this == MAPFMT__DOOR
		|| this == MAPFMT__SPRITE);
}

bool	mapformat__is_valid_fluidfill(t_mapfmt this)
{
	return (!(this == MAPFMT__WALL
			|| this == MAPFMT__EMPTY
			|| this == MAPFMT__FILL));
}

void	mapformat__assert_valid(
	t_mapfmt this, t_mapformat__validator_f func)
{
	if (!(func(this)))
		std__panic__value__char(
			"raw_map_arr__check_valid: invalid tile", this);
}

void	raw_map_arr__check_valid(t_string_arr this)
{
	t_ivec						it;
	t_mapfmt					tile;
	t_mapformat__validator_f	func;

	if (BONUS)
		func = mapformat__is_valid_bonus;
	else
		func = mapformat__is_valid;
	it.y = -1;
	while (this[++it.y])
	{
		it.x = -1;
		while (this[it.y][++it.x])
		{
			tile = this[it.y][it.x];
			mapformat__assert_valid(tile, func);
		}
	}
}
