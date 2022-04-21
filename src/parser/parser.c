#include <fcntl.h>
#include <stdio.h>
#include "parser.h"
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

void	parser__parse(t_parser *this)
{

	parser__parse__id(this);
	for (int i = 0; i < 4; i++)
		printf("tex path: %s\n", this->texture_path[i]);
	parser__parse__map(this);
}
