/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_of.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youkim    <youkim@student.42seoul.kr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 10:13:06 by youkim            #+#    #+#             */
/*   Updated: 2022/05/04 10:13:06 by youkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "std__string.h"

/**
 * @brief find the first occurence of any chars in a character set.
 * c implementation of string::find_first_of in c++.
 * more at https://www.cplusplus.com/reference/string/string/find_first_of/
 * @param this
 * @param charset the character set to search for. if abcd,
 * then the string will be searched for any of first occurance of a, b, c, d.
 * @return index of string if found, ERR (-1) if not found
 */
t_int_or_neg_as_err	str__find_first_of(t_const_string this,
										t_const_string charset)
{
	int	i;

	if (!charset)
		return (ERR);
	i = -1;
	while (this[++i])
		if (str__is_in(charset, this[i]))
			return (i);
	return (ERR);
}

/**
 * @brief find the first occurence of any chars not in a character set.
 * c implementation of string::find_first_not_of in c++.
 * more at https://www.cplusplus.com/reference/string/string/find_first_not_of/
 * @param this
 * @param charset
 * @return index of string if found, ERR (-1) if not found
 */
t_int_or_neg_as_err	str__find_first_not_of(t_const_string this,
											t_const_string charset)
{
	int	i;

	if (!charset)
		return (ERR);
	i = -1;
	while (this[++i])
		if (!str__is_in(charset, this[i]))
			return (i);
	return (ERR);
}

/**
 * @brief find the last occurence of any chars in a character set.
 * c implementation of string::find_first_not_of in c++.
 * more at https://www.cplusplus.com/reference/string/string/find_last_of/
 * @param this
 * @param charset
 * @return index of string if found, ERR (-1) if not found
 */
t_int_or_neg_as_err	str__find_last_of(t_const_string this,
										t_const_string charset)
{
	int			i;
	const int	len = str__len(this);

	if (!charset || len == ERR)
		return (ERR);
	i = len;
	while (--i >= 0)
		if (str__is_in(charset, this[i]))
			return (i);
	return (ERR);
}

/**
 * @brief find the last occurence of any chars not in a character set.
 * c implementation of string::find_first_not_of in c++.
 * more at https://www.cplusplus.com/reference/string/string/find_last_not_of/
 * @param this
 * @param charset
 * @return index of string if found, ERR (-1) if not found
 */
t_int_or_neg_as_err	str__find_last_not_of(t_const_string this,
											t_const_string charset)
{
	int			i;
	const int	len = str__len(this);

	if (!charset || len == ERR)
		return (ERR);
	i = len;
	while (--i >= 0)
		if (!str__is_in(charset, this[i]))
			return (i);
	return (ERR);
}
