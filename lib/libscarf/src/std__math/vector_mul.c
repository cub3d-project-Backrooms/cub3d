/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_mul.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkim <tkim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 16:59:56 by tkim              #+#    #+#             */
/*   Updated: 2022/06/12 16:59:58 by tkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "std__math.h"

t_vec	vec__mul(const t_vec *vec, double amount)
{
	return ((t_vec){
		.x = vec->x * amount,
		.y = vec->y * amount
	});
}

void	vec__mul_assign(t_vec *vec, double amount)
{
	vec->x *= amount;
	vec->y *= amount;
}
