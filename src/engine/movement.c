/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkim <tkim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 10:13:06 by youkim            #+#    #+#             */
/*   Updated: 2022/06/10 01:52:33 by tkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"
#include "renderer.h"
#include "std__math.h"
#include <math.h>

void	engine__try_move_player(t_engine *e, const t_vec d)
{
	if (!is_collision_with_wall(&e->renderer.world,
			&(t_ivec){e->camera.pos.x + d.x, e->camera.pos.y}))
		e->camera.pos.x += d.x;
	if (!is_collision_with_wall(&e->renderer.world,
			&(t_ivec){e->camera.pos.x, e->camera.pos.y + d.y}))
		e->camera.pos.y += d.y;
}

void	engine__try_move_player_straight(t_engine *e, t_sign dir)
{
	const t_vec	delta = {
		.x = dir * e->camera.dir.x * e->movespeed,
		.y = dir * e->camera.dir.y * e->movespeed};

	engine__try_move_player(e, delta);
}

void	engine__try_strafe_player(t_engine *e, t_sign dir)
{
	const t_vec	tmp = vec__mul(&e->camera.dir, e->movespeed);
	const t_vec	delta = vec__rotate(&tmp, dir * STD__PI / 2);

	engine__try_move_player(e, delta);
}

// both camera direction && camera plane must be rotated
void	engine__rotate_player(t_engine *e, double angle)
{
	camera__rotate(&e->camera, angle * e->rotspeed);
}

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
	if (ih->is_right_rotate_pressed || (ih->x > WIDTH / 2 && ih->delay_x % 5 == 0))
		engine__rotate_player(e, POSITIVE);
	if (ih->is_left_rotate_pressed || (ih->x < WIDTH / 2 && ih->delay_x % 5 == 0))
		engine__rotate_player(e, NEGATIVE);

}
