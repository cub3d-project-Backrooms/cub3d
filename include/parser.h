#ifndef PARSER_H
# define PARSER_H

# include "types__parser.h"
# include "types__renderer.h"
# include "std__types__math.h"

//@func
/*
** < check__cubfile.c > */

bool			cubfile__is_line_empty(t_string line);
/*
** < check__cubid.c > */

bool			cubid__is_valid(t_string arr[]);
bool			cubid__is_color(t_cubid id);
bool			cubid__is_texture(t_cubid id);
/*
** < check__map.c > */

bool			mapformat__is_player(t_mapformat this);
bool			mapformat__is_valid(t_mapformat this);
void			mapformat__assert_valid(t_mapformat this);
void			raw_map_arr__check_valid(t_string_arr this);
/*
** < check__map__index.c > */

bool			is_first_row(t_ivec pos);
bool			is_last_row(t_ivec pos, t_sizevec map_size);
bool			is_first_column(t_ivec pos);
bool			is_last_column(t_ivec pos, t_sizevec map_size);
/*
** < check__parser.c > */

bool			parser__all_cubid_found(t_parser *this);
bool			parser__has_duplicate_cubid(t_parser *this, t_cubid id);
/*
** < cubid.c > */

void			parser__parse__id(t_parser *this);
/*
** < map.c > */

void			parser__parse__map(t_parser *this, t_world *world);
/*
** < map__raw.c > */

int				raw_map_arr__max_width(t_string_arr this);
t_string		parser__new_raw_map_line(t_parser *this);
t_string_arr	parser__new_raw_map_arr(t_parser *this);
void			raw_map_arr__pad(t_string_arr this, t_sizevec map_size);
/*
** < parser.c > */

void			parser__init(t_parser *this, t_const_string file);
t_world			parser__parse(t_parser *this);
/*
** < rgb.c > */

void			rgb__print(t_rgb rgb);
t_rgb			rgb__from_arr(int raw_rgb[3]);
t_rgb			rgb__from_string(t_const_string str, t_const_string delim);
#endif
