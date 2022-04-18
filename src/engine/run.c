#include "engine.h"
#include "renderer.h"
#include "std__math.h"
#include <stdio.h>

void engine__refresh(t_engine *this) {
  renderer__raycast(&this->renderer, &this->camera);
  renderer__draw(&this->renderer);
}

int engine__loop(t_engine *this) {
  if (inputhandler__is_movement(&this->inputhandler)) {
    engine__refresh(this);
    engine__move_player(this);
  }
  return (0);
}

void engine__run(t_engine *this) {
  mlx_loop_hook(this->renderer.mlx, &engine__loop, this);
  engine__refresh(this);
  mlx_loop(this->renderer.mlx);
}
