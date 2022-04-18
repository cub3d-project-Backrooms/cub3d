#ifndef __TYPES__ENGINE_H__
#define __TYPES__ENGINE_H__

#include "std__types.h"
#include "std__types__math.h"
#include "types__platform__keycode.h"
// #include "types__renderer.h"


typedef struct s_renderer {
  t_vec pos;
  t_vec dir;
  t_vec plane;
  void *mlx;
  void *win;
  void *buffer;
  double moveSpeed;
  double rotSpeed;
  t_image image;
  int buf[HEIGHT][WIDTH];
  t_engine__keyinfo keyinfo;
} t_renderer;

typedef enum e_direction { UP, DOWN, LEFT, RIGHT } t_direction;
typedef enum e_sign { PLUS = 1, MINUS = -1 } t_sign;

#endif // __TYPES__ENGINE_H__
