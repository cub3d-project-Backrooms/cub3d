#include "engine.h"
#include "mlx.h"
#include "types__x11_events.h"
#include <stdio.h>

int main(void) {
  t_engine engine;
  t_config config = (t_config){
      .window_size = {.width = 800, .height = 600},
      .title = "cub3d",
  };
  engine__init(&engine, config);
  // printf("Hello, World!\n");
  // void *mlx = mlx_init();
  // void *win = mlx_new_window(mlx, 100, 100, "Hello, World!");

  // mlx_hook(engine.win, X11EVENTS__KeyPress, X11MASKS__KeyPressMask,
  // &key_press, 		 &engine); mlx_hook(engine.win,
  // X11EVENTS__KeyRelease, X11MASKS__KeyReleaseMask, 		 &key_release,
  // &engine); mlx_loop(mlx);
  return 0;
}
