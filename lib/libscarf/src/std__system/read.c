#include <fcntl.h>
#include <unistd.h>
#include "std__system.h"
#include "std__string.h"

/**
 * @brief same as read but last byte is NULL terminated.
 *
 * @param fd file descriptor to read from
 * @param buffer buffer to read into. Must be at least size+1 bytes long.
 * @param size number of bytes to read.
 * @return int
 */
int	std__read(t_fd fd, char *buffer, t_uint size)
{
	int	len;

	len = read(fd, buffer, size);
	if (len > 0)
		buffer[len] = '\0';
	return (len);
}

bool	read__is_eof(int len)
{
	return (len == 0);
}

t_fd	std__open(t_const_string path, int flags)
{
	const t_fd	fd = open(path, flags);

	if (fd == ERR)
		std__panic__syscall("std__open");
	return (fd);
}
