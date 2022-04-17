#ifndef TYPES__ENGINE_H
#define TYPES__ENGINE_H

#include "std__types.h"
#include "std__types__math.h"
#include "types__input.h"
#include "types__platform__keycode.h"

typedef void *t_mlx__ref;
typedef void *t_mlx__image_ref;
typedef void *t_mlx__window_ref;

typedef struct s_config {
  // t_ivec map_size;
  t_ivec window_size;
  double initial_player_move_speed;
  double initial_player_rot_speed;
} t_config;

typedef struct s_engine {
  t_mlx__ref mlx;
  t_mlx__image_ref image;
  t_mlx__window_ref window;
} t_engine;

typedef struct s_camera {
  t_vec dir;
  t_vec plane;
} t_camera;

typedef struct s_map {
  t_ivec size;
  t_vec *points;
} t_map;
#endif
