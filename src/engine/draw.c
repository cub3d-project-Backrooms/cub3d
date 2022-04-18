#include "engine.h"
#include "mlx_linux/mlx.h"

const extern int worldMap[24][24];

void draw(t_engine* info) {
  for (int y = 0; y < HEIGHT; y++)
    for (int x = 0; x < WIDTH; x++)
      info->img.data[y * WIDTH + x] =
          info->buf[y][x];  // NOTE: for some reason its WIDTH?

  mlx_put_image_to_window(info->mlx, info->win, info->img.img, 0, 0);
}

void clear_grid(int grid[HEIGHT][WIDTH]) {
  for (int i = 0; i < HEIGHT; i++)
    for (int j = 0; j < WIDTH; j++)
      grid[i][j] = 0;
}
