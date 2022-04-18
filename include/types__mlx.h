#ifndef __TYPES__MLX_H__
#define __TYPES__MLX_H__

typedef struct s_img {
  void* img;
  int* data;

  int size_l;
  int bpp;
  int endian;
  int img_width;
  int img_height;
} t_img;

#endif // __TYPES__MLX_H__
