/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
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
 * @brief count the number of occurences of a sequence in a string.
 *
 * "hello world" " " -> 1
 * "hello world" "l" -> 3
 * "hello world" "ll" -> 1
 *
 * @param str
 * @param delim
 * @return t_int_or_neg_as_err
 */
t_int_or_neg_as_err	str__count_of(t_const_string str, t_const_string other)
{
	int					i;
	int					find_result;
	const int			str_len = str__len(str);
	const int			other_len = str__len(other);
	t_int_or_neg_as_err	count;

	if (other_len == ERR || str_len == ERR)
		return (ERR);
	if (other_len == 0)
		std__panic__value("str__count_of", "string to match is zero witdh");
	i = 0;
	count = 0;
	while (true)
	{
		find_result = str__find_from(str, other, i);
		if (find_result == ERR)
			return (count);
		else
		{
			count++;
			i = find_result + other_len;
		}
	}
}

/**
 * @brief split string by deliminating string.
 *
 * "hello world" " " -> ["hello", "world"]
 * "hello world" "l" -> ["he", "o wor", "d"]
 * "hello world" "ell" -> ["h", "o world"]
 *
 * @param str
 * @param delim
 * @return array of t_string, NULL terminated. copy of itself if no match.
 */
t_string	*str__new_split(t_const_string str, t_const_string delim)
{
	int			start;
	int			end;
	t_string	*arr;
	int			arr_i;

	if (!delim)
		std__panic__null("str__split");
	if (str__len(delim) == 0)
		std__panic__value("str__split", "empty separator");
	arr_i = -1;
	arr = std__allocate(str__count_of(str, delim) + 1, sizeof(t_string));
	start = 0;
	end = str__find(str, delim);
	while (end != ERR)
	{
		arr[++arr_i] = str__new_substr(str, start, end - start);
		start = end + str__len(delim);
		end = str__find_from(str, delim, start);
	}
	arr[++arr_i] = str__new_substr(str, start, -1);
	return (arr);
}
