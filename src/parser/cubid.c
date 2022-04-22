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


static void	parser__parse_line__id(t_parser *this, t_string line)
{
	t_cubid		id;
	t_string	*arr;

	if (cubfile__is_line_empty(line))
		return ;
	arr = str__new_split(line, " ");
	if (not (cubid__is_valid(arr)))
		std__panic__value("parser__parse_line__id: invalid line", line);
	str__strip(&arr[1], STD__SPACES);
	id = cubid__parse(arr[0]);
	if (id == CUBID__ERR)
		std__panic__value("parser__parse_line__id: invalid id", arr[0]);
	if (parser__has_duplicate_cubid(this, id))
		std__panic__value("parser__feed_ident: duplicate identifier", line);
	if (cubid__is_color(id))
		this->colors[id - (CUBID__TEXTURE__EAST + 1)]
			= rgb__from_string(arr[1], ",");
	else
		this->texture_path[id] = str__new(arr[1]);
	this->found_cubid[id] = true;
	str__delete__arr(&arr);
}

// static void	parser__init_texture(t_parser *this, t_world *world)
// {

// }

void	parser__parse__id(t_parser *this)
{
	t_string	line;

	while (not parser__all_cubid_found(this))
	{
		line = std__new_readfile__line(this->fd);
		parser__parse_line__id(this, line);
		str__delete(&line);
	}
}
