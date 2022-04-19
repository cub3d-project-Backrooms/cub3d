#include "engine.h"
#include "renderer.h"
#include <stdlib.h>

t_inputhandler	inputhandler__init(void)
{
	return ((t_inputhandler){false, false, false, false, false, false});
}

bool	inputhandler__is_movement(t_inputhandler *this)
{
	return (this->is_up_pressed || this->is_down_pressed
		|| this->is_left_pressed || this->is_right_pressed);
}

int	inputhandler__key_release(t_keycode key, t_inputhandler *this)
{
	if (key == KEY_W)
		this->is_up_pressed = false;
	if (key == KEY_S)
		this->is_down_pressed = false;
	if (key == KEY_A)
		this->is_left_pressed = false;
	if (key == KEY_D)
		this->is_right_pressed = false;
	if (key == KEY_ESC)
		this->is_exit = true;
	if (key == KEY_SHIFT)
		this->is_shift_pressed = false;
	return (0);
}

int	inputhandler__key_press(t_keycode key, t_inputhandler *this)
{
	if (key == KEY_W)
		this->is_up_pressed = true;
	if (key == KEY_S)
		this->is_down_pressed = true;
	if (key == KEY_A)
		this->is_left_pressed = true;
	if (key == KEY_D)
		this->is_right_pressed = true;
	if (key == KEY_ESC)
		this->is_exit = true;
	if (key == KEY_SHIFT)
		this->is_shift_pressed = true;
	return (0);
}
