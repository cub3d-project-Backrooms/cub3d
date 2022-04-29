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
	t_world		world;
	t_engine	engine;

	if (argc != 2)
		std__panic__value("main", "usage: ./cub3d.out <cub_file>.cub");
	parser__init(&parser, argv[1]);
	parser__parse(&parser, &world);
	engine__init(&engine, &world);
	engine__run(&engine);
	return (0);
}
