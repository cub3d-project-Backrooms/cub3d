#include "parser.h"
#include "std__math.h"
#include "std__string.h"
#include "std__system.h"

int	raw_map_arr__max_width(t_string_arr this)
{
	int	i;
	int	max_len;

	i = -1;
	max_len = UNSET;
	while (this[++i])
		max_len = math__max(str__len(this[i]), max_len);
	return (max_len);
}

t_string	parser__new_raw_map_line(t_parser *this)
{
	t_string	line;
	bool		is_start;
	t_string	raw_mapline;

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
	return (raw_mapline);
}

t_string_arr	parser__new_raw_map_arr(t_parser *this)
{
	int			i;
	t_string	raw_mapline;
	t_string	*raw_map_arr;

	raw_mapline = parser__new_raw_map_line(this);
	raw_map_arr = str__new_split(raw_mapline, "\n");
	i = -1;
	while (raw_map_arr[++i])
		str__rstrip(&raw_map_arr[i], "\n");
	str__delete(&raw_mapline);
	return (raw_map_arr);
}

void	raw_map_arr__pad(t_string_arr this, t_sizevec map_size)
{
	t_i64	i;
	t_i64	len;

	i = -1;
	while (++i < map_size.height)
	{
		len = str__len(this[i]);
		if (len < map_size.width)
			str__pad_right(&this[i], map_size.width - len, ' ');
	}
}
