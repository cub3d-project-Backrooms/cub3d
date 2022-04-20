#ifndef PARSER_H
# define PARSER_H

# include "types__parser.h"

//@func
/*
** < rgb.c > */

void	rgb__print(t_rgb rgb);
t_rgb	rgb__from_arr(int raw_rgb[3]);
t_rgb	rgb__from_string(t_const_string str, t_const_string delim);
/*
** < texture.c > */

void	parser__init(t_parser *this, t_const_string path);
#endif
