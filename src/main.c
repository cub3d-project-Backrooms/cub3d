#include "engine.h"
#include "renderer.h"
#include "std__types.h"
#include <stdio.h>
#include <stdlib.h>
#include "std__system.h"
#include <fcntl.h>
#include <unistd.h>
#include "std__string.h"

const extern int	g_worldmap[24][24];

int	main(int argc, t_const_string argv[])
{
	(void)argc;
	(void)argv;

	// t_const_string tex = "WE ./path_to_the_west_texture\n";
	// str__split()
	// t_fd fd;
	// t_string str;

	// fd = open("asset/map/mandatory.cub", O_RDONLY);
	// while (true)
	// {
	// 	str = std__new_readfile__line(fd);
	// 	if (str == NULL)
	// 		break ;
	// 	printf("%s\n", str);
	// 	free(str);
	// }
	// close(fd);
	t_engine	engine;

	(void)argc;
	(void)argv;
	engine__init(&engine);
	engine__run(&engine);
	return (0);
}
