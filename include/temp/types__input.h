#ifndef TYPES__INPUT_H
#define TYPES__INPUT_H

#include "types__platform__keycode.h"

typedef struct s_engine__inputhandler {
  int arrows[4];
  int mouse[5];
  int alphabets[KEY_Z - KEY_A + 1];
  int numbers[10];
} t_engine__inputhandler;

#endif

/*
bitset
0 ~ 65535
2^16
*/
