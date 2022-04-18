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
  renderer.mlx = mlx_init();
  t_camera camera = {
      .pos = {12, 5},
      .dir = {-1, 0},
      .plane = {0, 0.66},
  };
  renderer.moveSpeed = 0.025;
  renderer.rotSpeed = 0.01;
  renderer.keyinfo = (t_engine__keyinfo){false, false, false, false};
  renderer.camera = camera;
  renderer.window = mlx_new_window(renderer.mlx, WIDTH, HEIGHT, "mlx");

  renderer.image.img_ref = mlx_new_image(renderer.mlx, WIDTH, HEIGHT);
  renderer.image.data = (int *)mlx_get_data_addr(
      renderer.image.img_ref, &renderer.image.bits_per_pixel,
      &renderer.image.size_line, &renderer.image.endian);

  mlx_loop_hook(renderer.mlx, &main_loop, &renderer);
  mlx_hook(renderer.window, X11EVENTS__KeyPress, X11MASKS__KeyPressMask,
           &key_press, &renderer);
  mlx_hook(renderer.window, X11EVENTS__KeyRelease, X11MASKS__KeyReleaseMask,
           &key_release, &renderer);

  raycast(&renderer);
  draw(&renderer);

  mlx_loop(renderer.mlx);
}
