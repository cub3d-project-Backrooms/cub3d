/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check__cubid.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youkim    <youkim@student.42seoul.kr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 10:13:06 by youkim            #+#    #+#             */
/*   Updated: 2022/05/04 10:13:06 by youkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "types__parser.h"

bool	cubid__is_valid(t_string arr[])
{
	return (arr && str__len__arr(arr) == 2);
}

bool	cubid__is_color(t_cubid id)
{
	return (id == CUBID__COLOR__FLOOR || id == CUBID__COLOR__CEILING);
}

bool	cubid__is_texture(t_cubid id)
{
	return (CUBID__TEXTURE__NORTH <= id && id <= CUBID__TEXTURE__EAST);
}
