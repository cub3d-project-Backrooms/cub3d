#include "engine.h"
#include "renderer.h"
#include "std__types.h"
#include "std__system.h"
#include <assert.h>
#include <stdio.h>

// TODO: refactor
static void	load_tex(t_renderer *this, int texline[], t_string path)
{
	t_image	image;

	image__init(&image, this->mlx, path);
	image__write_to_buffer(&image, texline);
	image__deinit(&image);
}

static void	load_tex_from_rgb(t_renderer *this, int texline[], t_rgb rgb)
{
	t_image	image;

	image__init_from_rgb(&image, this->mlx, rgb);
	image__write_to_buffer(&image, texline);
	image__deinit(&image);
}

void	renderer__init_texture(t_renderer *this)
{
	int			i;
	t_world		*world;
	// const char	*default_tex[] = {
	// 	"texture/backroom/floor1.xpm",
	// 	"texture/backroom/ceiling0.xpm",
	// 	"texture/backroom/light0.xpm"};

	world = &this->world;
	i = -1;
	while (++i <= TEX__WALL__WEST)
		load_tex(this, world->texture[i], world->texture_path[i]);
	load_tex_from_rgb(this, world->texture[TEX__FLOOR], world->colors[0]);
	load_tex_from_rgb(this, world->texture[TEX__CEILING0], world->colors[1]);
	load_tex_from_rgb(this, world->texture[TEX__CEILING1], world->colors[1]);
	// i = -1;
	// while (++i < 3)
	// 	load_tex(this, world->texture[i + 4], (t_string)default_tex[i]);
}
