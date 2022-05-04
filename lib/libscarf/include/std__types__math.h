/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   std__types__math.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youkim    <youkim@student.42seoul.kr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 10:13:06 by youkim            #+#    #+#             */
/*   Updated: 2022/05/04 10:13:06 by youkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STD__TYPES__MATH_H
# define STD__TYPES__MATH_H

# include "std__types.h"

# define INT_MIN_ABS 2147483648
# define STD__PI 3.14159265358979323846

typedef struct s_vec
{
	double	x;
	double	y;
}			t_vec;

typedef struct s_ivec
{
	int		x;
	int		y;
}			t_ivec;

typedef struct s_i64vec
{
	t_i64	x;
	t_i64	y;
}	t_i64vec;

typedef struct s_irange
{
	int		start;
	int		end;
}			t_irange;

typedef struct s_sizevec
{
	t_uint	width;
	t_uint	height;
}			t_sizevec;
#endif
