#include "std__string.h"

void	str__lstrip(t_string *this, t_const_string charset)
{
	const int	at = str__find_first_not_of(*this, charset);

	if (at != ERR)
		str__replace(this, str__new_substr(*this, at, -1));
}

void	str__rstrip(t_string *this, t_const_string charset)
{
	const int	at = str__find_last_not_of(*this, charset);

	if (at != ERR)
		str__replace(this, str__new_substr(*this, 0, at + 1));
}

void	str__strip(t_string *this, t_const_string charset)
{
	str__lstrip(this, charset);
	str__rstrip(this, charset);
}
