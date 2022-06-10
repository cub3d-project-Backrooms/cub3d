#include <math.h>
#include "raycast.h"
#include "renderer.h"
#include "std__math.h"

// void	renderer__draw__sprite_texture(
// 	t_renderer *this, t_camera* camera, int i)
// {

// }

t_spritedata	spritedata__init(const t_sprites sprites, t_camera* camera, int i)
{
	t_spritedata 		s;

	s.d = vec__sub(&sprites[i].pos, &camera->pos);
	s.inverse_determinant
		= 1.0 / (camera->plane.x * camera->dir.y - camera->dir.x * camera->plane.y);
	s.transform = (t_vec){
        s.inverse_determinant * (camera->dir.y * s.d.x - camera->dir.x * s.d.y),
        s.inverse_determinant * (-camera->plane.y * s.d.x + camera->plane.x * s.d.y)
	};

	// this is actually the depth inside the screen, that
	// what Z is in 3D, the distance of sprites to player,
	// matching sqrt(spriteDistance[i])
    s.screen_x = (int)((WIDTH / 2) * (1 + s.transform.x / s.transform.y));

	// using "transformy" instead of the
    // real distance prevents fisheye
    // calculate lowest and highest pixel to fill in current stripe
    s.size = (t_sizevec){
		.width = (int)fabs((HEIGHT / s.transform.y)),
		.height = (int)fabs((HEIGHT / s.transform.y))
	};

	s.x_range = (t_irange){
    	math__max(0, s.screen_x - s.size.width / 2),
    	math__min(WIDTH - 1, s.screen_x + s.size.width / 2)
	};

	s.y_range = (t_irange){
		math__max(0,  HEIGHT / 2 - s.size.height / 2),
		math__min(HEIGHT - 1, HEIGHT / 2 + s.size.height / 2)
	};

	return s;
}

void	renderer__raycast__sprite(
	t_renderer* this, t_camera* camera, int i, bool other_frame)
{
	const t_sprites		sprites = this->world.sprites;
	const t_spritedata	s = spritedata__init(sprites, camera, i);

    // loop through every vertical stripe of the sprites on screen
    for (int stripe = s.x_range.start; stripe < s.x_range.end; stripe++) {
      int texx = (int)((256 * (stripe - (s.screen_x - s.size.width / 2)) * TEX__WIDTH / s.size.width) / 256);

	  // the conditions in the if are:
      // 1) it's in front of camera plane so you don't see things behind you
      // 2) it's on the screen (left)
      // 3) it's on the screen (right)
      // 4) ZBuffer, with perpendicular distance
      if (s.transform.y > 0 && stripe > 0 && stripe < WIDTH && s.transform.y < this->zbuffer[stripe])
        for (int y = s.y_range.start; y < s.y_range.end; y++)  // for every pixel of the current stripe
        {
          int d = y * 256 - HEIGHT * 128 + s.size.height * 128;  // 256 and 128 factors to avoid floats
          int texy = ((d * TEX__HEIGHT) / s.size.height) / 256;
          int color = this->world.texture[TEX__SPRITE0 + other_frame][TEX__WIDTH * texy + texx];  // get current color from the texture
          if ((color & 0xFFFFFF) != 0)
            this->buf[y][stripe] = distance_shade(color, sprites[i].distance / 5);
			// paint pixel if it isn't black,
            // black is the invisible color
        }
    }
	// renderer__draw__sprite_texture(this, camera, i);
}

void	renderer__draw__sprites(
	t_renderer* this, t_camera* camera, bool other_frame) {
	int			i;
	t_sprites	sprites;

	sprites = this->world.sprites;
	i = -1;
	while (++i < this->world.num_sprites)
	{
		const t_vec delta = vec__sub(&sprites[i].pos, &camera->pos);
		sprites[i].distance = delta.x * delta.x + delta.y * delta.y;
		renderer__raycast__sprite(this, camera, i, other_frame);
	}
}
