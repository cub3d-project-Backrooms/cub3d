/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youkim    <youkim@student.42seoul.kr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 10:13:06 by youkim            #+#    #+#             */
/*   Updated: 2022/05/04 10:13:06 by youkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "std__string.h"

/** @brief Compare two strings.
 * 			use str__is_equal() instead for full length comparison.
 *  @return n1 - n2 of first non-matching char || 0 (leached end) */
int	str__ncmp(t_const_string s1, t_const_string s2, int n)
{
	int		i;
	t_u8	n1;
	t_u8	n2;

	i = -1;
	while (++i < n)
	{
		n1 = (t_u8)s1[i];
		n2 = (t_u8)s2[i];
		if (n1 != n2)
			return (n1 - n2);
		if (!n1 || !n2)
			break ;
	}
	return (0);
}

/** @return true if value of s1 && s2 are same. */
bool	str__is_equal(t_const_string s1, t_const_string s2)
{
	const int	s1_len = str__len(s1);
	const int	s2_len = str__len(s2);

	return (s1_len == s2_len && str__ncmp(s1, s2, s1_len) == 0);
}
