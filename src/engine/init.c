/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkim <tkim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 10:13:06 by youkim            #+#    #+#             */
/*   Updated: 2022/06/10 01:57:15 by tkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"
#include "renderer.h"
#include "types__x11_events.h"
#include <stdlib.h>
#include <math.h>
#include <stdio.h>

int mouse_hook(int x, int y, t_engine *this)
{
	mlx_mouse_hide();
	(void)x;
	this->inputhandler.delay_x++;
	mlx_mouse_get_pos(this->renderer.window, &this->inputhandler.x, &y );
	mlx_mouse_move(this->renderer.window, WIDTH / 2, HEIGHT / 2 );//스크린 정 중앙에 마우스 위치
	printf("%d %d\n", this->inputhandler.x, this->inputhandler.delay_x);
	return (0);
}

static void	engine__init__input(t_engine *this)
{
	mlx_hook(this->renderer.window, X11EVENTS__KeyPress, X11MASKS__KeyPressMask,
		&inputhandler__key_press, &this->inputhandler);
	mlx_hook(this->renderer.window, X11EVENTS__KeyRelease,
		X11MASKS__KeyReleaseMask, &inputhandler__key_release,
		&this->inputhandler);
	//mlx_mouse_hook(this->renderer.window, mouse_hook,this);
	mlx_hook(this->renderer.window, X11EVENTS__MotionNotify, X11MASKS__ButtonMotionMask, &mouse_hook, this);
	mlx_hook(this->renderer.window, X11EVENTS__DestroyNotify,
		X11MASKS__NoEventMask, &engine__deinit, this);
}

int	engine__deinit(t_engine *this)
{
	renderer__deinit(&this->renderer);
	exit(0);
	return (0);
}

void	engine__init(t_engine *this, t_world *world)
{
	this->camera = world->camera;
	renderer__init(&this->renderer, world);
	this->inputhandler = inputhandler__init();
	engine__init__input(this);
}
