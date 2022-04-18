#include <stdio.h>
#include <time.h>
#include "engine.h"
#include "renderer.h"
#include "std__math.h"

void engine__refresh(t_engine* this) {
  t_renderer* renderer = &this->renderer;
  renderer__clear(renderer);
  renderer__raycast(renderer, &this->camera);
  renderer__draw_minimap(renderer, &this->camera);
  renderer__draw_to_window(renderer);
}

// time_t oldtime, nowtime;
// char fps[40];
char pos[40];

int engine__loop(t_engine* this) {
  if (this->inputhandler.keyinfo.is_exit) {
    engine__deinit(this);
  } else if (inputhandler__is_movement(&this->inputhandler)) {
    engine__refresh(this);
    engine__move_player(this);
  }

  sprintf(pos, "X: %f Y: %f", this->camera.pos.x, this->camera.pos.y);
  mlx_string_put(this->renderer.mlx, this->renderer.window, 0, 96 + 13,
                 0xFFFFFF, pos);
  return (0);
}

void engine__run(t_engine* this) {
  mlx_loop_hook(this->renderer.mlx, &engine__loop, this);
  engine__refresh(this);
  mlx_loop(this->renderer.mlx);
}
