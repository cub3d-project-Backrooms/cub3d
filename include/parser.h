#ifndef PARSER_H
# define PARSER_H

# include "types__parser.h"

//@func
/*
** < check__cubfile.c > */

bool	cubfile__is_line_empty(t_string line);
/*
** < check__cubid.c > */

bool	cubid__is_valid(t_string arr[]);
bool	cubid__is_color(t_cubid id);
bool	cubid__is_texture(t_cubid id);
/*
** < check__map.c > */

bool	mapformat__is_valid(t_mapformat this);
void	mapformat__assert_valid(t_mapformat this);
void	raw_map_arr__check_valid(t_string_arr this);
/*
** < check__parser.c > */

bool	parser__all_cubid_found(t_parser *this);
bool	parser__has_duplicate_cubid(t_parser *this, t_cubid id);
/*
** < cubid.c > */

void	parser__parse__id(t_parser *this);
/*
** < map.c > */

void	parser__parse__map(t_parser *this);
/*
** < parser.c > */

void	parser__init(t_parser *this, t_const_string file);
void	parser__parse(t_parser *this);
/*
** < rgb.c > */

void	rgb__print(t_rgb rgb);
t_rgb	rgb__from_arr(int raw_rgb[3]);
t_rgb	rgb__from_string(t_const_string str, t_const_string delim);
#endif
