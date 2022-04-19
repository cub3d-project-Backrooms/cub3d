#include "renderer.h"

void renderer__deinit(t_renderer* this) {
  mlx_destroy_image(this->mlx, this->buffer_window.img_ref);
  mlx_destroy_window(this->mlx, this->window);
}
