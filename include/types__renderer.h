#ifndef TYPES__RENDERER_H
# define TYPES__RENDERER_H

# include "mlx.h"
# include "std__types.h"
# include "std__types__math.h"
# include "types__platform__keycode.h"

typedef void			*t_mlx__ref;
typedef void			*t_mlx__window_ref;
typedef void			*t_mlx__image_ref;

typedef struct s_image
{
	t_mlx__image_ref	img_ref;
	t_mlx__ref			mlx_ref;
	int					*data;
	int					bits_per_pixel;
	int					line_size;
	int					endian;
	t_sizevec			size;
}						t_image;

typedef struct s_camera
{
	t_vec				pos;
	t_vec				dir;
	t_vec				plane;
}						t_camera;

typedef enum e_config
{
	mapWidth = 24,
	mapHeight = 24,
	// WIDTH = 1920,
	// HEIGHT = 1080,
	WIDTH = 640,
	HEIGHT = 480,
}						t_config;

typedef enum e_direction
{
	UP,
	DOWN,
	LEFT,
	RIGHT
}						t_direction;
typedef enum e_sign
{
	POSITIVE = 1,
	NEGATIVE = -1
}						t_sign;
typedef struct s_step
{
	t_sign				x_sign;
	t_sign				y_sign;
	t_vec				side_dist;
	bool				is_hit_y_side;
}						t_dda__step;

typedef struct s_renderer
{
	t_mlx__ref			mlx;
	t_mlx__window_ref	window;
	t_image				buffer_window;
	int					buf[HEIGHT][WIDTH];
}						t_renderer;

typedef struct s_pair
{
	double				first;
	int					second;
}						t_pair;
#endif
