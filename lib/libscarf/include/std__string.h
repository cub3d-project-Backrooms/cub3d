/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   std__string.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youkim    <youkim@student.42seoul.kr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 10:13:06 by youkim            #+#    #+#             */
/*   Updated: 2022/05/04 10:13:06 by youkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STD__STRING_H
# define STD__STRING_H

# include "std__error.h"
# include "std__types.h"
# include "std__types__error.h"

//@func
/*
** < alloc.c > */

t_string			str__new(t_const_string from);
t_string			str__new_move(t_string *other);
t_string			str__new_size(t_uint size);
t_string			str__new_char(t_uint size, char c);
t_string_arr		str__new__arr(t_uint size, t_string from[]);
/*
** < append.c > */

int					str__copy(t_string this, t_const_string src, int size);
int					str__append(t_string *this, t_const_string src);
/*
** < cmp.c > */

int					str__ncmp(t_const_string s1, t_const_string s2, int n);
bool				str__is_equal(t_const_string s1, t_const_string s2);
/*
** < convert.c > */

t_string			str__new_from_int(int num);
t_int_res			str__to_int(t_const_string str);
/*
** < dealloc.c > */

void				str__delete(t_string *this);
void				str__delete__arr(t_string_arr *arr_ptr);
/*
** < find.c > */

t_int_or_neg_as_err	str__find(t_const_string this, t_const_string other);
t_int_or_neg_as_err	str__find_from(t_const_string this, t_const_string other,
						t_i64 from);
/*
** < find_of.c > */

t_int_or_neg_as_err	str__find_first_of(t_const_string this,
						t_const_string charset);
t_int_or_neg_as_err	str__find_first_not_of(t_const_string this,
						t_const_string charset);
t_int_or_neg_as_err	str__find_last_of(t_const_string this,
						t_const_string charset);
t_int_or_neg_as_err	str__find_last_not_of(t_const_string this,
						t_const_string charset);
/*
** < index.c > */

t_u8				str__at(t_const_string this, const int index);
bool				str__is_in(t_const_string this, char c);
/*
** < len.c > */

t_int_or_neg_as_err	str__len(t_const_string this);
t_int_or_neg_as_err	str__len__arr(t_string arr[]);
/*
** < move.c > */

void				str__move(t_string *this, t_string *other);
void				str__replace(t_string *this, t_string other);
void				str__merge(t_string *this, t_string *other);
void				str__swap(t_string *this, t_string *other);
/*
** < slice.c > */

t_string			str__new_substr(t_const_string this, t_uint start,
						t_int_or_neg_as_flag len);
/*
** < split.c > */

t_int_or_neg_as_err	str__count_of(t_const_string str, t_const_string other);
t_string			*str__new_split(t_const_string str, t_const_string delim);
/*
** < strip.c > */

void				str__lstrip(t_string *this, t_const_string charset);
void				str__rstrip(t_string *this, t_const_string charset);
void				str__strip(t_string *this, t_const_string charset);
/*
** < util.c > */

bool				str__is_empty(t_const_string this);
void				str__pad_right(t_string *this, t_uint len, char c);
void				str__pad_left(t_string *this, t_uint len, char c);
bool				str__ends_with(t_const_string this, t_const_string other);
#endif
