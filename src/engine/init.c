#include "engine.h"
#include "renderer.h"
#include "types__x11_events.h"

static void engine__init__keyinput(t_engine *this) {
  mlx_hook(this->renderer.window, X11EVENTS__KeyPress, X11MASKS__KeyPressMask,
           &inputhandler__key_press, &this->inputhandler);
  mlx_hook(this->renderer.window, X11EVENTS__KeyRelease,
           X11MASKS__KeyReleaseMask, &inputhandler__key_release,
           &this->inputhandler);
}

void engine__init(t_engine *this, t_camera camera) {
  renderer__init(&this->renderer);
  // camera position will be determined by parsed map result someday
  this->camera = camera;
  inputhandler__init(&this->inputhandler);
  this->moveSpeed = 0.01;
  this->rotSpeed = 0.003;
  engine__init__keyinput(this);
}
