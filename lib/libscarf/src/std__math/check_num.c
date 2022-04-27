#include <stdbool.h>
#include "std__types__math.h"

bool	is_digit(char c)
{
	return ('0' <= c && c <= '9');
}

bool	is_overflow(int num, int sign)
{
	return ((sign == -1 && num > 0) || (sign == 1 && num < 0));
}

bool	math__in_range(int num, t_irange range)
{
	return (range.start <= num && num <= range.end);
}
