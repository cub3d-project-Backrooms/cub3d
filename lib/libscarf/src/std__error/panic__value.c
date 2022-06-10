/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   panic__value.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youkim    <youkim@student.42seoul.kr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 10:13:06 by youkim            #+#    #+#             */
/*   Updated: 2022/05/04 10:13:06 by youkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "std__color.h"
#include "std__string.h"
#include "std__system.h"
#include <errno.h>
#include <stdlib.h>
#include <unistd.h>

void	std__panic__value(t_const_string where, t_const_string what)
{
	std__panic_write_internal(
		(t_const_string[]){where, " value error", what, NULL});
	exit(EXIT_FAILURE);
}

void	std__panic__value__char(t_const_string where, char what)
{
	const char	charstr[4] = {'\'', what, '\'', '\0'};

	std__panic_write_internal(
		(t_const_string[]){where, " value error", charstr, NULL});
	exit(EXIT_FAILURE);
}
