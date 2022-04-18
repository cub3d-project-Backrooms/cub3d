#ifndef TYPES__INPUT_H
#define TYPES__INPUT_H

#include "types__platform__keycode.h"

typedef enum e_inputhandler__key_status__movement {
  INPUTHANDLER__KEY_STATUS__UP,
  INPUTHANDLER__KEY_STATUS__DOWN,
  INPUTHANDLER__KEY_STATUS__LEFT,
  INPUTHANDLER__KEY_STATUS__RIGHT,
  INPUTHANDLER__KEY_STATUS__ESC,
} t_inputhandler__key_status__movement;

typedef enum e_inputhandler__keybind {
  INPUTHANDLER__NUM_KEYBINDS = 1,
  INPUTHANDLER__NUM_ARROWS = 4,
  INPUTHANDLER__NUM_MOUSE = 5,
  INPUTHANDLER__NUM_NUMBERS = 10,
  INPUTHANDLER__NUM_ALPHABETS = 26,
} t_inputhandler__keybind;

typedef enum e_inputhandler__keybind__alternatives {
  INPUTHANDLER__ALTERNATIVE_ARROWS = 2,
  INPUTHANDLER__ALTERNATIVE_MOUSE = 1,
  INPUTHANDLER__ALTERNATIVE_NUMBERS = 1,
  INPUTHANDLER__ALTERNATIVE_ALPHABETS = 1,
} t_inputhandler__keybind__alternatives;

typedef struct s_inputhandler__keybind_list {
  t_uint keybind_size;
  t_uint keybind_alternatives;
  int *keybinds;
} t_inputhandler__keybind_list;

/**
 * @brief
 *
 * <type>__keybind will have numbers * (alternative keybinds)
 */
typedef struct s_inputhandler {
  // t_inputhandler__keybind_list arrows;
  // t_inputhandler_keybind_addr *addr_list;
  int arrows__status[INPUTHANDLER__NUM_ARROWS];
  int arrows__keymap[INPUTHANDLER__NUM_ARROWS *
                     INPUTHANDLER__ALTERNATIVE_ARROWS];
  // int mouse[5];
  // int mouse__keybind[5];
  // int alphabets[INPUTHANDLER__NUM_ALPHABETS];
  // int numbers[INPUTHANDLER__NUM_NUMBERS];
  // int numbers__keybind[INPUTHANDLER__NUM_NUMBERS];
} t_inputhandler;

#endif

/*
bitset
0 ~ 65535
2^16
*/
