/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   platform__hook.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkim <tkim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 22:03:30 by tkim              #+#    #+#             */
/*   Updated: 2022/06/16 22:04:18 by tkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "types__renderer.h"

void	platform_mouse_get_pos(
	t_mlx__ref mlx, t_mlx__window_ref window, int *x, int *y)
{
	(void)mlx;
	mlx_mouse_get_pos(window, x, y);
}

void	platform_mouse_move(
	t_mlx__ref mlx, t_mlx__window_ref window, int x, int y)
{
	(void)mlx;
	mlx_mouse_move(window, x, y);
}
