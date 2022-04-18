#ifndef __ENGINE_H__
#define __ENGINE_H__

#include "mlx.h"
#include "types__engine.h"
#include "types__platform__keycode.h"
#include "types__x11_events.h"
#include <stdbool.h>

// clang-format off
//@func
/*
** < draw.c > */

void	draw(t_engine* info);
void	clear_grid(int grid[HEIGHT][WIDTH]);
/*
** < keyinput.c > */

int		key_release(t_keycode key, t_engine* info);
int		key_press(t_keycode key, t_engine* info);
/*
** < movement.c > */

void	engine__move_player(t_engine* e);
#endif  // __ENGINE_H__
