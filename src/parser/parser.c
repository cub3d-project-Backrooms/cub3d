#include <fcntl.h>
#include <stdio.h>
#include "parser.h"
#include "types__renderer.h"
#include "std__system.h"
#include "std__color.h"

/**
 * @brief check if a string ends with another string. e.g. an extension.
 *
 * example) ab.cd ends with cd?
 * str__find("ab.cd", "cd") == 3, 5 - 2 = 3, so it's true.
 */
static bool	str__ends_with(t_const_string this, t_const_string other)
{
	const int	this_len = str__len(this);
	const int	other_len = str__len(other);
	const int	at = str__find(this, other);

	return (at != ERR and at == this_len - other_len);
}

void	parser__init(t_parser *this, t_const_string file)
{
	int			i;

	i = -1;
	while (++i < 6)
		this->found_cubid[i] = false;
	if (not str__ends_with(file, ".cub"))
		std__panic__value("parser__init", "file must end with .cub");
	this->fd = std__open(file, O_RDONLY);
}

void	parser__parse(t_parser *this, t_world *world)
{
	parser__parse__id(this, world);
	parser__parse__map(this, world);
}
