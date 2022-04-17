#include "engine.h"
#include "mlx.h"
#include "std__system.h"

void engine__init__mlx(t_engine *engine) {
  engine->mlx = mlx_init();
  engine->window =
      mlx_new_window(engine->mlx, engine->config.window_size.x,
                     engine->config.window_size.y, engine->config.title);
  // engine->image = mlx_new_image(engine->mlx, engine->config.window_size.x,
  //                               engine->config.window_size.y);
}

void engine__init(t_engine *engine, t_config config) {
  engine->config = config;
  engine__init__mlx(engine);
}
