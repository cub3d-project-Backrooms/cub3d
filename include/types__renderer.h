#ifndef TYPES__RENDERER_H
#define TYPES__RENDERER_H

#include "mlx.h"
#include "std__types.h"
#include "std__types__math.h"
#include "types__platform__keycode.h"

typedef void *t_mlx__ref;
typedef void *t_mlx__window_ref;
typedef void *t_mlx__image_ref;

typedef struct s_image {
  t_mlx__image_ref img_ref;
  t_mlx__ref mlx_ref;
  int *data;
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

typedef struct s_engine__keyinfo {
  bool is_up_pressed;
  bool is_down_pressed;
  bool is_left_pressed;
  bool is_right_pressed;
} t_engine__keyinfo;

typedef enum e_config {
  mapWidth = 24,
  mapHeight = 24,
  WIDTH = 640,
  HEIGHT = 480,
} t_config;

typedef enum e_direction { UP, DOWN, LEFT, RIGHT } t_direction;
typedef enum e_sign { PLUS = 1, MINUS = -1 } t_sign;

typedef struct s_renderer {
  t_mlx__ref mlx;
  t_mlx__window_ref window;
  t_image buffer_window;
  t_camera camera;
  int buf[HEIGHT][WIDTH];
  double moveSpeed;
  double rotSpeed;
  t_engine__keyinfo keyinfo;
} t_renderer;

#endif
