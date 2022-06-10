#ifndef RAYCAST_H
# define RAYCAST_H

# include "types__renderer.h"

//@func
/*
** < floor.c > */

void		floordata__raycast__set_raydir_vector(t_floordata *this,
				t_camera *camera);
void		floordata__raycast__set_row_distance(t_floordata *this,
				int current_y);
void		floordata__raycast__set_floor_vectors(t_floordata *this,
				t_camera *camera);
void		floordata__raycast__set_dtexture_vector(t_floordata *this);
void		renderer__draw__floor(t_renderer *this, t_floordata *vecs,
				int current_x, int current_y);
/*
** < raycast.c > */

void		renderer__raycast__floor(t_renderer *this, t_camera *camera);
void		renderer__raycast__wall(t_renderer *this, t_camera *camera,
				double zbuffer[WIDTH]);
void		renderer__raycast__sprites(t_renderer* this, t_camera* camera,
				double zbuffer[WIDTH]);
void		renderer__raycast(t_renderer *this, t_camera *camera);
/*
** < sprite.c > */

void		renderer__raycast__sprite(t_renderer* this, t_camera* camera,
				double zbuffer[WIDTH], int i);
/*
** < texture.c > */

t_texdata	walldata__get_texdata(t_walldata *data, t_mapfmt tile_type);
t_rgb		renderer__draw__wall_texture(t_renderer *this, t_walldata *data);
/*
** < wall.c > */

void		renderer__draw__vertical_wall(t_renderer *this, int lineheight,
				t_rgb color, int x);
void		walldata__raycast__set_dda_vector(t_walldata *this,
				t_camera *camera, int current_x, t_world *world);
void		walldata__draw__set_wall_data(t_walldata *this, t_camera *camera);
void		walldata__draw__set_texture_data(t_walldata *this);
#endif
