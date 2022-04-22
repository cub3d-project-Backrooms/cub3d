#include "types__parser.h"

bool	parser__all_cubid_found(t_parser *this)
{
	int	i;

	i = -1;
	while (++i < 6)
		if (not this->found_cubid[i])
			return (false);
	return (true);
}

bool	parser__has_duplicate_cubid(t_parser *this, t_cubid id)
{
	return (this->found_cubid[id]);
}
