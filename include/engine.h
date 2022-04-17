#ifndef ENGINE_H
#define ENGINE_H

#include "types__engine.h"

//@func
/*
** < init.c > */

void	engine__init__mlx(t_engine *engine);
void	engine__init(t_engine *engine, t_config config);
#endif
