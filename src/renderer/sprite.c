/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkim <tkim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 21:30:53 by tkim              #+#    #+#             */
/*   Updated: 2022/06/16 21:03:31 by tkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "raycast.h"
#include "renderer.h"
#include "std__math.h"
#include "engine.h"

t_spritedata	spritedata__init(
	const t_sprites sprites, t_camera *camera, int i, int frame)
{
	t_spritedata	s;

	s.frame = frame;
	s.d = vec__sub(&sprites[i].pos, &camera->pos);
	s.inverse_determinant
		= 1.0 / (camera->plane.x * camera->dir.y - \
		camera->dir.x * camera->plane.y);
	s.transform = (t_vec){
		s.inverse_determinant * (camera->dir.y * s.d.x - camera->dir.x * s.d.y),
		s.inverse_determinant * (-camera->plane.y * s.d.x + \
		camera->plane.x * s.d.y)};
	s.screen_x = (int)((WIDTH / 2) * (1 + s.transform.x / s.transform.y));
	s.size = (t_sizevec){
		.width = (int)fabs((HEIGHT / s.transform.y)),
		.height = (int)fabs((HEIGHT / s.transform.y))
	};
	s.x_range = (t_irange){
		math__max(0, s.screen_x - s.size.width / 2),
		math__min(WIDTH - 1, s.screen_x + s.size.width / 2)
	};
	s.y_range = (t_irange){
		math__max(0, HEIGHT / 2 - s.size.height / 2),
		math__min(HEIGHT - 1, HEIGHT / 2 + s.size.height / 2)
	};
	return (s);
}

void	renderer__draw__sprite_texture(
 	t_renderer *this, t_spritedata	s, int i, int stripe, int y)
{
	const t_sprites		sprites = this->world.sprites;
	
	int texx = (int)((256 * (stripe - (s.screen_x - s.size.width / 2)) \
	* TEX__WIDTH / s.size.width) / 256);
	int d = y * 256 - HEIGHT * 128 + s.size.height * 128;
	int texy = ((d * TEX__HEIGHT) / s.size.height) / 256;
	int color = this->world.texture[TEX__SPRITE0 + is_other_frame(s.frame)][TEX__WIDTH * texy + texx];
	if ((color & 0xFFFFFF) != 0)
		this->buf[y][stripe] = make_colorful(distance_shade(color, sprites[i].distance / 4), s.frame);

}
void	renderer__raycast__sprite(
	t_renderer *this, t_camera *camera, int i, int frame)
{
	const t_sprites		sprites = this->world.sprites;
	const t_spritedata	s = spritedata__init(sprites, camera, i, frame);
	int					stripe;
	int					y;

	stripe = s.x_range.start - 1;
	while (++stripe < s.x_range.end)
	{
		if (s.transform.y > 0 && stripe > 0 && stripe < WIDTH && \
			s.transform.y < this->zbuffer[stripe])
		{
			y = s.y_range.start - 1;
			while (++y < s.y_range.end)
			{
			//	int texx = (int)((256 * (stripe - (s.screen_x - s.size.width / 2)) \
			//	* TEX__WIDTH / s.size.width) / 256);
			//	int d = y * 256 - HEIGHT * 128 + s.size.height * 128;
			//	int texy = ((d * TEX__HEIGHT) / s.size.height) / 256;
			//	int color = this->world.texture[TEX__SPRITE0 + is_other_frame(s.frame)][TEX__WIDTH * texy + texx];
			//	if ((color & 0xFFFFFF) != 0)
			//		this->buf[y][stripe] = make_colorful(distance_shade(color, sprites[i].distance / 4), s.frame);
			renderer__draw__sprite_texture(this, s, i, stripe, y);
			}
 	//t_renderer *this, t_spritedata	s, int i, int stripe)

		}
	}
}

void	renderer__draw__sprites(
	t_renderer *this, t_camera *camera, int frame)
{
	int			i;
	t_sprites	sprites;

	sprites = this->world.sprites;
	i = -1;
	while (++i < this->world.num_sprites)
	{
		const t_vec	delta = vec__sub(&sprites[i].pos, &camera->pos);
		sprites[i].distance = delta.x * delta.x + delta.y * delta.y;
		renderer__raycast__sprite(this, camera, i, frame);
	}
}
