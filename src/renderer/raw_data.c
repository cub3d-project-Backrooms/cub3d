#include "engine.h"
#include "renderer.h"
#include "std__types.h"
#include "std__system.h"

int			g_worldmap[mapWidth][mapHeight] = {
	{8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 4, 4, 6, 4, 4, 6, 4, 6, 4, 4, 4, 6, 4},
	{8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4},
	{8, 0, 3, 3, 0, 0, 0, 0, 0, 8, 8, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 6},
	{8, 0, 0, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 6},
	{8, 0, 3, 3, 0, 0, 0, 0, 0, 8, 8, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4},
	{8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8, 4, 0, 0, 0, 0, 0, 6, 6, 6, 0, 6, 4, 6},
	{8, 8, 8, 8, 0, 8, 8, 8, 8, 8, 8, 4, 4, 4, 4, 4, 4, 6, 0, 0, 0, 0, 0, 6},
	{7, 7, 7, 7, 0, 7, 7, 7, 7, 0, 8, 0, 8, 0, 8, 0, 8, 4, 0, 4, 0, 6, 0, 6},
	{7, 7, 0, 0, 0, 0, 0, 0, 7, 8, 0, 8, 0, 8, 0, 8, 8, 6, 0, 0, 0, 0, 0, 6},
	{7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8, 6, 0, 0, 0, 0, 0, 4},
	{7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8, 6, 0, 6, 0, 6, 0, 6},
	{7, 7, 0, 0, 0, 0, 0, 0, 7, 8, 0, 8, 0, 8, 0, 8, 8, 6, 4, 6, 0, 6, 6, 6},
	{7, 7, 7, 7, 0, 7, 7, 7, 7, 8, 8, 4, 0, 6, 8, 4, 8, 3, 3, 3, 0, 3, 3, 3},
	{2, 2, 2, 2, 0, 2, 2, 2, 2, 4, 6, 4, 0, 0, 6, 0, 6, 3, 0, 0, 0, 0, 0, 3},
	{2, 2, 0, 0, 0, 0, 0, 2, 2, 4, 0, 0, 0, 0, 0, 0, 4, 3, 0, 0, 0, 0, 0, 3},
	{2, 0, 0, 0, 0, 0, 0, 0, 2, 4, 0, 0, 0, 0, 0, 0, 4, 3, 0, 0, 0, 0, 0, 3},
	{1, 0, 0, 0, 0, 0, 0, 0, 1, 4, 4, 4, 4, 4, 6, 0, 6, 3, 3, 0, 0, 0, 3, 3},
	{2, 0, 0, 0, 0, 0, 0, 0, 2, 2, 2, 1, 2, 2, 2, 6, 6, 0, 0, 5, 0, 5, 0, 5},
	{2, 2, 0, 0, 0, 0, 0, 2, 2, 2, 0, 0, 0, 2, 2, 0, 5, 0, 5, 0, 0, 0, 5, 5},
	{2, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 2, 5, 0, 5, 0, 5, 0, 5, 0, 5},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5},
	{2, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 2, 5, 0, 5, 0, 5, 0, 5, 0, 5},
	{2, 2, 0, 0, 0, 0, 0, 2, 2, 2, 0, 0, 0, 2, 2, 0, 5, 0, 5, 0, 0, 0, 5, 5},
	{2, 2, 2, 2, 1, 2, 2, 2, 2, 2, 2, 1, 2, 2, 2, 5, 5, 5, 5, 5, 5, 5, 5, 5}};


#include <assert.h>
#include <stdio.h>
void	load_image(t_renderer *r, int *texture, char *path, t_image *img)
{
	// TODO: make image self-contained object with methods
	// printf("loading %s\n", path);
	img->img_ref = mlx_xpm_file_to_image(r->mlx, path, (int *)&img->size.width,
			(int *)&img->size.height);
	assert(img->img_ref != NULL);
	img->data = (int *)mlx_get_data_addr(img->img_ref, &img->bits_per_pixel,
			&img->line_size, &img->endian);
	for (t_uint y = 0; y < img->size.height; y++)
		for (t_uint x = 0; x < img->size.width; x++)
			texture[img->size.width * y + x] = img->data[img->size.width * y + x];
	mlx_destroy_image(r->mlx, img->img_ref);
}

void	renderer__init_texture(t_renderer *r)
{
	r->world.tex_name[NORTHWALL] = "asset/texture/wolf/eagle.xpm";
	r->world.tex_name[SOUTHWALL] = "asset/texture/wolf/redbrick.xpm";
	r->world.tex_name[EASTWALL] = "asset/texture/wolf/purplestone.xpm";
	r->world.tex_name[WESTWALL] = "asset/texture/wolf/greystone.xpm";
	r->world.tex_name[FLOOR] = "asset/texture/wolf/bluestone.xpm";
	r->world.tex_name[CEILING] = "asset/texture/wolf/mossy.xpm";
	r->world.tex_name[FLOOR2] = "asset/texture/wolf/wood.xpm";
	r->world.tex_name[CEILING2] = "asset/texture/wolf/colorstone.xpm";

	t_image	img;
	int			texture[TEX_AMOUNT][r->world.tex_height * r->world.tex_width];
	load_image(r, texture[NORTHWALL], r->world.tex_name[NORTHWALL], &img);
	load_image(r, texture[SOUTHWALL], r->world.tex_name[SOUTHWALL], &img);
	load_image(r, texture[EASTWALL], r->world.tex_name[EASTWALL], &img);
	load_image(r, texture[WESTWALL], r->world.tex_name[WESTWALL], &img);
	load_image(r, texture[FLOOR], r->world.tex_name[FLOOR], &img);
	load_image(r, texture[CEILING], r->world.tex_name[CEILING], &img);
	load_image(r, texture[FLOOR2], r->world.tex_name[FLOOR2], &img);
	load_image(r, texture[CEILING2], r->world.tex_name[CEILING2], &img);
	r->world.texture = std__allocate(TEX_AMOUNT, sizeof(int *));
	for (int i = 0; i < TEX_AMOUNT; ++i)
		r->world.texture[i] = std__allocate(r->world.tex_height * r->world.tex_width, sizeof(int));
	for (int i = 0; i < TEX_AMOUNT; ++i)
		for (int j = 0; j < r->world.tex_height * r->world.tex_width; ++j)
			r->world.texture[i][j] = texture[i][j];
}
