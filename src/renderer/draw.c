#include "mlx.h"
#include "renderer.h"

const extern int	g_worldmap[24][24];

/**
 * @brief
 *
 * The pixel data is a single array of width * height * 4 bytes.
 * so it is also same as: array of
 * int * width, int * width, int * width...
 * hence it is indexed with [y * width + x].
 *
 * @param info
 */
void	renderer__draw_to_window(t_renderer *info)
{
	int	y;
	int	x;

	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
			info->buffer_window.data[y * WIDTH + x] = info->buf[y][x];
	}
	mlx_put_image_to_window(info->mlx, info->window,
		info->buffer_window.img_ref, 0, 0);
}

void	renderer__draw_buf_by_ivec(t_renderer *this, t_ivec *pos, int color)
{
	this->buf[pos->y][pos->x] = color;
}
