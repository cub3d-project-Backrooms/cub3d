#include "renderer.h"
#include <stdlib.h>

// FIXME: implement key library
int key_release(t_keycode key, t_renderer *this) {
  if (key == KEY_W)
    this->keyinfo.is_up_pressed = false;
  if (key == KEY_S)
    this->keyinfo.is_down_pressed = false;
  if (key == KEY_A)
    this->keyinfo.is_left_pressed = false;
  if (key == KEY_D)
    this->keyinfo.is_right_pressed = false;
  return 0;
}

int key_press(t_keycode key, t_renderer *this) {
  if (key == KEY_W)
    this->keyinfo.is_up_pressed = true;
  if (key == KEY_S)
    this->keyinfo.is_down_pressed = true;
  if (key == KEY_A)
    this->keyinfo.is_left_pressed = true;
  if (key == KEY_D)
    this->keyinfo.is_right_pressed = true;
  if (key == KEY_ESC)
    exit(0);

  return (0);
}
