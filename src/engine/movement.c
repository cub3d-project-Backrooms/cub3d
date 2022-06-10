/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkim <tkim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 10:13:06 by youkim            #+#    #+#             */
/*   Updated: 2022/06/10 13:31:51 by tkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"
#include "renderer.h"
#include "std__math.h"
#include <math.h>

void	engine__move_player(t_engine *e)
{
	const t_inputhandler	*ih = &e->inputhandler;

	if (ih->is_up_pressed)
		engine__try_move_player_straight(e, POSITIVE);
	if (ih->is_down_pressed)
		engine__try_move_player_straight(e, NEGATIVE);
	if (ih->is_left_pressed)
		engine__try_strafe_player(e, NEGATIVE);
	if (ih->is_right_pressed)
		engine__try_strafe_player(e, POSITIVE);
	if (ih->is_right_rotate_pressed || is_mouse_motion(ih) == MOUSEMOTION_RIGHT)
		engine__rotate_player(e, POSITIVE);
	if (ih->is_left_rotate_pressed || is_mouse_motion(ih) == MOUSEMOTION_LEFT)
		engine__rotate_player(e, NEGATIVE);
}
