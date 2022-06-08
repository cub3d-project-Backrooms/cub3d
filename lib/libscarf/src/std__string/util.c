/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youkim <youkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 10:13:06 by youkim            #+#    #+#             */
/*   Updated: 2022/05/04 15:06:35 by youkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "std__string.h"
#include <stdlib.h>

/**
 * @brief NULL is also considered empty.
 */
bool	str__is_empty(t_const_string this)
{
	return (!this || str__len(this) == 0);
}

void	str__pad_right(t_string *this, t_uint len, char c)
{
	t_string	pad_str;

	pad_str = str__new_char(len, c);
	str__merge(this, &pad_str);
}

void	str__pad_left(t_string *this, t_uint len, char c)
{
	t_string	new;

	new = str__new_char(len, c);
	str__append(&new, *this);
	str__move(this, &new);
}

/**
 * @brief check if a string ends with another string. e.g. an extension.
 *
 * example) ab.cd ends with cd?
 * str__find("ab.cd", "cd") == 3, 5 - 2 = 3, so it's true.
 */
bool	str__ends_with(t_const_string this, t_const_string other)
{
	const int	this_len = str__len(this);
	const int	other_len = str__len(other);
	const int	at = str__find(this, other);

	return (at != ERR && at == this_len - other_len);
}
