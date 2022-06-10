/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check__map2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkim <tkim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 13:27:18 by tkim              #+#    #+#             */
/*   Updated: 2022/06/10 13:29:05 by tkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "std__math.h"
#include "parser.h"
#include "flags.h"

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
