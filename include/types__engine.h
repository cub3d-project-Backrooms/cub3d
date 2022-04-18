#ifndef TYPES__ENGINE_H
#define TYPES__ENGINE_H

#include "types__renderer.h"

typedef struct s_inputhandler {
  t_inputhandler__keyinfo keyinfo;
} t_inputhandler;

typedef struct s_engine {
  t_renderer renderer;
  t_inputhandler inputhandler;
  // t_camera camera;
} t_engine;

#endif
