/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
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
 * @brief free this, move other -> this, make other's address NULL
 */
void	str__move(t_string *this, t_string *other)
{
	str__replace(this, *other);
	*other = NULL;
}

/**
 * @brief free this && replace with address of other.
 *        used to swap 'this' with temporary objects.
 *
 * @param other address to replace.
 */
void	str__replace(t_string *this, t_string other)
{
	free(*this);
	*this = other;
}

void	str__merge(t_string *this, t_string *other)
{
	str__append(this, *other);
	str__delete(other);
}

void	str__swap(t_string *this, t_string *other)
{
	t_string	tmp;

	tmp = *this;
	*this = *other;
	*other = tmp;
}
