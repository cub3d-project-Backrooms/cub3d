#ifndef TYPES__PLATFORM__KEYCODE_H
#define TYPES__PLATFORM__KEYCODE_H

# define TILE_SIZE 64

# define EEND -1

typedef enum e_status
{
	PLAY,
	WIN,
	LOSE,
	SHUTDOWN
}	t_status;

typedef enum e_keycode
{
	KEY_A = 0,
	KEY_B = 11,
	KEY_C = 8,
	KEY_D = 2,
	KEY_E = 14,
	KEY_F = 3,
	KEY_G = 5,
	KEY_H = 4,
	KEY_I = 34,
	KEY_J = 38,
	KEY_K = 40,
	KEY_L = 37,
	KEY_M = 50,
	KEY_N = 45,
	KEY_O = 31,
	KEY_P = 35,
	KEY_Q = 12,
	KEY_R = 15,
	KEY_S = 1,
	KEY_T = 17,
	KEY_U = 32,
	KEY_V = 9,
	KEY_W = 13,
	KEY_X = 7,
	KEY_Y = 16,
	KEY_Z = 6,

	KEY_0 = 29,
	KEY_1 = 18,
	KEY_2 = 19,
	KEY_3 = 20,
	KEY_4 = 21,
	KEY_5 = 23,
	KEY_6 = 22,
	KEY_7 = 26,
	KEY_8 = 28,
	KEY_9 = 25,

	KEY_UP = 126,
	KEY_DOWN = 125,
	KEY_LEFT = 123,
	KEY_RIGHT = 124,

	KEY_ESC = 53,
	KEY_SPACE = 49,
	KEY_ENTER = 36,

	KEY_MINUS = 27,
	KEY_EQUAL = 24,
	KEY_BACKSPACE = 51,
	KEY_TAB = 48,
	KEY_LEFT_BRACKET = 33,
	KEY_RIGHT_BRACKET = 30,
	KEY_BACKSLASH = 42,
	KEY_SEMICOLON = 41,
	KEY_APOSTROPHE = 39,
	KEY_GRAVE = 43,
	KEY_COMMA = 54,
	KEY_PERIOD = 55,
	KEY_SLASH = 56,
	KEY_CAPS_LOCK = 57,
}	t_keycode;

typedef enum e_mousecode
{
	MOUSE_LEFT = 1,
	MOUSE_RIGHT = 2,
	MOUSE_MIDDLE = 3,
	MOUSE_SCROLL_UP = 4,
	MOUSE_SCROLL_DOWN = 5,
}	t_mousecode;

#endif
