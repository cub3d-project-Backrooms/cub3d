#include "renderer.h"
#include <stdlib.h>

void	world__deinit(t_world *this)
{
	int	i;

	i = -1;
	while (++i < this->world_width)
		free(this->worldmap[i]);
	free(this->worldmap);
}

void	renderer__deinit(t_renderer *this)
{
	world__deinit(&this->world);
	mlx_destroy_image(this->mlx, this->buffer_window.img_ref);
	mlx_destroy_window(this->mlx, this->window);
}
