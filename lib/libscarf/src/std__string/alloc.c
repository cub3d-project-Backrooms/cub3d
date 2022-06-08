/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alloc.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youkim    <youkim@student.42seoul.kr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 10:13:06 by youkim            #+#    #+#             */
/*   Updated: 2022/05/04 10:13:06 by youkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "std__string.h"
#include "std__system.h"
#include <stdlib.h>

/**
 * @brief create a new string from a given string.
 *
 * @param from
 * @return t_string
 */
t_string	str__new(t_const_string from)
{
	t_i32		i;
	t_string	new;
	const t_i32	len = str__len(from);

	new = str__new_size(len);
	i = -1;
	while (++i < len)
		new[i] = from[i];
	return (new);
}

/**
 * @brief create a new string by moving other. other is freed.
 *
 * @param this
 * @param other
 */
t_string	str__new_move(t_string *other)
{
	t_string	new;

	new = str__new(*other);
	str__delete(other);
	return (new);
}

/**
 * @brief create a uninitialized string of given length.
 *
 * @param size
 * @return t_string
 */
t_string	str__new_size(t_uint size)
{
	t_string	new;

	new = std__calloc(size, sizeof(char));
	return (new);
}

t_string	str__new_char(t_uint size, char c)
{
	t_i64		i;
	t_string	new;

	new = str__new_size(size);
	i = -1;
	while (++i < size)
		new[i] = c;
	return (new);
}

t_string_arr	str__new__arr(t_uint size, t_string from[])
{
	t_i64			i;
	t_string_arr	new_arr;

	new_arr = std__calloc(size, sizeof(t_string));
	i = -1;
	while (++i < size)
		new_arr[i] = str__new(from[i]);
	return (new_arr);
}
