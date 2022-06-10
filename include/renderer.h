/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youkim <youkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 10:13:06 by youkim            #+#    #+#             */
/*   Updated: 2022/05/04 15:11:20 by youkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDERER_H
# define RENDERER_H

# include "mlx.h"
# include "types__color.h"
# include "types__platform__keycode.h"
# include "types__renderer.h"
# include "types__x11_events.h"
# include <stdbool.h>

// clang-format off

// wrapper for all platforms
void		platform_mouse_get_pos(
				t_mlx__ref mlx, t_mlx__window_ref window, int *x, int *y);
void		platform_mouse_move(
				t_mlx__ref mlx, t_mlx__window_ref window, int x, int y);

//@func
/*
** < camera.c > */

t_vec			camera__ray_dir_at_position(t_camera *this, double x);
t_ivec			camera__to_pos_at_map(t_camera *this);
void			camera__rotate(t_camera *this, double angle);
/*
** < dda__dist.c > */

t_vec			dda__dist_to_next_closest_grid(t_vec *ray_dir);
double			dda__normalized_plane_x(double x);
double			dda__perpendicular_dist_to_closest_grid(t_dda__step *step,
					t_camera *camera, t_ivec *map_pos, t_vec *ray_dir);
/*
** < dda__step.c > */

t_dda__step		dda__initial_step(t_camera *camera, t_ivec *map_pos,
					t_vec *ray_dir, t_vec *delta_dist);
void			dda__advance_step(t_dda__step *step, t_ivec *map_pos,
					t_vec *delta_dist);
void			dda__advance_step_until_hit(t_dda__step *step, t_ivec *map_pos,
					t_vec *delta_dist, t_world *world);
/*
** < deinit.c > */

void			world__deinit(t_world *this);
void			renderer__deinit(t_renderer *this);
/*
** < draw.c > */

void			renderer__draw_to_window(t_renderer *info);
/*
** < image.c > */

void			image__write_to_buffer(t_image *this, int texline[]);
void			image__init_xpm(t_image *this, t_mlx__ref mlx, t_string path);
void			image__deinit(t_image *this);
/*
** < init.c > */

void			renderer__init__mlx(t_renderer *this);
void			renderer__init(t_renderer *this, t_world *world);
/*
** < load_tex.c > */

void			renderer__init_texture(t_renderer *this);
/*
** < minimap.c > */

void			renderer__draw_minimap_at(t_renderer *this, t_ivec player_pos,
					t_irange x_range, t_irange y_range);
void			renderer__draw_minimap(t_renderer *this, t_camera *camera);
/*
** < sprite.c > */

t_spritedata	spritedata__init(const t_sprites sprites, t_camera* camera,
					int i);
void			renderer__raycast__sprite(t_renderer* this, t_camera* camera,
					int i, int frame);
void			renderer__draw__sprites(t_renderer* this, t_camera* camera,
					int frame);
/*
** < util.c > */

t_rgb			shade_color(t_rgb color, double divide);
t_rgb			distance_shade(int color, double distance);
t_rgb			make_colorful(t_rgb color, int by);
void			floordata__draw__lights(t_floordata *this);
#endif  // __RENDERER_H__
