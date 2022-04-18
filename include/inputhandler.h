#ifndef INPUTHANDLER_H
#define INPUTHANDLER_H

#include "types__inputhandler.h"

//@func
/*
** < handler.c > */

void			inputhandler__key_status__init(bool list[], t_u16 size);
void			inputhandler__keybinds__init(t_keycode list[],
					t_u16 status_length,t_u16 alternatives,
					t_keycode keybinds[]);
t_inputhandler	inputhandler__init();
int				inputhandler__key_press(t_keycode key,
					t_inputhandler *handler);
int				inputhandler__key_release(t_keycode key,
					t_inputhandler *handler);
#endif
