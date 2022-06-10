/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deinit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youkim    <youkim@student.42seoul.kr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 10:13:06 by youkim            #+#    #+#             */
/*   Updated: 2022/05/04 10:13:06 by youkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "renderer.h"
#include <stdlib.h>

void	world__deinit(t_world *this)
{
	int	i;

	i = -1;
	while (++i < this->world_height)
		free(this->worldmap[i]);
	free(this->worldmap);
	// free(this->sprites);
}

void	renderer__deinit(t_renderer *this)
{
	world__deinit(&this->world);
	mlx_destroy_image(this->mlx, this->buffer_window.img_ref);
	mlx_destroy_window(this->mlx, this->window);
}
