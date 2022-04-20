#include <fcntl.h>
#include "std__string.h"
#include "std__system.h"
#include "parser.h"
#include <stdio.h>
#include "std__color.h"

void	parser__init(t_parser *this, t_const_string file)
{
	int			i;

	i = -1;
	while (++i < 6)
		this->found_cubid[i] = false;
	this->fd = std__open(file, O_RDONLY);
}

void	parser__parse(t_parser *this)
{
	t_string	line;

	while (not parser__all_cubid_found(this))
	{
		line = std__new_readfile__line(this->fd);
		parser__parse_line__id(this, line);
		printf(CYN "%d,%d,%d,%d,%d,%d\n" END, this->found_cubid[0], this->found_cubid[1], this->found_cubid[2], this->found_cubid[3], this->found_cubid[4], this->found_cubid[5]);
		str__delete(&line);
	}
	// this->raw_mapdata = str__new_size(0);
	// while (true)
	// {
	// 	line = std__new_readfile__line(this->fd);
	// 	if (line == NULL)
	// 		break ;
	// 	str__move(&this->raw_mapdata, line);
	// }
}
