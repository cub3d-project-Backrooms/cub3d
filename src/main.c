#include "data.h"
#include "engine.h"
#include "raycast.h"
#include "renderer.h"
#include "types__x11_events.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
const extern int worldMap[24][24];

int main_loop(t_renderer *this) {
  if (is_raycast_refresh(this->keyinfo)) {
    raycast(this);
    draw(this);
  }
  engine__move_player(this);

  return (0);
}

int main(void) {
  // t_engine engine;
  t_renderer renderer;
  t_camera camera = {
      .pos = {12, 5},
      .dir = {-1, 0},
      .plane = {0, 0.66},
  };

  renderer__init(&renderer, camera);

  mlx_loop_hook(renderer.mlx, &main_loop, &renderer);
  mlx_hook(renderer.window, X11EVENTS__KeyPress, X11MASKS__KeyPressMask,
           &key_press, &renderer);
  mlx_hook(renderer.window, X11EVENTS__KeyRelease, X11MASKS__KeyReleaseMask,
           &key_release, &renderer);

  raycast(&renderer);
  draw(&renderer);

  mlx_loop(renderer.mlx);
}
