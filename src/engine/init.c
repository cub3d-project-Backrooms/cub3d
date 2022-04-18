#include <stdlib.h>
#include "engine.h"
#include "renderer.h"
#include "types__x11_events.h"
#define __USE_MISC
#include <math.h>

static void engine__init__input(t_engine* this) {
  mlx_hook(this->renderer.window, X11EVENTS__KeyPress, X11MASKS__KeyPressMask,
           &inputhandler__key_press, &this->inputhandler);
  mlx_hook(this->renderer.window, X11EVENTS__KeyRelease,
           X11MASKS__KeyReleaseMask, &inputhandler__key_release,
           &this->inputhandler);
  mlx_hook(this->renderer.window, X11EVENTS__DestroyNotify,
           X11MASKS__NoEventMask, &engine__deinit, this);
}

int engine__deinit(t_engine* this) {
  renderer__deinit(&this->renderer);
  exit(0);
  return (0);
}

void engine__init(t_engine* this) {
  t_camera camera = {
      .pos = {10, 6},
      .dir = {-1, 0},
      .plane = {0, 0.66},
  };

  renderer__init(&this->renderer);
  // camera position will be determined by parsed map result someday
  this->camera = camera;
  engine__rotate_player(this, M_PI / 2);
  inputhandler__init(&this->inputhandler);
  this->moveSpeed = 0.01;
  this->rotSpeed = 0.005;
  engine__init__input(this);
}
