/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youkim    <youkim@student.42seoul.kr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 10:13:06 by youkim            #+#    #+#             */
/*   Updated: 2022/05/04 10:13:06 by youkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "flags.h"
#include "engine.h"
#include "mlx.h"
#include "renderer.h"
#include "std__math.h"
#include <stdio.h>
#include <time.h>

void	engine__refresh(t_engine *this)
{
	t_renderer	*renderer;

	renderer = &this->renderer;
	renderer__raycast(renderer, &this->camera);
	if (BONUS)
		renderer__draw_minimap(renderer, &this->camera);
	renderer__draw_to_window(renderer);
}

void	engine__set_movespeed(t_engine *this)
{
	if (this->inputhandler.is_shift_pressed)
	{
		this->movespeed = 0.07;
		this->rotspeed = 0.02;
	}
	else
	{
		this->movespeed = 0.04;
		this->rotspeed = 0.04;
	}
}

int	engine__loop(t_engine *this)
{
	if (this->inputhandler.is_exit)
		engine__deinit(this);
	else if (inputhandler__is_action(&this->inputhandler))
	{
		engine__handle_door(this);
		engine__refresh(this);
		engine__set_movespeed(this);
		engine__move_player(this);
	}
	return (0);
}

void	engine__run(t_engine *this)
{
	mlx_loop_hook(this->renderer.mlx, &engine__loop, this);
	engine__refresh(this);
	mlx_loop(this->renderer.mlx);
}
