#include "std__math.h"
#include "std__color.h"
#include "std__string.h"
#include "parser.h"
#include <stdio.h>

t_ivec fluidfill__start_pos(t_string_arr this)
{
	t_ivec it;
	t_mapformat tile;

	it.y = -1;
	while (this[++it.y])
	{
		it.x = -1;
		while (this[it.y][++it.x])
		{
			tile = this[it.y][it.x];
			if (tile != MAPFMT__WALL && tile != MAPFMT__EMPTY && tile != MAPFMT__FILL)
				return (it);
		}
	}
	return (t_ivec){-100, -100};
}

void fluidfill__recursive(t_string_arr this, t_ivec node)
{
	t_mapformat tile;

//	printf("Searching (%d, %d)\n", node.x, node.y);
	if (node.x < 0 || node.y < 0 || !this[node.y] || !this[node.y][node.x])
		std__panic("Invalid map");
	tile = this[node.y][node.x];
	if (tile == MAPFMT__EMPTY || tile == MAPFMT__ERR)
		std__panic("Invalid map");
	if (tile == MAPFMT__FILL)
		return ;
	if (tile == MAPFMT__WALL)
		return ;
	this[node.y][node.x] = MAPFMT__FILL;
	fluidfill__recursive(this, (t_ivec){node.x + 1, node.y});
	fluidfill__recursive(this, (t_ivec){node.x - 1, node.y});
	fluidfill__recursive(this, (t_ivec){node.x, node.y + 1});
	fluidfill__recursive(this, (t_ivec){node.x, node.y - 1});
	fluidfill__recursive(this, (t_ivec){node.x + 1, node.y + 1});
	fluidfill__recursive(this, (t_ivec){node.x + 1, node.y - 1});
	fluidfill__recursive(this, (t_ivec){node.x - 1, node.y + 1});
	fluidfill__recursive(this, (t_ivec){node.x - 1, node.y - 1});
}

bool raw_map_arr__fluidfill(t_string_arr this, t_sizevec map_size)
{
	t_ivec start;
	t_string_arr tmp;

	printf("%sfluidfill algorithm is checking map validation ...%s\n", CYN, END);
	tmp = str__new__arr(map_size.height, this);
	while (true)
	{
		start = fluidfill__start_pos(tmp);
		if (start.x < 0)
			break ;
		fluidfill__recursive(tmp, start);
	}
	str__delete__arr(&tmp);
	return (true);
}
