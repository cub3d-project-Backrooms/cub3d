#ifndef RENDERER_H
# define RENDERER_H

# include "mlx.h"
# include "types__color.h"
# include "types__platform__keycode.h"
# include "types__renderer.h"
# include "types__x11_events.h"
# include <stdbool.h>

# include "defs__texture.h"

// clang-format off
//@func
/*
** < camera.c > */

t_vec		camera__ray_dir_at_position(t_camera *this, double x);
t_ivec		camera__to_pos_at_map(t_camera *this);
/*
** < dda__dist.c > */

t_vec		dda__dist_to_next_closest_grid(t_vec *ray_dir);
double		dda__normalized_plane_x(double x);
double		dda__perpendicular_dist_to_closest_grid(t_dda__step *step,
				t_camera *camera, t_ivec *map_pos, t_vec *ray_dir);
/*
** < dda__step.c > */

t_dda__step	dda__initial_step(t_camera *camera, t_ivec *map_pos,
				t_vec *ray_dir, t_vec *delta_dist);
void		dda__advance_step(t_dda__step *step, t_ivec *map_pos,
				t_vec *delta_dist);
bool		dda__is_ray_hit_wall(const t_ivec *pos, t_world *world);
void		dda__advance_step_until_hit(t_dda__step *step, t_ivec *map_pos,
				t_vec *delta_dist, t_world *world);
/*
** < deinit.c > */

void		renderer__deinit(t_renderer *this);
/*
** < draw.c > */

void		renderer__draw_to_window(t_renderer *info);
void		renderer__draw_buf_by_ivec(t_renderer *this, t_ivec *pos,
				int color);
/*
** < image.c > */

void		image__write_to_buffer(t_image *this, int texline[]);
void		image__init(t_image *this, t_mlx__ref mlx, t_string path);
void		image__deinit(t_image *this);
/*
** < init.c > */

void		renderer__init__world_data(t_renderer *this);
void		renderer__init__mlx(t_renderer *this);
void		renderer__init(t_renderer *this);
/*
** < minimap.c > */

void		renderer__draw_minimap_at(t_renderer *this, t_ivec player_pos,
				t_irange x_range, t_irange y_range);
void		renderer__draw_minimap(t_renderer *this, t_camera *camera);
/*
** < raw_data.c > */

void		load_image(t_renderer *r, int *texture, t_string path);
void		renderer__init_texture(t_renderer *r);
/*
** < raycast.c > */

int			shade_color(int color, double divide);
int			distance_shade(int color, double distance);
void		renderer__draw__vertical_wall(t_renderer *this, int lineheight,
				int color, int x);
void		floordata__raycast__set_raydir_vector(t_floordata *this,
				t_camera *camera);
void		floordata__raycast__set_row_distance(t_floordata *this,
				int current_y);
void		floordata__raycast__set_floor_vectors(t_floordata *this,
				t_camera *camera);
void		floordata__raycast__set_delta_texture_vector(t_floordata *this,
				t_world *world);
bool		floordata__draw__is_light(t_floordata *this);
void		floordata__draw__checkerboard(t_floordata *this);
void		renderer__draw__floor(t_renderer *this, t_floordata *vecs,
				int current_x, int current_y);
void		renderer__raycast__floor(t_renderer *this, t_camera *camera);
void		walldata__raycast__set_dda_vector(t_walldata *this,
				t_camera *camera, int current_x, t_world *world);
void		walldata__draw__set_wall_data(t_walldata *this, t_camera *camera);
void		walldata__draw__set_texture_data(t_walldata *this, t_world *world);
int			renderer__draw__wall_texture(t_renderer *this,
				t_walldata *data);
void		renderer__raycast__wall(t_renderer* this, t_camera* camera,
				double zbuffer[WIDTH]);
void		renderer__raycast(t_renderer *this, t_camera *camera);
#endif  // __ENGINE_H__
