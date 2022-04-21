#include "engine.h"
#include "renderer.h"
#include "std__types.h"
#include <stdio.h>
#include <stdlib.h>
#include "std__system.h"
#include <fcntl.h>
#include <unistd.h>
#include "std__string.h"
#include "parser.h"

int	main(int argc, t_const_string argv[])
{
	t_parser	parser;
	t_engine	engine;

	(void)argc;
	(void)argv;
	if (argc != 2)
		std__panic__value("main", "usage: ./cub3d.out <cub_file>.cub");
	parser__init(&parser, argv[1]);
	parser__parse(&parser);
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
	// t_engine	engine;

	engine__init(&engine);
	engine__run(&engine);
	return (0);
}
