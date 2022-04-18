#ifndef RENDERER_H
#define RENDERER_H

#include <stdbool.h>
#include "mlx.h"
#include "types__color.h"
#include "types__platform__keycode.h"
#include "types__renderer.h"
#include "types__x11_events.h"

#define texWidth 64
#define texHeight 64
#define numSprites 19

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
** < deinit.c > */

void		renderer__deinit(t_renderer* this);
/*
** < draw.c > */

void		renderer__draw_to_window(t_renderer* info);
void		renderer__clear_grid(int grid[HEIGHT][WIDTH]);
void		renderer__clear(t_renderer* this);
void		renderer__draw_buf_by_ivec(t_renderer* this, t_ivec* pos,
				int color);
/*
** < init.c > */

void		renderer__init__mlx(t_renderer *this);
void		renderer__init(t_renderer *this);
/*
** < minimap.c > */

void		renderer__draw_minimap_at(t_renderer* this, t_ivec player_pos,
				t_irange x_range, t_irange y_range);
void		renderer__draw_minimap(t_renderer* this, t_camera* camera);
/*
** < raw_data.c > */

void		load_image(t_renderer* r, int* texture, char* path, t_image* img);
void		renderer__init_texture(t_renderer* r);
void		sort_order(t_pair* orders, int amount);
void		sortSprites(int* order, double* dist, int amount);
/*
** < raycast.c > */

t_colors	get_color(t_ivec* map, bool is_hit_y_side);
void		renderer__draw__vertical_wall(t_renderer* this, int lineheight,
				int color, int x);
void		renderer__raycast__floor(t_renderer* this, t_camera* camera);
void		renderer__raycast__wall(t_renderer* this, t_camera* camera,
				double zbuffer[WIDTH]);
void		renderer__raycast__sprite(t_renderer* this, t_camera* camera,
				double zbuffer[WIDTH]);
void		renderer__raycast(t_renderer* this, t_camera* camera);
#endif  // __ENGINE_H__
