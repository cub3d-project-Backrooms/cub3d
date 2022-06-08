/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   std__types__vector.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youkim    <youkim@student.42seoul.kr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 10:13:06 by youkim            #+#    #+#             */
/*   Updated: 2022/05/04 10:13:06 by youkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STD__TYPES__VECTOR_H
# define STD__TYPES__VECTOR_H

# include "std__types.h"

typedef void			*t_std__vector_item;

typedef enum e_vector__config
{
	VECTOR__INIT_CAPACITY = 16,
	VECTOR__DEFAULT_GROW_FACTOR = 2,
	VECTOR__DEBUG = true,
}						t_vector__config;

typedef struct s_std__vector
{
	t_destructor		destructor;
	t_std__vector_item	*items;
	t_u32				capacity;
	t_u32				size;
}						t_std__vector;

#endif
