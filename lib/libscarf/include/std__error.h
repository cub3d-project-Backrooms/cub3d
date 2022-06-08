/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   std__error.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youkim    <youkim@student.42seoul.kr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 10:13:06 by youkim            #+#    #+#             */
/*   Updated: 2022/05/04 10:13:06 by youkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STD__ERROR_H
# define STD__ERROR_H

# include "std__types.h"

//@func
/*
** < panic.c > */

void	std__panic_write_internal(t_const_string arr[]);
void	std__panic__syscall(t_const_string category);
void	std__panic(t_const_string what);
void	std__panic__null(t_const_string where);
/*
** < panic__index.c > */

void	std__panic__index__string(t_const_string where, t_const_string what,
			int index, int size);
void	std__panic__index(t_const_string where, int attemped_index, int size);
/*
** < panic__value.c > */

void	std__panic__value(t_const_string where, t_const_string what);
void	std__panic__value__char(t_const_string where, char what);
#endif
