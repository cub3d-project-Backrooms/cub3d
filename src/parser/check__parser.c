/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check__parser.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youkim    <youkim@student.42seoul.kr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 10:13:06 by youkim            #+#    #+#             */
/*   Updated: 2022/05/04 10:13:06 by youkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "types__parser.h"

bool	parser__all_cubid_found(t_parser *this)
{
	int	i;

	i = -1;
	while (++i < 6)
		if (!this->found_cubid[i])
			return (false);
	return (true);
}

bool	parser__has_duplicate_cubid(t_parser *this, t_cubid id)
{
	return (this->found_cubid[id]);
}
