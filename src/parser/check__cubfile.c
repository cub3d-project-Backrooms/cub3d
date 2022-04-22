#include "std__string.h"

bool	cubfile__is_line_empty(t_string line)
{
	return (str__is_equal(line, "\n"));
}
