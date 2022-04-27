#include "std__error.h"
#include "std__string.h"
#include <stdio.h>

/** @brief	python-like indexing. crash if the index is out of bounds.
 *  @param	this	the string to index.
 *  @param	index	the index to index. can be negative.
 *  @return	the character at the index.
 */
t_u8	str__at(t_const_string this, const int index)
{
	const int	len = str__len(this);

	if (index >= 0)
	{
		if (index >= len)
			std__panic__index__string("str__at", this, index, len);
		return (this[index]);
	}
	else
	{
		if (-index > len)
			std__panic__index__string("str__at", this, index, len);
		return (this[len + index]);
	}
}

bool	str__is_in(t_const_string this, char c)
{
	t_uint	i;

	i = -1;
	while (this[++i])
		if (this[i] == c)
			return (true);
	return (false);
}
