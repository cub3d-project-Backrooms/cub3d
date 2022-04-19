#ifndef TYPES__ENGINE_H
# define TYPES__ENGINE_H

# include "types__renderer.h"

typedef struct s_inputhandler
{
	bool	is_up_pressed;
	bool	is_down_pressed;
	bool	is_left_pressed;
	bool	is_right_pressed;
	bool	is_exit;
}	t_inputhandler;

typedef struct s_engine
{
	t_renderer		renderer;
	t_inputhandler	inputhandler;
	t_camera		camera;
	double			movespeed;
	double			rotspeed;
}	t_engine;

#endif
