#ifndef TYPES__PARSER_H
# define TYPES__PARSER_H

# include "std__string.h"

typedef enum e_cubformat
{
	CUBFMT__TEXTURE__NORTH,
	CUBFMT__TEXTURE__SOUTH,
	CUBFMT__TEXTURE__EAST,
	CUBFMT__TEXTURE__WEST,
	CUBFMT__TEXTURE__FLOOR,
	CUBFMT__TEXTURE__CEILING,
	CUBFMT__COLOR__FLOOR,
	CUBFMT__COLOR__CEILING,
	CUBFMT__GRID,
}	t_cubformat;

typedef struct s_parser
{
	t_fd		fd;
	t_string	path;
	t_string	textures[6];
}	t_parser;

#endif
