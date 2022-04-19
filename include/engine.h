#ifndef ENGINE_H
# define ENGINE_H

# include "types__engine.h"
# include "types__renderer.h"

//@func
/*
** < init.c > */
void			engine__init(t_engine *this);
int				engine__deinit(t_engine *this);
/*
** < keyinput.c > */

t_inputhandler	inputhandler__init(void);
bool			inputhandler__is_movement(t_inputhandler *this);
bool			inputhandler__is_mouse_movement(t_inputhandler *this);
int				inputhandler__key_release(t_keycode key, t_inputhandler *this);
int				inputhandler__key_press(t_keycode key, t_inputhandler *this);
/*
** < movement.c > */

void			engine__try_move_player(t_engine *e, double x, double y);
void			engine__rotate_player(t_engine *e, double angle);
void			engine__rotate_player_to_mouse(t_engine *e);
void			engine__move_player(t_engine *e);
/*
** < run.c > */

void			engine__refresh(t_engine *this);
int				engine__loop(t_engine *this);
void			engine__run(t_engine *this);
#endif
