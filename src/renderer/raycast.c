#include <math.h>
#include "engine.h"
#include "renderer.h"
#include "std__math.h"
#include "types__color.h"
#include "types__renderer.h"

const extern int worldMap[24][24];

t_colors get_color(int map_y, int map_x) {
  const t_colors colors[] = {
      COLOR__YELLOW, COLOR__RED, COLOR__GREEN, COLOR__BLUE, COLOR__WHITE,
  };
  const int index = worldMap[map_y][map_x];
  if (index > 4)
    return colors[0];
  return colors[index];
}

void renderer__raycast__wall() {}

void renderer__raycast(t_renderer* this, t_camera* cam) {
  clear_grid(this->buf);

  for (int x = 0; x < WIDTH; x++) {
    double camera_x = dda__normalized_plane_x(x);
    t_vec ray_dir = camera__ray_dir_at_position(cam, camera_x);
    t_ivec map_pos = camera__to_pos_at_map(cam);
    t_vec delta_dist = dda__dist_to_next_closest_grid(&ray_dir);
    t_dda__step step = dda__initial_step(cam, &map_pos, &ray_dir, &delta_dist);
    dda__advance_step_until_hit(&step, &map_pos, &delta_dist);

    double perpWallDist =
        dda__perpendicular_dist_to_closest_grid(&step, cam, &map_pos, &ray_dir);

    // Calculate HEIGHT of line to draw on screen
    int lineHeight = (int)(HEIGHT / perpWallDist * 1);

    // calculate lowest and highest pixel to fill in current stripe
    {
      int draw_start = math__max(-lineHeight / 2 + HEIGHT / 2, 0);
      int draw_end = math__min(lineHeight / 2 + HEIGHT / 2, HEIGHT - 1);

      int color = get_color(map_pos.y, map_pos.x);

      if (step.is_hit_y_side)
        color = color / 2;

      for (int y = draw_start; y < draw_end; y++)
        this->buf[y][x] = color;
    }
  }
}
