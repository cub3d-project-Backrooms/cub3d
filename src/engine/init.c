#include "engine.h"
#include "renderer.h"
#include "types__x11_events.h"
#include <stdlib.h>
#include <math.h>

static void	engine__init__input(t_engine *this)
{
	mlx_hook(this->renderer.window, X11EVENTS__KeyPress, X11MASKS__KeyPressMask,
		&inputhandler__key_press, &this->inputhandler);
	mlx_hook(this->renderer.window, X11EVENTS__KeyRelease,
		X11MASKS__KeyReleaseMask, &inputhandler__key_release,
		&this->inputhandler);
	mlx_hook(this->renderer.window, X11EVENTS__DestroyNotify,
		X11MASKS__NoEventMask, &engine__deinit, this);
}

int	engine__deinit(t_engine *this)
{
	renderer__deinit(&this->renderer);
	exit(0);
	return (0);
}

// camera position will be determined by parsed map result someday
void	engine__init(t_engine *this)
{
	t_camera	camera;

	camera = (t_camera){
		.pos = {17, 2},
		.dir = {-1, 0},
		.plane = {0, 0.66},
	};
	renderer__init(&this->renderer);
	this->camera = camera;
	engine__rotate_player(this, 3.14159265358979323846264338327950288 / 2);
	this->inputhandler = inputhandler__init();
	this->movespeed = 0.02;
	this->rotspeed = 0.015;
	engine__init__input(this);
}
