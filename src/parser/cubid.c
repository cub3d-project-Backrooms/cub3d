/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cubid.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youkim    <youkim@student.42seoul.kr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 10:13:06 by youkim            #+#    #+#             */
/*   Updated: 2022/05/04 10:13:06 by youkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "parser.h"
#include "std__string.h"
#include "std__color.h"
#include "std__system.h"

static t_cubid	cubid__parse(t_const_string id)
{
	int						i;
	static t_const_string	ids[] = {
		"NO", "SO", "WE", "EA", "F", "C"};

	i = -1;
	while (++i < 6)
		if (str__is_equal(id, ids[i]))
			return ((t_cubid)i);
	std__panic__value("parser__parse_identifier", "invalid identifier");
	return (CUBID__ERR);
}

static void	split_id_data(t_string line, t_string arr[2])
{
	const int	at = str__find(line, " ");

	if (at == ERR)
		std__panic__value("parser__parse_line__id: invalid line", line);
	arr[0] = str__new_substr(line, 0, at);
	arr[1] = str__new_substr(line, at + 1, -1);
	str__strip(&arr[0], STD__SPACES);
	str__strip(&arr[1], STD__SPACES);
}

static void	parser__parse_line__id(
	t_parser *this, t_world *world, t_string line)
{
	t_cubid		id;
	t_string	arr[2];

	if (cubfile__is_line_empty(line))
		return ;
	split_id_data(line, arr);
	id = cubid__parse(arr[0]);
	if (id == CUBID__ERR)
		std__panic__value("parser__parse_line__id: invalid id", arr[0]);
	if (parser__has_duplicate_cubid(this, id))
		std__panic__value("parser__feed_ident: duplicate identifier", line);
	if (cubid__is_color(id))
		world->colors[id - (CUBID__TEXTURE__EAST + 1)]
			= rgb__from_string(arr[1], ",");
	else
		world->texture_path[id] = str__new(arr[1]);
	this->found_cubid[id] = true;
	str__delete(&arr[0]);
	str__delete(&arr[1]);
}

void	parser__parse__id(t_parser *this, t_world *world)
{
	t_string	line;

	while (!parser__all_cubid_found(this))
	{
		line = std__new_readfile__line(this->fd);
		parser__parse_line__id(this, world, line);
		str__delete(&line);
	}
}
