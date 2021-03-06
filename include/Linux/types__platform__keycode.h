/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types__platform__keycode.h                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youkim    <youkim@student.42seoul.kr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 10:13:06 by youkim            #+#    #+#             */
/*   Updated: 2022/05/04 10:13:06 by youkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES__PLATFORM__KEYCODE_H
# define TYPES__PLATFORM__KEYCODE_H

// TODO: add KEY_SHIFT
typedef enum e_keycode
{
	KEY_A = 97,
	KEY_B,
	KEY_C,
	KEY_D,
	KEY_E,
	KEY_F,
	KEY_G,
	KEY_H,
	KEY_I,
	KEY_J,
	KEY_K,
	KEY_L,
	KEY_M,
	KEY_N,
	KEY_O,
	KEY_P,
	KEY_Q,
	KEY_R,
	KEY_S,
	KEY_T,
	KEY_U,
	KEY_V,
	KEY_W,
	KEY_X,
	KEY_Y,
	KEY_Z,
	KEY_0 = 48,
	KEY_1,
	KEY_2,
	KEY_3,
	KEY_4,
	KEY_5,
	KEY_6,
	KEY_7,
	KEY_8,
	KEY_9,
	KEY_UP = 65362,
	KEY_DOWN = 65364,
	KEY_LEFT = 65361,
	KEY_RIGHT = 65363,
	KEY_ESC = 65307,
	KEY_SPACE = 32,
	KEY_ENTER = 65293,
	KEY_MINUS = 45,
	KEY_EQUAL = 61,
	KEY_BACKSPACE = 65288,
	KEY_TAB = 65289,
	KEY_LEFT_BRACKET = 91,
	KEY_RIGHT_BRACKET = 93,
	KEY_BACKSLASH = 92,
	KEY_SEMICOLON = 59,
	KEY_APOSTROPHE = 39,
	KEY_GRAVE = 96,
	KEY_COMMA = 44,
	KEY_PERIOD = 46,
	KEY_SLASH = 47,
	KEY_CAPS_LOCK = 65307,
	KEY_SHIFT = 65505,
	KEY_NUMPAD_DIV = 65455,
	KEY_NUMPAD_MUL = 65450,
	KEY_NUMPAD_MIN = 65453,
	KEY_NUMPAD_PLU = 65451,
}	t_keycode;

typedef enum e_mousecode
{
	MOUSE_LEFT = 1,
	MOUSE_RIGHT = 3,
	MOUSE_MIDDLE = 2,
	MOUSE_SCROLL_UP = 4,
	MOUSE_SCROLL_DOWN = 5,
}	t_mousecode;

#endif
