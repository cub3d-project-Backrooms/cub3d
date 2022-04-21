#ifndef TYPES__PARSER_H
# define TYPES__PARSER_H

# include "std__string.h"

typedef enum e_cubid
{
	CUBID__TEXTURE__NORTH,
	CUBID__TEXTURE__SOUTH,
	CUBID__TEXTURE__WEST,
	CUBID__TEXTURE__EAST,
	CUBID__COLOR__FLOOR,
	CUBID__COLOR__CEILING,
	CUBID__ERR = -1,
}	t_cubid;

typedef enum e_mapformat
{
	MAPFMT__FLOOR = '0',
	MAPFMT__WALL = '1',
	MAPFMT__NORTH = 'N',
	MAPFMT__SOUTH = 'S',
	MAPFMT__WEST = 'W',
	MAPFMT__EAST = 'E',
	MAPFMT__EMPTY = ' ',
	MAPFMT__ERR = -1,
}	t_mapformat;

typedef struct s_parser
{
	t_fd		fd;
	t_string	texture_path[4];
	t_rgb		colors[2];
	bool		found_cubid[6];
}	t_parser;

#endif
