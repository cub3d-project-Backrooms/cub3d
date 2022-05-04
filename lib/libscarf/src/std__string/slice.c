/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   slice.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youkim    <youkim@student.42seoul.kr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 10:13:06 by youkim            #+#    #+#             */
/*   Updated: 2022/05/04 10:13:06 by youkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "std__string.h"
#include <stdio.h>
#include <stdlib.h>

t_string	str__new_substr(t_const_string this,
							t_uint start,
							t_int_or_neg_as_flag len)
{
	t_string	new;
	const int	str_len = str__len(this);

	if (len == NEG_AS_FLAG__UNLIMITED)
		return (str__new(this + start));
	if (start >= (t_uint)str_len)
		std__panic__index__string("str__new_substr", "start >= str_len",
			start, str_len);
	new = str__new_size(len);
	str__copy(new, this + start, len);
	return (new);
}
