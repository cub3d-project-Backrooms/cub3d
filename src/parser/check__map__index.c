/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check__map__index.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youkim    <youkim@student.42seoul.kr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 10:13:06 by youkim            #+#    #+#             */
/*   Updated: 2022/05/04 10:13:06 by youkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "std__math.h"

bool	is_first_row(t_ivec pos)
{
	return (pos.y == 0);
}

bool	is_last_row(t_ivec pos, t_sizevec map_size)
{
	return ((t_uint)pos.y == map_size.height - 1);
}

bool	is_first_column(t_ivec pos)
{
	return (pos.x == 0);
}

bool	is_last_column(t_ivec pos, t_sizevec map_size)
{
	return ((t_uint)pos.x == map_size.width - 1);
}
