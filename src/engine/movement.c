#include <math.h>
#include <stdio.h>
#include "engine.h"
#include "renderer.h"
#include "std__math.h"

const extern int worldMap[24][24];

static bool is_collision_with_wall(const t_vec* pos) {
  return (worldMap[(int)pos->x][(int)pos->y] > 0);
}

void engine__try_move_player(t_engine* e, double x, double y) {
  const double dx = x * e->camera.dir.x * e->moveSpeed;
  const double dy = y * e->camera.dir.y * e->moveSpeed;

  if (!is_collision_with_wall(&(t_vec){e->camera.pos.x + dx, e->camera.pos.y}))
    e->camera.pos.x += dx;
  if (!is_collision_with_wall(&(t_vec){e->camera.pos.x, e->camera.pos.y + dy}))
    e->camera.pos.y += dy;
}

// TODO: make it into camera method
// both camera direction and camera plane must be rotated
void engine__rotate_player(t_engine* e, double angle) {
  vec__rotate_assign(&e->camera.dir, -1 * angle * e->rotSpeed);
  vec__rotate_assign(&e->camera.plane, -1 * angle * e->rotSpeed);
}

void engine__move_player(t_engine* e) {
  t_inputhandler__keyinfo keyinfo = e->inputhandler.keyinfo;

  if (keyinfo.is_up_pressed)
    engine__try_move_player(e, 1, 1);
  if (keyinfo.is_down_pressed)
    engine__try_move_player(e, -1, -1);
  if (keyinfo.is_right_pressed)
    engine__rotate_player(e, 1);
  if (keyinfo.is_left_pressed)
    engine__rotate_player(e, -1);
}
