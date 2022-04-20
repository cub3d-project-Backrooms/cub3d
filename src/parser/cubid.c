#include "std__string.h"
#include "parser.h"
#include <stdio.h>
#include "std__color.h"

t_cubid	cubid__parse(t_const_string id)
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

bool	parser__all_cubid_found(t_parser *this)
{
	int	i;

	i = -1;
	while (++i < 6)
		if (not this->found_cubid[i])
			return (false);
	return (true);
}

bool	parser__has_duplicate_cubid(t_parser *this, t_cubid id)
{
	return (this->found_cubid[id]);
}

void	parser__parse_line__id(t_parser *this, t_string line)
{
	t_cubid		id;
	t_string	*arr;

	if (str__is_equal(line, "\n"))
		return ;
	arr = str__new_split(line, " ");
	if (arr == NULL or str__len__arr(arr) != 2)
		std__panic__value("parser__parse_line__id: invalid line", line);
	str__strip(&arr[1], STD__SPACES);
	id = cubid__parse(arr[0]);
	if (id == CUBID__ERR)
		std__panic__value("parser__parse_line__id: invalid id", arr[0]);
	if (parser__has_duplicate_cubid(this, id))
		std__panic__value("parser__feed_ident: duplicate identifier", line);
	if (id == CUBID__COLOR__FLOOR or id == CUBID__COLOR__CEILING)
		this->colors[id - (CUBID__TEXTURE__EAST + 1)]
			= rgb__from_string(arr[1], ",");
	else
		this->textures[id] = str__new(arr[1]);
	this->found_cubid[id] = true;
}
