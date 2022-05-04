/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youkim    <youkim@student.42seoul.kr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 10:13:06 by youkim            #+#    #+#             */
/*   Updated: 2022/05/04 10:13:06 by youkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "std__system.h"
#include <stdlib.h>

/** @brief sets all value of given memory as c. use std__allocate() instead. */
void	*std__memset(void *ptr, char c, int count)
{
	int		i;
	char	*ptr_curs;

	ptr_curs = (char *)ptr;
	i = -1;
	while (++i < count)
		ptr_curs[i] = c;
	return (ptr);
}

/** @brief  sets all value of given memory as 0. use std__allocate() instead. */
void	*std__bzero(void *ptr, int count)
{
	return (std__memset(ptr, '\0', count));
}

/** @brief copies count bytes from src to dst. */
void	*std__memcpy(void *dst, const void *src, size_t count)
{
	size_t		i;
	t_u8		*dstptr;
	const t_u8	*srcptr;

	if (!dst && !src)
		return (dst);
	srcptr = (t_u8 *)src;
	dstptr = (t_u8 *)dst;
	i = -1;
	while (++i < count)
		dstptr[i] = srcptr[i];
	return (dst);
}
