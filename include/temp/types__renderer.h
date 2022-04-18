#ifndef TYPES__RENDERER_H
#define TYPES__RENDERER_H

#include "mlx.h"

typedef void *t_mlx__ref;
typedef void *t_mlx__window_ref;
typedef void *t_mlx__image_ref;

typedef struct s_image {
  t_mlx__image_ref img_ref;
  t_mlx__ref mlx_ref;
  char *data_addr;
  int bits_per_pixel;
  int size_line;
  int endian;
  t_sizevec size;
} t_image;

typedef struct s_camera {
  t_vec pos;
  t_vec dir;
  t_vec plane;
} t_camera;

typedef struct s_renderer {
  t_mlx__ref mlx;
  t_mlx__window_ref window;
  t_sizevec window_size;
  t_image buffer_image;
  t_camera camera;
} t_renderer;

#endif
