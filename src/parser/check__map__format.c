/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check__map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkim <tkim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 10:13:06 by youkim            #+#    #+#             */
/*   Updated: 2022/06/10 13:28:48 by tkim             ###   ########.fr       */
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
