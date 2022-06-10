#include <math.h>
#include "raycast.h"
#include "renderer.h"
#include "std__math.h"

void	renderer__raycast__sprite(
	t_renderer* this, t_camera* camera, double zbuffer[WIDTH], int i) {
	const t_sprites	sprites = this->world.sprites;
	const t_vec		pos = vec__sub(&sprites[i].pos, &camera->pos);
    const double	inverse_determinant
		= 1.0 / (camera->plane.x * camera->dir.y - camera->dir.x * camera->plane.y);
	const t_vec transform = {
        inverse_determinant * (camera->dir.y * pos.x - camera->dir.x * pos.y),
        inverse_determinant * (-camera->plane.y * pos.x + camera->plane.x * pos.y)};
		// this is actually the depth inside the screen, that
        // what Z is in 3D, the distance of sprites to player,
        // matching sqrt(spriteDistance[i])
    const int spriteScreenx = (int)((WIDTH / 2) * (1 + transform.x / transform.y));

    // calculate height of the sprites on screen
    const int spriteHeight = (int)fabs((HEIGHT / transform.y));
	// using "transformy" instead of the
    // real distance prevents fisheye
    // calculate lowest and highest pixel to fill in current stripe
	const int drawStarty = math__max(0, -spriteHeight / 2 + HEIGHT / 2);
	int drawEndy = math__min(HEIGHT - 1, spriteHeight / 2 + HEIGHT / 2);

    // calculate width of the sprites
    int spriteWidth = (int)fabs((HEIGHT / transform.y));
    int drawStartx = math__max(0, -spriteWidth / 2 + spriteScreenx);
    int drawEndx = math__min(WIDTH - 1, spriteWidth / 2 + spriteScreenx);
    // loop through every vertical stripe of the sprites on screen
    for (int stripe = drawStartx; stripe < drawEndx; stripe++) {
      int texx = (int)((256 * (stripe - (-spriteWidth / 2 + spriteScreenx)) * TEX__WIDTH / spriteWidth) / 256);
      // the conditions in the if are:
      // 1) it's in front of camera plane so you don't see things behind you
      // 2) it's on the screen (left)
      // 3) it's on the screen (right)
      // 4) ZBuffer, with perpendicular distance
      if (transform.y > 0 && stripe > 0 && stripe < WIDTH && transform.y < zbuffer[stripe])
        for (int y = drawStarty; y < drawEndy; y++)  // for every pixel of the current stripe
        {
          int d = y * 256 - HEIGHT * 128 + spriteHeight * 128;  // 256 and 128 factors to avoid floats
          int texy = ((d * TEX__HEIGHT) / spriteHeight) / 256;
          int color = this->world.texture[TEX__SPRITE0][TEX__WIDTH * texy + texx];  // get current color from the texture
          if ((color & 0xFFFFFF) != 0)
            this->buf[y][stripe] = distance_shade(color, sprites[i].distance / 5);
			// paint pixel if it isn't black,
            // black is the invisible color
        }
    }
}
