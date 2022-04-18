#include "engine.h"
#include "graphic.h"
#include "mlx.h"
#include "std__system.h"

void engine__init__mlx(t_engine *engine) {
  engine->mlx = mlx_init();
  engine->window =
      mlx_new_window(engine->mlx, engine->config.window_size.width,
                     engine->config.window_size.height, engine->config.title);
  engine->buffer_image = image__new(engine->mlx, engine->config.window_size);
}

void engine__init(t_engine *engine, t_config config) {
  engine->config = config;
  engine__init__mlx(engine);
}
