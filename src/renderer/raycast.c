#include "engine.h"
#include "renderer.h"
#include "types__color.h"
#include "types__renderer.h"
#include <math.h>

const extern int worldMap[24][24];

bool is_raycast_refresh(t_inputhandler__keyinfo keyinfo) {
  return (keyinfo.is_up_pressed || keyinfo.is_down_pressed ||
          keyinfo.is_left_pressed || keyinfo.is_right_pressed);
}

t_colors get_color(int map_y, int map_x) {
  const t_colors colors[] = {
      COLOR__YELLOW, COLOR__RED, COLOR__GREEN, COLOR__BLUE, COLOR__WHITE,
  };
  const int index = worldMap[map_y][map_x];
  if (index > 4)
    return colors[0];
  return colors[index];
}

bool is_ray_hit_wall(const t_ivec *pos) {
  return (worldMap[pos->x][pos->y] > 0);
}

t_vec camera__cast_ray(t_camera *this, double x) {
  return (t_vec){this->dir.x + this->plane.x * x,
                 this->dir.y + this->plane.y * x};
}

t_ivec camera__to_pos_at_map(t_camera *this) {
  return (t_ivec){(int)this->pos.x, (int)this->pos.y};
}

// length of ray from one x or y-side to next x or y-side
t_vec raycast__dist_to_next_closest_wall(t_vec ray_dir) {
  return (t_vec){fabs(1 / ray_dir.x), fabs(1 / ray_dir.y)};
}

void raycast(t_renderer *e) {
  t_camera *cam = &e->camera;
  clear_grid(e->buf);

  for (int x = 0; x < WIDTH; x++) {
    double cameraX = 2 * x / (double)WIDTH - 1;
    t_vec ray_dir = camera__cast_ray(cam, cameraX);
    t_ivec map_pos = camera__to_pos_at_map(cam);

    t_vec delta_dist = raycast__dist_to_next_closest_wall(ray_dir);

    // what direction to step in x or y-direction (either +1 or -1)
    t_ivec step;

    int side; // was a NS or a EW wall hit?

    // length of ray from current position to next x or y-side
    t_vec side_dist;
    if (ray_dir.x < 0) {
      step.x = -1;
      side_dist.x = (cam->pos.x - map_pos.x) * delta_dist.x;
    } else {
      step.x = 1;
      side_dist.x = (map_pos.x + 1.0 - cam->pos.x) * delta_dist.x;
    }
    if (ray_dir.y < 0) {
      step.y = -1;
      side_dist.y = (cam->pos.y - map_pos.y) * delta_dist.y;
    } else {
      step.y = 1;
      side_dist.y = (map_pos.y + 1.0 - cam->pos.y) * delta_dist.y;
    }

    while (!is_ray_hit_wall(&map_pos)) {
      // jump to next map square, OR in x-direction, OR in y-direction
      if (side_dist.x < side_dist.y) {
        side_dist.x += delta_dist.x;
        map_pos.x += step.x;
        side = 0;
      } else {
        side_dist.y += delta_dist.y;
        map_pos.y += step.y;
        side = 1;
      }
    }

    double perpWallDist;
    if (side == 0)
      perpWallDist = (map_pos.x - cam->pos.x + (1 - step.x) / 2) / ray_dir.x;
    else
      perpWallDist = (map_pos.y - cam->pos.y + (1 - step.y) / 2) / ray_dir.y;

    // Calculate HEIGHT of line to draw on screen
    int lineHeight = (int)(HEIGHT / perpWallDist);

    // calculate lowest and highest pixel to fill in current stripe
    int drawStart = -lineHeight / 2 + HEIGHT / 2;
    if (drawStart < 0)
      drawStart = 0;
    int drawEnd = lineHeight / 2 + HEIGHT / 2;
    if (drawEnd >= HEIGHT)
      drawEnd = HEIGHT - 1;

    int color = get_color(map_pos.y, map_pos.x);

    if (side == 1)
      color = color / 2;

    for (int y = drawStart; y < drawEnd; y++)
      e->buf[y][x] = color;
  }
}
