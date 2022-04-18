#include "std__system.h"
#include "std__types.h"
#include "types__input.h"

// t_inputhandler__keybind_list inputhandler__keybind_list__impl__new(
//     t_uint keybind_size, t_uint keybind_alternatives, int keybinds[]) {
//   int i;
//   int j;
//   t_inputhandler__keybind_list list;

//   list.keybind_size = keybind_size;
//   list.keybind_alternatives = keybind_alternatives;
//   list.keybinds =
//       std__allocate(keybind_size * keybind_alternatives, sizeof(int));

//   i = -1;
//   while (++i < keybind_alternatives) {
//     j = -1;
//     while (++j < keybind_size)
//       list.keybinds[i * keybind_size + j] = keybinds[j];
//   }
//   return list;
// }

t_inputhandler inputhandler__init() {
  t_inputhandler inputhandler;

  // inputhandler__keybind_list__impl__new(&inputhandler.arrows__keymap,
  //                                 INPUTHANDLER__NUM_ARROWS, 2,
  //                                 (int[]){KEY_UP, KEY_DOWN, KEY_LEFT,
  //                                 KEY_RIGHT,
  //                                         KEY_W, KEY_S, KEY_A, KEY_D});
  inputhandler.arrows__status[INPUTHANDLER__KEY_STATUS__UP] = 0;
  inputhandler.arrows__status[INPUTHANDLER__KEY_STATUS__DOWN] = 0;
  return inputhandler;
}

#include <stdio.h>
int inputhandler__key_press(t_keycode key, t_inputhandler *handler) {
  int i;
  int j;
  t_keycode candidate;

  printf("pressed %d\n", key);
  i = -1;
  while (++i < INPUTHANDLER__ALTERNATIVE_ARROWS) {
    j = -1;
    while (++j < INPUTHANDLER__NUM_ARROWS) {
      candidate = handler->arrows__keymap[i * INPUTHANDLER__NUM_ARROWS + j];
      if (key == candidate) {
        handler->arrows__status[i] = true;
        printf("press match!!! %d\n", key);
        break;
      }
    }
  }
  return (0);
}
// int inputhandler__key_release(t_keycode key, t_inputhandler *handler) {
//   int i;

//   i = -1;
//   while (++i < INPUTHANDLER__NUM_ARROWS) {
//     if (handler->arrows_keymap[i] == key)
//       handler->arrows[i] = 0;
//   }
//   return (0);
// }
