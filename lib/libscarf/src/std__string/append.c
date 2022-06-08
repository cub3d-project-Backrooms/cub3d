/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   append.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youkim    <youkim@student.42seoul.kr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 10:13:06 by youkim            #+#    #+#             */
/*   Updated: 2022/05/04 10:13:06 by youkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "std__string.h"
#include "std__system.h"
#include <stdio.h>

/**
 * @brief same as strcpy. use at your own lisk!
 */
int	str__copy(t_string this, t_const_string src, int size)
{
	int			i;
	const int	src_len = str__len(src);

	if (size < 0)
		size = src_len;
	i = -1;
	while (src[++i] && i < size)
		this[i] = src[i];
	this[i] = '\0';
	return (src_len);
}

/**
 * @brief append a string to another.
 *
 * @param this address to the string that would be modified.
 * @param to_add the constant string reference to add.
 */
int	str__append(t_string *this, t_const_string src)
{
	t_string	new;
	const int	org_len = str__len(*this);
	const int	src_len = str__len(src);
	const int	new_len = org_len + src_len;

	new = std__allocate(new_len, sizeof(char));
	if (!new)
		return (ERR);
	str__copy(new, *this, org_len);
	str__copy(new + org_len, src, src_len);
	str__move(this, &new);
	return (new_len);
}
