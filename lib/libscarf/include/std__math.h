/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   std__math.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youkim    <youkim@student.42seoul.kr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 10:13:06 by youkim            #+#    #+#             */
/*   Updated: 2022/05/04 10:13:06 by youkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STD__MATH_H
# define STD__MATH_H

# include "std__types__math.h"
# include <stdbool.h>

//@func
/*
** < check_char.c > */

bool	is_upper(char c);
bool	is_lower(char c);
bool	is_alpha(char c);
bool	is_alnum(char c);
bool	is_whitespace(char c);
/*
** < check_num.c > */

bool	is_digit(char c);
bool	is_overflow(int num, int sign);
bool	math__in_range(int num, t_irange range);
/*
** < math.c > */

int		math__max(int a, int b);
int		math__min(int a, int b);
int		math__clamp(int n, const t_irange range);
int		math__digit_len(int num);
int		math__normalize(int num, const t_irange from, const t_irange to);
/*
** < vector.c > */

t_vec	vec__add(const t_vec *v1, const t_vec *v2);
void	vec__add_assign(t_vec *v1, t_vec *v2);
t_vec	vec__rotate(const t_vec *vec, double angle);
void	vec__rotate_assign(t_vec *vec, double angle);
/*
** < vector_mul.c > */

t_vec	vec__mul(const t_vec *vec, double amount);
void	vec__mul_assign(t_vec *vec, double amount);
/*
** < vector_util.c > */

bool	ivec__is_equal(const t_ivec *v1, const t_ivec *v2);
t_ivec	vec__to_ivec(const t_vec *vec);
#endif
