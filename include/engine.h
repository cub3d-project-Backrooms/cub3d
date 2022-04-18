#ifndef ENGINE_H
#define ENGINE_H

#include "types__renderer.h"

//@func
/*
** < draw.c > */

void	draw(t_renderer *info);
void	clear_grid(int grid[HEIGHT][WIDTH]);
/*
** < keyinput.c > */

int		key_release(t_keycode key, t_renderer *this);
int		key_press(t_keycode key, t_renderer *this);
/*
** < movement.c > */

void	engine__move_player(t_renderer *e);
#endif
