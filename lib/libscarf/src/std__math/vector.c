/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youkim    <youkim@student.42seoul.kr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 10:13:06 by youkim            #+#    #+#             */
/*   Updated: 2022/05/04 10:13:06 by youkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "std__math.h"
#include <math.h>

t_vec	vec__add(t_vec *v1, t_vec *v2)
{
	return ((t_vec){
		v1->x + v2->x,
		v1->y + v2->y,
	});
}

void	vec__add_assign(t_vec *v1, t_vec *v2)
{
	v1->x += v2->x;
	v1->y += v2->y;
}

t_vec	vec__rotate(t_vec *vec, double angle)
{
	return ((t_vec){
		.x = vec->x * cos(angle) - vec->y * sin(angle),
		.y = vec->x * sin(angle) + vec->y * cos(angle),
	});
}

void	vec__rotate_assign(t_vec *vec, double angle)
{
	const double	x = vec->x * cos(angle) - vec->y * sin(angle);
	const double	y = vec->x * sin(angle) + vec->y * cos(angle);

	vec->x = x;
	vec->y = y;
}

bool	ivec__is_equal(t_ivec *v1, t_ivec *v2)
{
	return (v1->x == v2->x && v1->y == v2->y);
}
