#include <math.h>
#include <stdio.h>
#include "renderer.h"
#include "std__math.h"

const extern int worldMap[24][24];

static bool is_collision_with_wall(const t_vec* pos) {
  return (worldMap[(int)pos->x][(int)pos->y] > 0);
}

static void engine__try_move_player(t_renderer* e, t_sign x_sign, t_sign y_sign) {
  const double dx = x_sign * e->dir.x * e->moveSpeed;
  const double dy = y_sign * e->dir.y * e->moveSpeed;

  if (!is_collision_with_wall(&(t_vec){e->pos.x + dx, e->pos.y}))
    e->pos.x += dx;
  if (!is_collision_with_wall(&(t_vec){e->pos.x, e->pos.y + dy}))
    e->pos.y += dy;
}

// both camera direction and camera plane must be rotated
static void engine__rotate_player(t_renderer* e, t_sign sign) {
  e->dir = vec__rotate(&e->dir, -1 * sign * e->rotSpeed);
  e->plane = vec__rotate(&e->plane, -1 * sign * e->rotSpeed);
}

void engine__move_player(t_renderer* e) {
  t_engine__keyinfo keyinfo = e->keyinfo;
  if (keyinfo.is_up_pressed)
    engine__try_move_player(e, 1, 1);
  if (keyinfo.is_down_pressed)
    engine__try_move_player(e, -1, -1);
  if (keyinfo.is_right_pressed)
    engine__rotate_player(e, PLUS);
  if (keyinfo.is_left_pressed)
    engine__rotate_player(e, MINUS);
}
