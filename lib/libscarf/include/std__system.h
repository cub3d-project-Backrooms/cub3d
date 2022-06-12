/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   std__system.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youkim    <youkim@student.42seoul.kr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 10:13:06 by youkim            #+#    #+#             */
/*   Updated: 2022/05/04 10:13:06 by youkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STD__SYSTEM_H
# define STD__SYSTEM_H

# include "std__types.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 255
# endif
# ifndef OPEN_MAX
#  define OPEN_MAX 256
# endif

//@func
/*
** < alloc.c > */

void		*std__calloc(size_t count, size_t size);
void		*std__allocate(size_t count, size_t size);
void		std__deallocate(void **ptr_ptr);
/*
** < mem.c > */

void		*std__memset(void *ptr, char c, int count);
void		*std__bzero(void *ptr, int count);
void		*std__memcpy(void *dst, const void *src, size_t count);
/*
** < read.c > */

int			std__read(t_fd fd, char *buffer, t_uint size);
bool		read__is_eof(int len);
t_fd		std__open(t_const_string path, int flags);
/*
** < read__file.c > */

t_string	std__new_readfile__line(t_fd fd);
/*
** < write.c > */

int			std__write(int fd, t_const_string str);
int			std__writes(int fd, t_const_string arr[]);
#endif
