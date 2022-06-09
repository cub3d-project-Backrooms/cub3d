/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youkim    <youkim@student.42seoul.kr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 10:13:06 by youkim            #+#    #+#             */
/*   Updated: 2022/05/04 10:13:06 by youkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENGINE_H
# define ENGINE_H

# include "types__engine.h"
# include "types__renderer.h"

//@func
/*
** < collision.c > */

bool				is_collision_with_wall(t_world *world, const t_ivec *pos);
/*
** < door.c > */

void				engine__toggle_door(t_engine *this);
/*
** < init.c > */

int					engine__deinit(t_engine *this);
void				engine__init(t_engine *this, t_world *world);
/*
** < keyinput.c > */

t_inputhandler		inputhandler__init(void);
bool				inputhandler__is_movement(t_inputhandler *this);
inline static void	inputhandler__key_action(t_keycode key,
						t_inputhandler *this, bool value);
int					inputhandler__key_release(t_keycode key,
						t_inputhandler *this);
int					inputhandler__key_press(t_keycode key,
						t_inputhandler *this);
/*
** < movement.c > */

void				engine__try_move_player(t_engine *e, const t_vec d);
void				engine__try_move_player_straight(t_engine *e, t_sign dir);
void				engine__try_strafe_player(t_engine *e, t_sign dir);
void				engine__rotate_player(t_engine *e, double angle);
void				engine__move_player(t_engine *e);
/*
** < run.c > */

void				engine__refresh(t_engine *this);
void				engine__set_movespeed(t_engine *this);
int					engine__loop(t_engine *this);
void				engine__run(t_engine *this);
#endif
