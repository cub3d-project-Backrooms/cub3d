#include "engine.h"
#include "renderer.h"
#include "std__math.h"
#include <math.h>
#include <stdio.h>

const extern int	g_worldmap[24][24];

static bool	is_collision_with_wall(const t_vec *pos)
{
	return (g_worldmap[(int)pos->x][(int)pos->y] > 0);
}

void	engine__try_move_player(t_engine *e, double x, double y)
{
	double	dx;
	double	dy;

	dx = x * e->camera.dir.x * e->movespeed;
	dy = y * e->camera.dir.y * e->movespeed;
	if (!is_collision_with_wall(&(t_vec){e->camera.pos.x + dx,
											e->camera.pos.y}))
		e->camera.pos.x += dx;
	if (!is_collision_with_wall(&(t_vec){e->camera.pos.x, e->camera.pos.y
			+ dy}))
		e->camera.pos.y += dy;
}

// TODO: make it into camera method
// both camera direction and camera plane must be rotated
void	engine__rotate_player(t_engine *e, double angle)
{
	vec__rotate_assign(&e->camera.dir, -1 * angle * e->rotspeed);
	vec__rotate_assign(&e->camera.plane, -1 * angle * e->rotspeed);
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
