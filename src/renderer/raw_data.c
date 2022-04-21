#include "engine.h"
#include "renderer.h"
#include "std__types.h"
#include "std__system.h"
#include <assert.h>
#include <stdio.h>

void	load_image(t_renderer *r, int texline[], t_string path)
{
	t_image	image;

	image__init(&image, r->mlx, path);
	image__write_to_buffer(&image, texline);
	image__deinit(&image);
}

void	renderer__init_texture(t_renderer *r)
{
	r->world.tex_name[TEX__WALL__NORTH] = "asset/texture/backroom/wall0.xpm";
	r->world.tex_name[TEX__WALL__SOUTH] = "asset/texture/backroom/wall1.xpm";
	r->world.tex_name[TEX__WALL__EAST] = "asset/texture/backroom/wall2.xpm";
	r->world.tex_name[TEX__WALL__WEST] = "asset/texture/backroom/wall3.xpm";

	load_image(r, r->world.texture[TEX__WALL__NORTH], r->world.tex_name[TEX__WALL__NORTH]);
	load_image(r, r->world.texture[TEX__WALL__SOUTH], r->world.tex_name[TEX__WALL__SOUTH]);
	load_image(r, r->world.texture[TEX__WALL__EAST], r->world.tex_name[TEX__WALL__EAST]);
	load_image(r, r->world.texture[TEX__WALL__WEST], r->world.tex_name[TEX__WALL__WEST]);
	load_image(r, r->world.texture[TEX__FLOOR], FLOOR_PATH);
	load_image(r, r->world.texture[TEX__CEILING0], CEILING_PATH);
	load_image(r, r->world.texture[TEX__CEILING1], CEILING2_PATH);
}
