#include "std__color.h"
#include "std__string.h"
#include "std__system.h"
#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void	std__panic__index__string(t_const_string where,
								t_const_string what,
								int index,
								int size)
{
	t_string	index_str;
	t_string	size_str;

	index_str = str__new_from_int(index);
	size_str = str__new_from_int(size);
	std__panic_write_internal((t_const_string[]){
		where, "while indexing", what, MAG "index out of range" BRED,
		index_str, RED "while available size is" BHYEL, size_str, NULL});
	str__delete(&index_str);
	str__delete(&size_str);
	exit(EXIT_FAILURE);
}

void	std__panic__index(t_const_string where, int attemped_index, int size)
{
	t_string	index_str;
	t_string	size_str;

	index_str = str__new_from_int(attemped_index);
	size_str = str__new_from_int(size);
	std__panic_write_internal(
		(t_const_string[]){where, "index out of bounds", index_str,
		MAG "while available size is" BHYEL, size_str, NULL});
	str__delete(&index_str);
	str__delete(&size_str);
	exit(EXIT_FAILURE);
}
