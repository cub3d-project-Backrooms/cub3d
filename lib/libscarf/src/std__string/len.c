/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   len.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youkim    <youkim@student.42seoul.kr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 10:13:06 by youkim            #+#    #+#             */
/*   Updated: 2022/05/04 10:13:06 by youkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "std__string.h"

/**
 * @brief length of a string.
 *
 * @param this the string to get the length of.
 * @return ERR (-1) if the string is NULL, the length of the string otherwise.
 */
t_int_or_neg_as_err	str__len(t_const_string this)
{
	int	i;

	if (!this)
		return (ERR);
	i = 0;
	while (this[i])
		i++;
	return (i);
}

t_int_or_neg_as_err	str__len__arr(t_string arr[])
{
	int	i;

	if (!arr)
		return (ERR);
	i = 0;
	while (arr[i])
		i++;
	return (i);
}
