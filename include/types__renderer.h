#ifndef TYPES__RENDERER_H
# define TYPES__RENDERER_H

# include "mlx.h"
# include "std__types.h"
# include "std__types__math.h"
# include "types__platform__keycode.h"
# include "types__parser.h"
# include "defs__texture.h"

typedef void			*t_mlx__ref;
typedef void			*t_mlx__window_ref;
typedef void			*t_mlx__image_ref;
typedef int				**t_grid;

typedef struct s_camera
{
	t_vec				pos;
	t_vec				dir;
	t_vec				plane;
}	t_camera;

typedef struct s_world
{
	int			world_width;
	int			world_height;
	t_grid		worldmap;
	t_string	tex_name[TEX__AMOUNT];
	int			texture[TEX__AMOUNT + 3][TEX__WIDTH * TEX__HEIGHT];
	t_camera	camera;
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
	mapWidth = 24,
	mapHeight = 24,
	WIDTH = 640,
	HEIGHT = 480,
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
	int			texX;
	double		step_val;
	double		tex_pos;
}	t_walldata;

#endif
