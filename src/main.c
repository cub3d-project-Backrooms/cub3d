#include "engine.h"
#include "renderer.h"
#include "std__types.h"
#include <stdio.h>
#include <stdlib.h>

int	main(int argc, t_const_string argv[])
{
	t_engine	engine;

	(void)argc;
	(void)argv;
	engine__init(&engine);
	engine__run(&engine);
	return (0);
}
