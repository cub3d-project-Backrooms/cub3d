#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "data.h"
#include "engine.h"
#include "raycast.h"

const extern int worldMap[24][24];

int main_loop(t_engine* engine) {
  if (is_raycast_refresh(engine->keyinfo)) {
    raycast(engine);
    draw(engine);
  }
  engine__move_player(engine);

  return (0);
}

int main(void) {
  t_engine engine;
  engine.mlx = mlx_init();

  engine.pos = (t_vec){12, 5};
  engine.dir = (t_vec){-1, 0};
  engine.plane = (t_vec){0, 0.66};
  engine.moveSpeed = 0.025;
  engine.rotSpeed = 0.01;
  engine.keyinfo = (t_engine__keyinfo){false, false, false, false};

  engine.win = mlx_new_window(engine.mlx, WIDTH, HEIGHT, "mlx");

  engine.img.img = mlx_new_image(engine.mlx, WIDTH, HEIGHT);
  engine.img.data = (int*)mlx_get_data_addr(
      engine.img.img, &engine.img.bpp, &engine.img.size_l, &engine.img.endian);

  mlx_loop_hook(engine.mlx, &main_loop, &engine);
  mlx_hook(engine.win, X11EVENTS__KeyPress, X11MASKS__KeyPressMask, &key_press,
           &engine);
  mlx_hook(engine.win, X11EVENTS__KeyRelease, X11MASKS__KeyReleaseMask,
           &key_release, &engine);

  raycast(&engine);
  draw(&engine);

  mlx_loop(engine.mlx);
}
