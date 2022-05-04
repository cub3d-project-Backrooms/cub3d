#include "std__math.h"
#include "std__system.h"
#include "std__string.h"

/**
 * @brief read from fd, append the result to a string.
 *        always succeeds. panics on error.
 * @return length of characters read.
 */
static int	str__append_from_read(t_string *this, t_fd fd, bool *done)
{
	int		len;
	char	buffer[BUFFER_SIZE + 1];

	len = std__read(fd, buffer, BUFFER_SIZE);
	if (len == ERR)
		std__panic__syscall("read");
	else if (len > 0)
		str__append(this, buffer);
	if (read__is_eof(len))
		*done = true;
	return (len);
}

static t_string	str__new_take_away_from_front(
	t_string *this, t_uint len)
{
	t_string	new;

	new = str__new_substr(*this, 0, len);
	str__replace(this, str__new_substr(*this, len, -1));
	return (new);
}

t_string	std__new_readfile__line(t_fd fd)
{
	t_ivec			at;
	static bool		done[OPEN_MAX];
	static t_string	cache[OPEN_MAX];

	if (fd < 0 || fd >= OPEN_MAX)
		return (NULL);
	if (!done[fd] && !cache[fd])
		cache[fd] = str__new_size(0);
	while (!done[fd])
	{
		at.x = str__find(cache[fd], "\n");
		if (at.x == ERR)
			at.y = str__append_from_read(&cache[fd], fd, &done[fd]);
		else
			return (str__new_take_away_from_front(&cache[fd], at.x + 1));
	}
	if (!str__is_empty(cache[fd]))
		return (str__new_move(&cache[fd]));
	if (cache[fd])
		str__delete(&cache[fd]);
	return (NULL);
}
