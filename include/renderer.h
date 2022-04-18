#ifndef RENDERER_H
#define RENDERER_H

#include "mlx.h"
#include "types__color.h"
#include "types__platform__keycode.h"
#include "types__renderer.h"
#include "types__x11_events.h"
#include <stdbool.h>

// clang-format off
//@func
/*
** < camera.c > */

t_vec		camera__ray_dir_at_position(t_camera *this, double x);
t_ivec		camera__to_pos_at_map(t_camera *this);
/*
** < dda__dist.c > */

t_vec		dda__dist_to_next_closest_grid(t_vec* ray_dir);
double		dda__normalized_plane_x(double x);
double		dda__perpendicular_dist_to_closest_grid(t_dda__step* step,
				t_camera* camera, t_ivec* map_pos, t_vec* ray_dir);
/*
** < dda__step.c > */

t_dda__step	dda__initial_step(t_camera* camera, t_ivec* map_pos,
				t_vec* ray_dir, t_vec* delta_dist);
void		dda__advance_step(t_dda__step* step, t_ivec* map_pos,
				t_vec* delta_dist);
bool		dda__is_ray_hit_wall(const t_ivec* pos);
void		dda__advance_step_until_hit(t_dda__step* step, t_ivec* map_pos,
				t_vec* delta_dist);
/*
** < init.c > */

void		renderer__init__mlx(t_renderer *this);
void		renderer__init(t_renderer *this);
/*
** < raycast.c > */

t_colors	get_color(t_ivec* map, bool is_hit_y_side);
void		renderer__draw__vertical_wall(t_renderer* this, int lineheight,
				int color, int x);
void		renderer__raycast__wall(t_renderer* this, t_camera* camera, int x);
void		renderer__raycast(t_renderer* this, t_camera* camera);
#endif  // __ENGINE_H__
