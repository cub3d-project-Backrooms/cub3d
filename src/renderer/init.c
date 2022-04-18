#include "data.h"
#include "engine.h"
#include "raycast.h"
#include "renderer.h"
#include "types__x11_events.h"

void renderer__init__mlx(t_renderer *this) {
  this->mlx = mlx_init();
  this->window = mlx_new_window(this->mlx, WIDTH, HEIGHT, "mlx");
}

void renderer__init(t_renderer *this, t_camera camera) {
  renderer__init__mlx(this);
  this->buffer_window.img_ref = mlx_new_image(this->mlx, WIDTH, HEIGHT);
  this->buffer_window.data = (int *)mlx_get_data_addr(
      this->buffer_window.img_ref, &this->buffer_window.bits_per_pixel,
      &this->buffer_window.size_line, &this->buffer_window.endian);
  this->camera = camera;
  this->moveSpeed = 0.01;
  this->rotSpeed = 0.01;
  // this->keyinfo = (t_inputhandler__keyinfo){false, false, false, false};
}
