#ifndef INPUTHANDLER_H
#define INPUTHANDLER_H

#include "types__input.h"

//@func
/*
** < handler.c > */

t_inputhandler	inputhandler__init();
int				inputhandler__key_press(t_keycode key,
					t_inputhandler *handler);
#endif
