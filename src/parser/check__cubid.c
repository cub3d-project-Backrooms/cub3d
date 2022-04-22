#include "types__parser.h"

bool	cubid__is_valid(t_string arr[])
{
	return (arr and str__len__arr(arr) == 2);
}

bool	cubid__is_color(t_cubid id)
{
	return (id == CUBID__COLOR__FLOOR or id == CUBID__COLOR__CEILING);
}

bool	cubid__is_texture(t_cubid id)
{
	return (CUBID__TEXTURE__NORTH <= id and id <= CUBID__TEXTURE__EAST);
}

