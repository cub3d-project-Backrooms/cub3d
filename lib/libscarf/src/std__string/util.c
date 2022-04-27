#include "std__string.h"
#include <stdlib.h>

/**
 * @brief NULL is also considered empty.
 */
bool	str__is_empty(t_const_string this)
{
	return (not this or str__len(this) == 0);
}

void	str__pad_right(t_string *this, t_uint len, char c)
{
	t_string	pad_str;

	pad_str = str__new_char(len, c);
	str__merge(this, &pad_str);
}

void	str__pad_left(t_string *this, t_uint len, char c)
{
	t_string	new;

	new = str__new_char(len, c);
	str__append(&new, *this);
	str__move(this, &new);
}
