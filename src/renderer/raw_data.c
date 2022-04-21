#include "engine.h"
#include "renderer.h"
#include "std__types.h"
#include "std__system.h"

void	load_image(t_renderer *r, int *texture, char *path, t_image *img)
{
	t_uint y;
	t_uint x;

	img->img_ref = mlx_xpm_file_to_image(r->mlx, path, (int *)&img->size.width,
			(int *)&img->size.height);
	img->data = (int *)mlx_get_data_addr(img->img_ref, &img->bits_per_pixel,
			&img->line_size, &img->endian);
	y = -1;
	while (++y < img->size.height)
	{
		x = -1;
		while (++x < img->size.width)
			texture[img->size.width * y + x] = img->data[img->size.width * y + x];
	}
	mlx_destroy_image(r->mlx, img->img_ref);
}

void	renderer__init_texture(t_renderer *r)
{
	r->world.tex_name[WNORTH] = "backroom/wall0.xpm";
	r->world.tex_name[WSOUTH] = "backroom/wall1.xpm";
	r->world.tex_name[WEAST] = "backroom/wall2.xpm";
	r->world.tex_name[WWEST] = "backroom/wall3.xpm";

	t_image	img;
	load_image(r, r->world.texture[WNORTH], r->world.tex_name[WNORTH], &img);
	load_image(r, r->world.texture[WSOUTH], r->world.tex_name[WSOUTH], &img);
	load_image(r, r->world.texture[WEAST], r->world.tex_name[WEAST], &img);
	load_image(r, r->world.texture[WWEST], r->world.tex_name[WWEST], &img);
	load_image(r, r->world.texture[FLOOR], FLOOR_PATH, &img);
	load_image(r, r->world.texture[CEILING], CEILING_PATH, &img);
	load_image(r, r->world.texture[CEILING2], CEILING2_PATH, &img);
}
