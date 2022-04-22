#include "engine.h"
#include "renderer.h"
#include "std__system.h"
#include "types__x11_events.h"

void	renderer__init__mlx(t_renderer *this)
{
	this->mlx = mlx_init();
	this->window = mlx_new_window(this->mlx, WIDTH, HEIGHT, "cub3d");
}

void	renderer__init(t_renderer *this, t_world *world)
{
	renderer__init__mlx(this);
	this->buffer_window.img_ref = mlx_new_image(this->mlx, WIDTH, HEIGHT);
	this->buffer_window.data = (int *)mlx_get_data_addr(
			this->buffer_window.img_ref, &this->buffer_window.bits_per_pixel,
			&this->buffer_window.line_size, &this->buffer_window.endian);
	this->world = *world;
	renderer__init_texture(this);
}
