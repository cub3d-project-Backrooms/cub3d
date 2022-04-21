#include "engine.h"
#include "renderer.h"
#include "std__types.h"
#include "std__system.h"
#include <assert.h>
#include <stdio.h>

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

void	load_image(t_renderer *r, int *texture, t_string path)
{
	t_image	image;

	image__init(&image, r->mlx, path);
	image__write_to_buffer(&image, texture);
	image__deinit(&image);
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

	int			texture[TEX_AMOUNT][r->world.tex_height * r->world.tex_width];
	load_image(r, texture[NORTHWALL], r->world.tex_name[NORTHWALL]);
	load_image(r, texture[SOUTHWALL], r->world.tex_name[SOUTHWALL]);
	load_image(r, texture[EASTWALL], r->world.tex_name[EASTWALL]);
	load_image(r, texture[WESTWALL], r->world.tex_name[WESTWALL]);
	load_image(r, texture[FLOOR], r->world.tex_name[FLOOR]);
	load_image(r, texture[CEILING], r->world.tex_name[CEILING]);
	load_image(r, texture[FLOOR2], r->world.tex_name[FLOOR2]);
	load_image(r, texture[CEILING2], r->world.tex_name[CEILING2]);
	r->world.texture = std__allocate(TEX_AMOUNT, sizeof(int *));
	for (int i = 0; i < TEX_AMOUNT; ++i)
		r->world.texture[i] = std__allocate(r->world.tex_height * r->world.tex_width, sizeof(int));
	for (int i = 0; i < TEX_AMOUNT; ++i)
		for (int j = 0; j < r->world.tex_height * r->world.tex_width; ++j)
			r->world.texture[i][j] = texture[i][j];
}
