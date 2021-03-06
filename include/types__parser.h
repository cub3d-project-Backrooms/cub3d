/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types__parser.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkim <tkim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 10:13:06 by youkim            #+#    #+#             */
/*   Updated: 2022/06/10 13:35:23 by tkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	MAPFMT__FILL = 'f',
	MAPFMT__DOOR = 'D',
	MAPFMT__DOOR_OPEN = 'O',
	MAPFMT__SPRITE = 'T',
	MAPFMT__ERR = -1,
}	t_mapfmt;

typedef bool(*t_mapformat__validator_f)(t_mapfmt);

typedef struct s_parser
{
	t_fd		fd;
	bool		found_cubid[6];
}	t_parser;

#endif
