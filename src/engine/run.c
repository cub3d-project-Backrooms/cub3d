#include "engine.h"
#include "renderer.h"
#include "std__math.h"
#include <stdio.h>

void engine__refresh(t_engine *this) {
  raycast(&this->renderer, &this->camera);
  draw(&this->renderer);
}

int engine__loop(t_engine *this) {
  if (is_raycast_refresh(this->inputhandler.keyinfo)) {
    engine__refresh(this);
  }
  engine__move_player(this);
  return (0);
}

void engine__run(t_engine *this) {
  engine__refresh(this);
  mlx_loop_hook(this->renderer.mlx, &engine__loop, this);
  mlx_loop(this->renderer.mlx);
}
