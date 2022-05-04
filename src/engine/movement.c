#include "engine.h"
#include "renderer.h"
#include "std__math.h"
#include <math.h>
#include <stdio.h>

static bool	is_collision_with_wall(t_world *world, const t_vec *pos)
{
	return (world->worldmap[(int)pos->y][(int)pos->x] > 0);
}

void	engine__try_move_player(t_engine *e, double x, double y)
{
	const double	dx = x * e->camera.dir.x * e->movespeed;
	const double	dy = y * e->camera.dir.y * e->movespeed;

	if (!is_collision_with_wall(&e->renderer.world,
			&(t_vec){e->camera.pos.x + dx, e->camera.pos.y}))
		e->camera.pos.x += dx;
	if (!is_collision_with_wall(&e->renderer.world,
			&(t_vec){e->camera.pos.x, e->camera.pos.y + dy}))
		e->camera.pos.y += dy;
}

// both camera direction && camera plane must be rotated
void	engine__rotate_player(t_engine *e, double angle)
{
	camera__rotate(&e->camera, angle * e->rotspeed);
}

void	engine__move_player(t_engine *e)
{
	t_inputhandler	*ih;

	ih = &e->inputhandler;
	if (ih->is_up_pressed)
		engine__try_move_player(e, 1, 1);
	if (ih->is_down_pressed)
		engine__try_move_player(e, -1, -1);
	if (ih->is_right_pressed)
		engine__rotate_player(e, 1);
	if (ih->is_left_pressed)
		engine__rotate_player(e, -1);
}
