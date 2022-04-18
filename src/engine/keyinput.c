#include <stdlib.h>
#include "engine.h"

// FIXME: implement key library
int key_release(t_keycode key, t_engine* info) {
  if (key == KEY_W)
    info->keyinfo.is_up_pressed = false;
  if (key == KEY_S)
    info->keyinfo.is_down_pressed = false;
  if (key == KEY_A)
    info->keyinfo.is_left_pressed = false;
  if (key == KEY_D)
    info->keyinfo.is_right_pressed = false;
  return 0;
}

int key_press(t_keycode key, t_engine* info) {
  if (key == KEY_W)
    info->keyinfo.is_up_pressed = true;
  if (key == KEY_S)
    info->keyinfo.is_down_pressed = true;
  if (key == KEY_A)
    info->keyinfo.is_left_pressed = true;
  if (key == KEY_D)
    info->keyinfo.is_right_pressed = true;
  if (key == KEY_ESC)
    exit(0);

  return (0);
}
