#include <stdio.h>
#include "types__renderer.h"
#include "std__types__math.h"
#include "std__color.h"
#include "renderer.h"
#include "parser.h"

void	image__write_to_buffer(t_image *this, int texline[])
{
	t_i64vec	it;

	it.y = -1;
	while (++it.y < this->size.height)
	{
		it.x = -1;
		while (++it.x < this->size.width)
			texline[this->size.width * it.y + it.x]
				= this->data[this->size.width * it.y + it.x];
	}
}

void	image__init(t_image *this, t_mlx__ref mlx, t_string path)
{
	this->mlx_ref = mlx;
	this->img_ref = mlx_xpm_file_to_image(this->mlx_ref, path,
			(int *)&this->size.width, (int *)&this->size.height);
	if (not this->img_ref)
		std__panic__value("image__init: failed to load image from", path);
	this->data = (int *)mlx_get_data_addr(this->img_ref,
			&this->bits_per_pixel, &this->line_size, &this->endian);
	printf(CYN "🖼️ loaded %s\n" END, path);
}

void	image__deinit(t_image *this)
{
	mlx_destroy_image(this->mlx_ref, this->img_ref);
}
