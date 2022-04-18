#ifndef TYPES__ENGINE_H
#define TYPES__ENGINE_H

#include "types__renderer.h"

typedef struct s_inputhandler {
  t_inputhandler__keyinfo keyinfo;
  t_ivec mouse;
  t_ivec old_mouse;
  t_keycode mouse_status;
} t_inputhandler;

typedef struct s_engine {
  t_renderer renderer;
  t_inputhandler inputhandler;
  t_camera camera;
  double moveSpeed;
  double rotSpeed;
} t_engine;

#endif
