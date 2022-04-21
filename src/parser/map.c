#include <stdio.h>
#include "parser.h"
#include "std__system.h"
#include "std__string.h"
// static int	longest_map_length(t_string raw_map_arr[])
// {
// 	int	i;

// 	i = -1;
// 	while (raw_map_arr[++i])
// 	{

// 	}
// }

static t_string	*parser__new_raw_map_arr(t_parser *this)
{
	int			i;
	bool		is_start;
	t_string	line;
	t_string	raw_mapline;
	t_string	*raw_map_arr;

	is_start = false;
	raw_mapline = str__new_size(0);
	while (true)
	{
		line = std__new_readfile__line(this->fd);
		if (line == NULL)
			break ;
		if (cubfile__is_line_empty(line))
		{
			if (is_start)
				std__panic("parser__new_raw_map_arr: empty map line");
			is_start = true;
			continue ;
		}
		str__merge(&raw_mapline, &line);
	}
	str__rstrip(&raw_mapline, "\n");
	raw_map_arr = str__new_split(raw_mapline, "\n");
	i = -1;
	while (raw_map_arr[++i])
		str__rstrip(&raw_map_arr[i], "\n");
	str__delete(&raw_mapline);
	return (raw_map_arr);
}

void	parser__parse__map(t_parser *this)
{
	parser__new_raw_map_arr(this);
}
