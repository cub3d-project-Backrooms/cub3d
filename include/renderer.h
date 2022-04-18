#ifndef ENGINE_H
#define ENGINE_H

#include "mlx.h"
#include "types__platform__keycode.h"
#include "types__x11_events.h"
#include "types__renderer.h"
#include <stdbool.h>

// clang-format off
//@func
/*
** < draw.c > */

void	draw(t_renderer* info);
void	clear_grid(int grid[HEIGHT][WIDTH]);
/*
** < keyinput.c > */

int		key_release(t_keycode key, t_renderer* info);
int		key_press(t_keycode key, t_renderer* info);
/*
** < movement.c > */

void	engine__move_player(t_renderer* e);
#endif  // __ENGINE_H__
