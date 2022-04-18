#include <stdio.h>
#include <time.h>
#include "engine.h"
#include "renderer.h"
#include "std__math.h"

void engine__refresh(t_engine* this) {
  renderer__raycast(&this->renderer, &this->camera);
  renderer__draw(&this->renderer);
}

// time_t oldtime, nowtime;
// char fps[40];

int engine__loop(t_engine* this) {
  // oldtime = nowtime;
  // nowtime = time(NULL);
  if (inputhandler__is_movement(&this->inputhandler)) {
    engine__refresh(this);
    engine__move_player(this);
  }
  // double frametime = difftime(nowtime, oldtime);
  // sprintf(fps, "FPS: %.10f", 1.0 / frametime);
  // mlx_string_put(this->renderer.mlx, this->renderer.window, 10, 10, 0xFFFFFF,
  //                fps);
  return (0);
}

void engine__run(t_engine* this) {
  mlx_loop_hook(this->renderer.mlx, &engine__loop, this);
  engine__refresh(this);
  mlx_loop(this->renderer.mlx);
}
