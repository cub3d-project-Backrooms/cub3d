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

t_vec	vec__rotate(const t_vec *vec, double angle)
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

