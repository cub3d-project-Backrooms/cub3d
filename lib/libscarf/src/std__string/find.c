/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youkim    <youkim@student.42seoul.kr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 10:13:06 by youkim            #+#    #+#             */
/*   Updated: 2022/05/04 10:13:06 by youkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "std__string.h"

/**
 * @brief find the first occurence of a string.
 * str__find("abcde", "de") would return 3.
 * @param this the string to search in.
 * @param other the sequence to search for.
 * @return index of string if found, ERR (-1) if not found
 */
t_int_or_neg_as_err	str__find(t_const_string this, t_const_string other)
{
	return (str__find_from(this, other, 0));
}

t_int_or_neg_as_err	str__find_from(t_const_string this,
									t_const_string other,
									t_i64 from)
{
	t_i64		i;
	const int	this_len = str__len(this);
	const int	other_len = str__len(other);

	if (other_len == ERR || other_len == 0)
		return (other_len);
	i = from - 1;
	while (++i <= this_len - other_len)
		if (str__ncmp(this + i, other, other_len) == 0)
			return (i);
	return (ERR);
}
