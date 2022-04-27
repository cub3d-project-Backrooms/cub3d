#include "std__math.h"
#include "std__string.h"

bool	is_upper(char c)
{
	return ('A' <= c && c <= 'Z');
}

bool	is_lower(char c)
{
	return ('a' <= c && c <= 'z');
}

bool	is_alpha(char c)
{
	return (is_upper(c) || is_lower(c));
}

bool	is_alnum(char c)
{
	return (is_alpha(c) || is_digit(c));
}

bool	is_whitespace(char c)
{
	return (str__is_in(STD__SPACES, c));
}
