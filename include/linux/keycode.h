#ifndef KEY_LINUX_H
# define KEY_LINUX_H

typedef enum e_keycode {
  KEY_A = 97,
  KEY_B = 98,
  KEY_C = 99,
  KEY_D = 100,
  KEY_E = 101,
  KEY_F = 102,
  KEY_G = 103,
  KEY_H = 104,
  KEY_I = 105,
  KEY_J = 106,
  KEY_K = 107,
  KEY_L = 108,
  KEY_M = 109,
  KEY_N = 110,
  KEY_O = 111,
  KEY_P = 112,
  KEY_Q = 113,
  KEY_R = 114,
  KEY_S = 115,
  KEY_T = 116,
  KEY_U = 117,
  KEY_V = 118,
  KEY_W = 119,
  KEY_X = 120,
  KEY_Y = 121,
  KEY_Z = 122,

  KEY_UP = 65362,
  KEY_DOWN = 65364,
  KEY_LEFT = 65361,
  KEY_RIGHT = 65363,

  KEY_NUMPAD_DIV = 65455,
  KEY_NUMPAD_MUL = 65450,
  KEY_NUMPAD_MIN = 65453,
  KEY_NUMPAD_PLU = 65451,

  KEY_ESC = 65307,
  KEY_SPACE = 32,
  KEY_ENTER = -1, // TODO: FIX IT


} t_keycode;

typedef enum e_mousecode {
  MOUSE_LEFT = 1,
  MOUSE_RIGHT = 3,
  MOUSE_MIDDLE = 2,
  MOUSE_SCROLL_UP = 4,
  MOUSE_SCROLL_DOWN = 5,
} t_mousecode;

#endif
