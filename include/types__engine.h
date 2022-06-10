/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types__engine.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkim <tkim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 10:13:06 by youkim            #+#    #+#             */
/*   Updated: 2022/06/10 13:35:13 by tkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES__ENGINE_H
# define TYPES__ENGINE_H

# include "types__renderer.h"

typedef struct s_inputhandler
{
	bool	is_up_pressed;
	bool	is_down_pressed;
	bool	is_left_pressed;
	bool	is_right_pressed;
	bool	is_left_rotate_pressed;
	bool	is_right_rotate_pressed;
	bool	is_exit;
	bool	is_shift_pressed;
	bool	is_toggle_door;
	int		x;
	float	mouse_motion_size;
}	t_inputhandler;

typedef struct s_engine
{
	t_renderer		renderer;
	t_inputhandler	inputhandler;
	t_camera		camera;
	double			movespeed;
	double			rotspeed;
	int				frame;
}	t_engine;

typedef enum s_mousemotion
{
	MOUSEMOTION_LEFT = -1,
	MOUSEMOTION_NONE = 0,
	MOUSEMOTION_RIGHT = 1
}	t_mousemotion;

#endif
