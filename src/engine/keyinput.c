/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyinput.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youkim    <youkim@student.42seoul.kr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 10:13:06 by youkim            #+#    #+#             */
/*   Updated: 2022/05/04 10:13:06 by youkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"
#include "renderer.h"
#include <stdlib.h>

t_inputhandler	inputhandler__init(void)
{
	const t_inputhandler	ih = {false};

	return (ih);
}

bool	inputhandler__is_action(t_inputhandler *this)
{
	return (this->is_up_pressed || this->is_down_pressed
		|| this->is_left_pressed || this->is_right_pressed
		|| this->is_left_rotate_pressed || this->is_right_rotate_pressed
		|| this->is_toggle_door);
}

static void	inputhandler__key_action(
	t_keycode key, t_inputhandler *this, bool value)
{
	if (key == KEY_W || key == KEY_UP)
		this->is_up_pressed = value;
	if (key == KEY_S || key == KEY_DOWN)
		this->is_down_pressed = value;
	if (key == KEY_A)
		this->is_left_pressed = value;
	if (key == KEY_D)
		this->is_right_pressed = value;
	if (key == KEY_Q || key == KEY_LEFT)
		this->is_left_rotate_pressed = value;
	if (key == KEY_E || key == KEY_RIGHT)
		this->is_right_rotate_pressed = value;
	if (key == KEY_ESC)
		this->is_exit = value;
	if (key == KEY_SHIFT)
		this->is_shift_pressed = value;
	if (key == KEY_SPACE)
		this->is_toggle_door = value;
}

int	inputhandler__key_release(t_keycode key, t_inputhandler *this)
{
	inputhandler__key_action(key, this, false);
	return (0);
}

int	inputhandler__key_press(t_keycode key, t_inputhandler *this)
{
	inputhandler__key_action(key, this, true);
	return (0);
}
