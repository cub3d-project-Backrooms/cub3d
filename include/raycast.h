#ifndef __RAYCAST_H__
#define __RAYCAST_H__

#include "std__vector.h"
#include "types__color.h"
#include "types__engine.h"
//@func
/*
** < raycast.c > */

bool		is_raycast_refresh(t_engine__keyinfo keyinfo);
t_colors	get_color(int map_y, int map_x);
bool		is_ray_hit_wall(const t_ivec* pos);
void		raycast(t_engine* e);
#endif  // __RAYCAST_H__
