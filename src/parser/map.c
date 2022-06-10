/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youkim <youkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 10:13:06 by youkim            #+#    #+#             */
/*   Updated: 2022/05/04 13:24:47 by youkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "renderer.h"
#include "std__system.h"
#include "std__string.h"
#include "std__math.h"
#include "types__renderer.h"

void	parser__parse__map(t_parser *this, t_world *world)
{
	t_string_arr	raw_map_arr;
	t_sizevec		map_size;

	raw_map_arr = parser__new_raw_map_arr(this);
	map_size = (t_sizevec){
		.width = raw_map_arr__max_width(raw_map_arr),
		.height = str__len__arr(raw_map_arr),
	};
	raw_map_arr__pad(raw_map_arr, map_size);
	raw_map_arr__check_valid(raw_map_arr);
	raw_map_arr__fluidfill(raw_map_arr, map_size);
	world__init(world, raw_map_arr, map_size);
	str__delete__arr(&raw_map_arr);
}
