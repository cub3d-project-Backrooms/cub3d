#include <unistd.h>
#include <fcntl.h>
#include "types__parser.h"
#include "std__error.h"
#include "std__system.h"

void	parser__init(t_parser *this, t_const_string path)
{
	this->fd = std__open(path, O_RDONLY);

}
