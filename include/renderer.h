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
** < init.c > */

void		renderer__init__mlx(t_renderer *this);
void		renderer__init(t_renderer *this, t_camera camera);
/*
** < raycast.c > */

bool		is_raycast_refresh(t_engine__keyinfo keyinfo);
t_colors	get_color(int map_y, int map_x);
bool		is_ray_hit_wall(const t_ivec *pos);
t_vec		camera__cast_ray(t_camera *this, double x);
t_ivec		camera__to_pos_at_map(t_camera *this);
t_vec		raycast__dist_to_next_closest_wall(t_vec ray_dir);
void		raycast(t_renderer *e);
#endif  // __ENGINE_H__
