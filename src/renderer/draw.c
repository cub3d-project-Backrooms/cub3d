#include "mlx.h"
#include "renderer.h"

const extern int worldMap[24][24];

/**
 * @brief
 *
 * The pixel data is a single array of width * height * 4 bytes.
 * so it is also same as: array of
 * int * width, int * width, int * width...
 * hence it is indexed with [y * width + x].
 *
 * @param info
 */
void renderer__draw_to_window(t_renderer* info) {
  for (int y = 0; y < HEIGHT; y++)
    for (int x = 0; x < WIDTH; x++)
      info->buffer_window.data[y * WIDTH + x] = info->buf[y][x];

  mlx_put_image_to_window(info->mlx, info->window, info->buffer_window.img_ref,
                          0, 0);
}

void renderer__clear_grid(int grid[HEIGHT][WIDTH]) {
  for (int i = 0; i < HEIGHT; i++)
    for (int j = 0; j < WIDTH; j++)
      grid[i][j] = 0;
}

void renderer__clear(t_renderer* this) {
  renderer__clear_grid(this->buf);
}

void renderer__draw_buf_by_ivec(t_renderer* this, t_ivec* pos, int color) {
  this->buf[pos->y][pos->x] = color;
}
