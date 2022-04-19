#ifndef TYPES__MLX_H
#define TYPES__MLX_H

typedef struct s_img {
  void* img;
  int* data;

  int size_l;
  int bpp;
  int endian;
  int img_width;
  int img_height;
} t_img;

#endif
