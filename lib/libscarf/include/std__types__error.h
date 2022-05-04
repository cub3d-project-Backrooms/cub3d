/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   std__types__error.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youkim    <youkim@student.42seoul.kr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 10:13:06 by youkim            #+#    #+#             */
/*   Updated: 2022/05/04 10:13:06 by youkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STD__TYPES__ERROR_H
# define STD__TYPES__ERROR_H

typedef int	t_int_or_neg_as_err;
typedef int	t_int_or_neg_as_flag;

typedef enum e_res
{
	OK,
	ERR = -1,
	UNSET = -2,
}			t_res;

typedef struct s_int_res
{
	t_res	err;
	int		num;
}			t_int_res;

typedef enum e_neg_as_flag
{
	NEG_AS_FLAG__UNLIMITED = -1,
}			t_neg_as_flag;

#endif
