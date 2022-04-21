#include "engine.h"
#include "renderer.h"
#include "std__types.h"

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

// TODO: make it stored where?
int			texture[8][TEX_HEIGHT * TEX_WIDTH];
#include <assert.h>
#include <stdio.h>
void	load_image(t_renderer *r, int *texture, char *path, t_image *img)
{
	(void)texture;
	// TODO: make image self-contained object with methods
	// printf("loading %s\n", path);
	img->img_ref = mlx_xpm_file_to_image(r->mlx, path, (int *)&img->size.width,
			(int *)&img->size.height);
	assert(img->img_ref != NULL);
	img->data = (int *)mlx_get_data_addr(img->img_ref, &img->bits_per_pixel,
			&img->line_size, &img->endian);
	for (t_uint y = 0; y < img->size.height; y++)
	{
		for (t_uint x = 0; x < img->size.width; x++)
		{
			texture[img->size.width * y + x] = img->data[img->size.width * y
				+ x];
		}
	}
	mlx_destroy_image(r->mlx, img->img_ref);
}

void	renderer__init_texture(t_renderer *r)
{
	t_image	img;

	(void)r;
	// load_image(r, texture[0], "asset/texture/wolf/eagle.xpm", &img);
	// load_image(r, texture[1], "asset/texture/wolf/redbrick.xpm", &img);
	// load_image(r, texture[2], "asset/texture/wolf/purplestone.xpm", &img);
	// load_image(r, texture[3], "asset/texture/wolf/greystone.xpm", &img);
	// load_image(r, texture[4], "asset/texture/wolf/bluestone.xpm", &img);
	// load_image(r, texture[5], "asset/texture/wolf/mossy.xpm", &img);
	// load_image(r, texture[6], "asset/texture/wolf/wood.xpm", &img);
	// load_image(r, texture[7], "asset/texture/wolf/colorstone.xpm", &img);

	load_image(r, texture[0], "asset/texture/backroom/wall1.xpm", &img);
	load_image(r, texture[1], "asset/texture/backroom/wall2.xpm", &img);
	load_image(r, texture[2], "asset/texture/backroom/wall3.xpm", &img);
	load_image(r, texture[3], "asset/texture/backroom/light0.xpm", &img);
	load_image(r, texture[4], "asset/texture/backroom/glass.xpm", &img);
	load_image(r, texture[5], "asset/texture/backroom/floor1.xpm", &img);
	load_image(r, texture[6], "asset/texture/backroom/floor0.xpm", &img);
	load_image(r, texture[7], "asset/texture/backroom/wall0.xpm", &img);
}
