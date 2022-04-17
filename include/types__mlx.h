#ifndef TYPES__MLX_H
#define TYPES__MLX_H

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

#endif
