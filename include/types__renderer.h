/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types__renderer.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkim <tkim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 10:13:06 by youkim            #+#    #+#             */
/*   Updated: 2022/06/16 22:03:06 by tkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES__RENDERER_H
# define TYPES__RENDERER_H

# include "mlx.h"
# include "std__types.h"
# include "std__types__math.h"
# include "types__platform__keycode.h"
# include "types__parser.h"

typedef void			*t_mlx__ref;
typedef void			*t_mlx__window_ref;
typedef void			*t_mlx__image_ref;
typedef t_mapfmt		**t_grid;

typedef enum e_texdata
{
	TEX__AMOUNT = 4,
	TEX__AMOUNT_BONUS = 6,
	TEX__WIDTH = 64,
	TEX__HEIGHT = 64,
	TEX__WALL__NORTH = 0,
	TEX__WALL__SOUTH,
	TEX__WALL__EAST,
	TEX__WALL__WEST,
	TEX__FLOOR,
	TEX__CEILING0,
	TEX__CEILING1,
	TEX__DOOR,
	TEX__SPRITE0,
	TEX__SPRITE1
}	t_texdata;

typedef struct s_camera
{
	t_vec				pos;
	t_vec				dir;
	t_vec				plane;
}	t_camera;

typedef struct s_sprite
{
	t_vec	pos;
	double	distance;
}	t_sprite;

typedef t_sprite*		t_sprites;

typedef struct s_world
{
	int			world_width;
	int			world_height;
	t_grid		worldmap;
	t_rgb		colors[2];
	t_string	texture_path[TEX__AMOUNT];
	int			texture
	[TEX__AMOUNT + TEX__AMOUNT_BONUS][TEX__WIDTH * TEX__HEIGHT];
	t_camera	camera;
	bool		has_player;
	int			num_sprites;
	t_sprites	sprites;
}	t_world;

typedef struct s_image
{
	t_mlx__image_ref	img_ref;
	t_mlx__ref			mlx_ref;
	int					*data;
	int					bits_per_pixel;
	int					line_size;
	int					endian;
	t_sizevec			size;
}	t_image;

typedef enum e_config
{
	WIDTH = 640,
	HEIGHT = 480,
	MINIMAP_PIX = 4,
	NUM_FRAMES = 240
}	t_config;

typedef enum e_sign
{
	POSITIVE = 1,
	NEGATIVE = -1
}	t_sign;
typedef struct s_step
{
	t_sign				x_sign;
	t_sign				y_sign;
	t_vec				side_dist;
	bool				is_hit_y_side;
}	t_dda__step;

typedef struct s_renderer
{
	t_world				world;
	t_mlx__ref			mlx;
	t_mlx__window_ref	window;
	t_image				buffer_window;
	int					buf[HEIGHT][WIDTH];
	double				zbuffer[WIDTH];
}	t_renderer;

typedef struct s_pair
{
	double				first;
	int					second;
}	t_pair;

typedef struct s_floordata
{
	t_vec	ray_dir0;
	t_vec	ray_dir1;
	float	row_distance;
	t_vec	floor_step;
	t_vec	floor;
	t_vec	cell;
	t_vec	dt;
	int		floor_texture;
	int		ceiling_texture;
}	t_floordata;

typedef struct s_walldata
{
	double		camera_x;
	t_vec		ray_dir;
	t_ivec		map_pos;
	t_vec		delta_dist;
	t_dda__step	step;
	double		perp_wall_dist;
	int			lineheight;
	int			draw_start;
	int			draw_end;
	double		wallx;
	int			texx;
	double		step_val;
	double		tex_pos;
}	t_walldata;

typedef struct s_spritedata
{
	t_vec		d;
	double		inverse_determinant;
	t_vec		transform;
	int			screen_x;
	t_sizevec	size;
	t_irange	x_range;
	t_irange	y_range;
	int			frame;
}	t_spritedata;

#endif
