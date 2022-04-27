#include "std__string.h"
#include "std__system.h"
#include <stdlib.h>

/**
 * @brief deletes a string and set it to NULL.
 *
 * @param this the string to delete.
 */
void	str__delete(t_string *this)
{
	std__dealloc((void **)this);
}

void	str__delete__arr(t_string_arr *arr_ptr)
{
	int			i;

	i = -1;
	while ((*arr_ptr)[++i])
		str__delete(&(*arr_ptr)[i]);
	std__dealloc((void **)arr_ptr);
}
