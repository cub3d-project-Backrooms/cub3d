#ifndef __TYPES__ENGINE_H__
#define __TYPES__ENGINE_H__

#include "std__types__math.h"
#include "types__engine.h"
#include "types__mlx.h"

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

typedef struct s_engine {
  t_vec pos;
  t_vec dir;
  t_vec plane;
  void *mlx;
  void *win;
  void *buffer;
  double moveSpeed;
  double rotSpeed;
  t_img img;
  int buf[HEIGHT][WIDTH];
  t_engine__keyinfo keyinfo;
} t_engine;

typedef enum e_direction { UP, DOWN, LEFT, RIGHT } t_direction;
typedef enum e_sign { PLUS = 1, MINUS = -1 } t_sign;

#endif // __TYPES__ENGINE_H__
