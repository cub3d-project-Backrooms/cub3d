#include "engine.h"
#include "renderer.h"
#include "std__types.h"
#include "types__entity.h"

int worldMap[24][24] = {
    {4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 7, 7, 7, 7, 7, 7, 7, 7},
    {4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 7},
    {4, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7},
    {4, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7},
    {4, 0, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 7},
    {4, 0, 4, 0, 0, 0, 0, 5, 5, 5, 5, 5, 5, 5, 5, 5, 7, 7, 0, 7, 7, 7, 7, 7},
    {4, 0, 5, 0, 0, 0, 0, 5, 0, 5, 0, 5, 0, 5, 0, 5, 7, 0, 0, 0, 7, 7, 7, 1},
    {4, 0, 6, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, 5, 7, 0, 0, 0, 0, 0, 0, 8},
    {4, 0, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 7, 7, 1},
    {4, 0, 8, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, 5, 7, 0, 0, 0, 0, 0, 0, 8},
    {4, 0, 0, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, 5, 7, 0, 0, 0, 7, 7, 7, 1},
    {4, 0, 0, 0, 0, 0, 0, 5, 5, 5, 5, 0, 5, 5, 5, 5, 7, 7, 7, 7, 7, 7, 7, 1},
    {6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 0, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6},
    {8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4},
    {6, 6, 6, 6, 6, 6, 0, 6, 6, 6, 6, 0, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6},
    {4, 4, 4, 4, 4, 4, 0, 4, 4, 4, 6, 0, 6, 2, 2, 2, 2, 2, 2, 2, 3, 3, 3, 3},
    {4, 0, 0, 0, 0, 0, 0, 0, 0, 4, 6, 0, 6, 2, 0, 0, 0, 0, 0, 2, 0, 0, 0, 2},
    {4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 6, 2, 0, 0, 5, 0, 0, 2, 0, 0, 0, 2},
    {4, 0, 0, 0, 0, 0, 0, 0, 0, 4, 6, 0, 6, 2, 0, 0, 0, 0, 0, 2, 2, 0, 2, 2},
    {4, 0, 6, 0, 6, 0, 0, 0, 0, 4, 6, 0, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 2},
    {4, 0, 0, 5, 0, 0, 0, 0, 0, 4, 6, 0, 6, 2, 0, 0, 0, 0, 0, 2, 2, 0, 2, 2},
    {4, 0, 6, 0, 6, 0, 0, 0, 0, 4, 6, 0, 6, 2, 0, 0, 5, 0, 0, 2, 0, 0, 0, 2},
    {4, 0, 0, 0, 0, 0, 0, 0, 0, 4, 6, 0, 6, 2, 0, 0, 0, 0, 0, 2, 0, 0, 0, 2},
    {4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 1, 1, 1, 2, 2, 2, 2, 2, 2, 3, 3, 3, 3, 3}};

// TODO: make it stored where?
int texture[11][texHeight * texWidth];
#include <assert.h>
void load_image(t_renderer* r, int* texture, char* path, t_image* img) {
  (void)texture;
  // TODO: make image self-contained object with methods
  img->img_ref = mlx_xpm_file_to_image(r->mlx, path, (int*)&img->size.width,
                                       (int*)&img->size.height);
  assert(img->img_ref != NULL);
  img->data = (int*)mlx_get_data_addr(img->img_ref, &img->bits_per_pixel,
                                      &img->line_size, &img->endian);
  for (t_uint y = 0; y < img->size.height; y++) {
    for (t_uint x = 0; x < img->size.width; x++) {
      texture[img->size.width * y + x] = img->data[img->size.width * y + x];
    }
  }
  mlx_destroy_image(r->mlx, img->img_ref);
}

void renderer__init_texture(t_renderer* r) {
  (void)r;
  t_image img;

  load_image(r, texture[0], "asset/eagle.xpm", &img);
  load_image(r, texture[1], "asset/redbrick.xpm", &img);
  load_image(r, texture[2], "asset/purplestone.xpm", &img);
  load_image(r, texture[3], "asset/greystone.xpm", &img);
  load_image(r, texture[4], "asset/bluestone.xpm", &img);
  load_image(r, texture[5], "asset/mossy.xpm", &img);
  load_image(r, texture[6], "asset/wood.xpm", &img);
  load_image(r, texture[7], "asset/colorstone.xpm", &img);
  load_image(r, texture[8], "asset/barrel.xpm", &img);
  load_image(r, texture[9], "asset/pillar.xpm", &img);
  load_image(r, texture[10], "asset/greenlight.xpm", &img);
}

int spriteOrder[numSprites];
double spriteDistance[numSprites];
t_entity sprite[numSprites] = {
    // green light in front of playerstart
    (t_entity){{20.5, 11.5}, 10},

    // green lights in every room
    (t_entity){{18.5, 4.5}, 10},
    (t_entity){{10.0, 4.5}, 10},
    (t_entity){{10.0, 12.5}, 10},
    (t_entity){{3.5, 6.5}, 10},
    (t_entity){{3.5, 20.5}, 10},
    (t_entity){{3.5, 14.5}, 10},
    (t_entity){{14.5, 20.5}, 10},

    // row of pillars in front of wall}: fisheye test
    (t_entity){{18.5, 10.5}, 9},
    (t_entity){{18.5, 11.5}, 9},
    (t_entity){{18.5, 12.5}, 9},

    // some barrels around the map
    (t_entity){{21.5, 1.5}, 8},
    (t_entity){{15.5, 1.5}, 8},
    (t_entity){{16.0, 1.8}, 8},
    (t_entity){{16.2, 1.2}, 8},
    (t_entity){{3.5, 2.5}, 8},
    (t_entity){{9.5, 15.5}, 8},
    (t_entity){{10.0, 15.1}, 8},
    (t_entity){{10.5, 15.8}, 8},
};

void sort_order(t_pair* orders, int amount) {
  t_pair tmp;

  for (int i = 0; i < amount; i++) {
    for (int j = 0; j < amount - 1; j++) {
      if (orders[j].first > orders[j + 1].first) {
        tmp.first = orders[j].first;
        tmp.second = orders[j].second;
        orders[j].first = orders[j + 1].first;
        orders[j].second = orders[j + 1].second;
        orders[j + 1].first = tmp.first;
        orders[j + 1].second = tmp.second;
      }
    }
  }
}

#include <stdlib.h>
#include "std__system.h"
void sortSprites(int* order, double* dist, int amount) {
  t_pair* sprites;

  // std::vector<std::pair<double, int>> sprites(amount);
  sprites = std__allocate(amount, sizeof(t_pair));
  // sprites = malloc(sizeof(t_pair) * amount);
  for (int i = 0; i < amount; i++) {
    sprites[i].first = dist[i];
    sprites[i].second = order[i];
  }
  sort_order(sprites, amount);
  // std::sort(sprites.begin(), sprites.end());
  for (int i = 0; i < amount; i++) {
    dist[i] = sprites[amount - i - 1].first;
    order[i] = sprites[amount - i - 1].second;
  }
  free(sprites);
}
