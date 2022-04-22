#include "engine.h"
#include "renderer.h"
#include "std__types.h"
#include "std__system.h"
#include "flags.h"
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

static void	load_tex_from_rgb(int texline[], t_rgb rgb)
{
	int	i;

	i = -1;
	while (++i < TEX__WIDTH * TEX__HEIGHT)
		texline[i] = rgb;
}

static void	renderer__load_tex_from_default(t_renderer *this)
{
	int			i;
	const char	*default_tex[] = {
		"texture/backroom/floor1.xpm",
		"texture/backroom/ceiling0.xpm",
		"texture/backroom/light0.xpm"};

	i = -1;
	while (++i < 3)
		load_tex(this, this->world.texture[i + 4], (t_string)default_tex[i]);
}

static void	renderer__load_tex_from_rgb(t_renderer *this)
{
	load_tex_from_rgb(this->world.texture[TEX__FLOOR], this->world.colors[0]);
	load_tex_from_rgb(
		this->world.texture[TEX__CEILING0], this->world.colors[1]);
	load_tex_from_rgb(
		this->world.texture[TEX__CEILING1], this->world.colors[1]);
}

void	renderer__init_texture(t_renderer *this)
{
	int		i;

	i = -1;
	while (++i < 4)
		load_tex(this, this->world.texture[i], this->world.texture_path[i]);
	if (BONUS)
		renderer__load_tex_from_default(this);
	else
		renderer__load_tex_from_rgb(this);
}
