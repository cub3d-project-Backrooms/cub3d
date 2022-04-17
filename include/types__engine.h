#ifndef TYPES__ENGINE_H
#define TYPES__ENGINE_H

#include "std__types.h"
#include "std__types__math.h"
#include "types__input.h"
#include "types__mlx.h"
#include "types__platform__keycode.h"

typedef struct s_config {
  t_string title;
  // t_ivec map_size;
  t_ivec window_size;
  double initial_player_move_speed;
  double initial_player_rot_speed;
} t_config;

typedef struct s_engine {
  t_mlx__ref mlx;
  t_mlx__image_ref image;
  t_mlx__window_ref window;
  int **buffer;
  t_config config;
} t_engine;

typedef struct s_camera {
  t_vec dir;
  t_vec plane;
} t_camera;

typedef struct s_map {
  t_ivec size;
  int **grid;
} t_map;
#endif
