#include "mlx.h"
#include "types__renderer.h"

void	platform_mouse_get_pos(
	t_mlx__ref mlx, t_mlx__window_ref window, int *x, int *y)
{
	mlx_mouse_get_pos(mlx, window, x, y);
}

void	platform_mouse_move(
	t_mlx__ref mlx, t_mlx__window_ref window, int x, int y)
{
	mlx_mouse_move(mlx, window, x, y);
}
