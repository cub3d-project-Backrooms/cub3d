#ifndef TYPES__ENGINE_H
#define TYPES__ENGINE_H

#include "std__types.h"
#include "std__types__math.h"
#include "types__input.h"
#include "types__platform__keycode.h"
#include "types__renderer.h"

typedef struct s_config {
  t_string title;
  // t_ivec map_size;
  t_sizevec window_size;
  double initial_player_move_speed;
  double initial_player_rot_speed;
} t_config;

typedef enum e_tile__type {
  TILE__TYPE__EMPTY,
  TILE__TYPE__NORMAL,
  TILE__TYPE__DOOR,
  TILE__TYPE__WALL,
  TILE__TYPE__PLAYER,
} t_tile__type;

typedef struct s_map {
  t_sizevec size;
  t_tile__type **grid;
} t_map;

typedef struct s_engine {
  t_renderer renderer;
  t_map map;
} t_engine;

#endif
