/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youkim <youkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 10:13:06 by youkim            #+#    #+#             */
/*   Updated: 2022/05/04 15:06:16 by youkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include "parser.h"
#include "types__renderer.h"
#include "std__system.h"
#include "std__color.h"

void	parser__init(t_parser *this, t_const_string file)
{
	int			i;

	i = -1;
	while (++i < 6)
		this->found_cubid[i] = false;
	if (!str__ends_with(file, ".cub"))
		std__panic__value("parser__init", "file must end with .cub");
	this->fd = std__open(file, O_RDONLY);
}

void	parser__parse(t_parser *this, t_world *world)
{
	parser__parse__id(this, world);
	parser__parse__map(this, world);
}
