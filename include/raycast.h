#ifndef __RAYCAST_H__
#define __RAYCAST_H__

#include "std__vector.h"
#include "types__color.h"
#include "types__renderer.h"
//@func
/*
** < raycast.c > */

bool		is_raycast_refresh(t_inputhandler__keyinfo keyinfo);
t_colors	get_color(int map_y, int map_x);
bool		is_ray_hit_wall(const t_ivec *pos);
t_vec		camera__cast_ray(t_camera *this, double x);
t_ivec		camera__to_pos_at_map(t_camera *this);
t_vec		raycast__dist_to_next_closest_wall(t_vec ray_dir);
void		raycast(t_renderer *e);
#endif // __RAYCAST_H__
