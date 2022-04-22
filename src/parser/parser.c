#include <fcntl.h>
#include <stdio.h>
#include "parser.h"
#include "types__renderer.h"
#include "std__system.h"
#include "std__color.h"

void	parser__init(t_parser *this, t_const_string file)
{
	int			i;

	i = -1;
	while (++i < 6)
		this->found_cubid[i] = false;
	this->fd = std__open(file, O_RDONLY);
}

t_world	parser__parse(t_parser *this)
{
	t_world		world;

	parser__parse__id(this);
	parser__parse__map(this, &world);
	return (world);
}
