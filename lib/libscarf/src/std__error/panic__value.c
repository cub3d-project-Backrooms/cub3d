#include "std__color.h"
#include "std__string.h"
#include "std__system.h"
#include <errno.h>
#include <stdlib.h>
#include <unistd.h>

void	std__panic__value(t_const_string where, t_const_string what)
{
	std__panic_write_internal(
		(t_const_string[]){where, " value error", what, NULL});
	exit(EXIT_FAILURE);
}

void	std__panic__value__char(t_const_string where, char what)
{
	const char	charstr[2] = (const char [2]){what, '\0'};

	std__panic_write_internal(
		(t_const_string[]){where, " value error", charstr, NULL});
	exit(EXIT_FAILURE);
}
