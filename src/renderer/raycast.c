/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youkim    <youkim@student.42seoul.kr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 10:13:06 by youkim            #+#    #+#             */
/*   Updated: 2022/05/04 10:13:06 by youkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"
#include "renderer.h"
#include <stdio.h>

void	renderer__raycast__floor(t_renderer *this, t_camera *camera)
{
	t_floordata	floordata;
	t_ivec		v;

	v.y = HEIGHT / 2 - 1;
	while (++v.y < HEIGHT)
	{
		floordata__raycast__set_raydir_vector(&floordata, camera);
		floordata__raycast__set_row_distance(&floordata, v.y);
		floordata__raycast__set_floor_vectors(&floordata, camera);
		v.x = -1;
		while (++v.x < WIDTH)
		{
			floordata__raycast__set_dtexture_vector(&floordata);
			floordata__draw__lights(&floordata);
			renderer__draw__floor(this, &floordata, v.x, v.y);
		}
	}
}

void	renderer__raycast__wall(
	t_renderer *this, t_camera *camera, double zbuffer[WIDTH])
{
	t_walldata	walldata;
	t_ivec		v;

	v.x = -1;
	while (++v.x < WIDTH)
	{
		walldata__raycast__set_dda_vector(&walldata, camera, v.x, &this->world);
		walldata__draw__set_wall_data(&walldata, camera);
		walldata__draw__set_texture_data(&walldata);
		zbuffer[v.x] = walldata.perp_wall_dist;
		v.y = walldata.draw_start - 1;
		while (++v.y < walldata.draw_end)
			this->buf[v.y][v.x] = renderer__draw__wall_texture(this, &walldata);
	}
}

#define numSprites 4
int spriteOrder[numSprites];
double spriteDistance[numSprites];
t_vec sprites[numSprites] = {
	{20.5, 11.5},
	{20.5, 10.5},
	{10.5, 4.5},
	{9.5, 4.5}
};

void sort_order(t_pair* orders, int amount) {
  t_pair tmp;

  for (int i = 0; i < amount; i++) {
    for (int j = 0; j < amount - 1; j++) {
      if (orders[j].first > orders[j + 1].first) {
        tmp.first = orders[j].first;
        tmp.second = orders[j].second;
        orders[j].first = orders[j + 1].first;
        orders[j].second = orders[j + 1].second;
        orders[j + 1].first = tmp.first;
        orders[j + 1].second = tmp.second;
      }
    }
  }
}

#include "std__math.h"
#include <math.h>
#include <stdlib.h>
#include "std__system.h"
void sortSprites(int* order, double* dist, int amount) {
  t_pair* sprites;

  // std::vector<std::pair<double, int>> sprites(amount);
  sprites = std__allocate(amount, sizeof(t_pair));
  // sprites = malloc(sizeof(t_pair) * amount);
  for (int i = 0; i < amount; i++) {
    sprites[i].first = dist[i];
    sprites[i].second = order[i];
  }
  sort_order(sprites, amount);
  // std::sort(sprites.begin(), sprites.end());
  for (int i = 0; i < amount; i++) {
    dist[i] = sprites[amount - i - 1].first;
    order[i] = sprites[amount - i - 1].second;
  }
  free(sprites);
}

void	renderer__raycast__sprite(
	t_renderer* this, t_camera* camera, double zbuffer[WIDTH]) {
  // SPRITE CASTING
  // sort sprites from far to close
  for (int i = 0; i < numSprites; i++) {
    spriteOrder[i] = i;
    spriteDistance[i] =
        ((camera->pos.x - sprites[i].x) * (camera->pos.x - sprites[i].x) +
         (camera->pos.y - sprites[i].y) * (camera->pos.y - sprites[i].y));  // sqrt not taken, unneeded
  }
  sortSprites(spriteOrder, spriteDistance, numSprites);
  // after sorting the sprites, do the projection and draw them
  for (int i = 0; i < numSprites; i++) {
    // translate sprites position to relative to camera
    double spritex = sprites[spriteOrder[i]].x - camera->pos.x;
    double spritey = sprites[spriteOrder[i]].y - camera->pos.y;

    double invDet = 1.0 / (camera->plane.x * camera->dir.y -
                           camera->dir.x * camera->plane.y);

    double transformx =
        invDet * (camera->dir.y * spritex - camera->dir.x * spritey);
    double transformy =
        invDet * (-camera->plane.y * spritex + camera->plane.x * spritey);
		// this is actually the depth inside the screen, that
        // what Z is in 3D, the distance of sprites to player,
        // matching sqrt(spriteDistance[i])

    int spriteScreenx = (int)((WIDTH / 2) * (1 + transformx / transformy));

    // calculate height of the sprites on screen
    int spriteHeight = (int)fabs((HEIGHT / transformy));
	// using "transformy" instead of the
    // real distance prevents fisheye
    // calculate lowest and highest pixel to fill in current stripe
	int drawStarty = math__max(0, -spriteHeight / 2 + HEIGHT / 2);
	int drawEndy = math__min(HEIGHT - 1, spriteHeight / 2 + HEIGHT / 2);

    // calculate width of the sprites
    int spriteWidth = (int)fabs((HEIGHT / transformy));
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
      if (transformy > 0 && stripe > 0 && stripe < WIDTH && transformy < zbuffer[stripe])
        for (int y = drawStarty; y < drawEndy; y++)  // for every pixel of the current stripe
        {
          int d = y * 256 - HEIGHT * 128 + spriteHeight * 128;  // 256 and 128 factors to avoid floats
          int texy = ((d * TEX__HEIGHT) / spriteHeight) / 256;
          int color = this->world.texture[TEX__SPRITE0][TEX__WIDTH * texy + texx];  // get current color from the texture
          if ((color & 0xFFFFFF) != 0)
            this->buf[y][stripe] = distance_shade(color, spriteDistance[i]);
			// paint pixel if it isn't black,
            // black is the invisible color
        }
    }
  }
}

void	renderer__raycast(t_renderer *this, t_camera *camera)
{
	double zbuffer[WIDTH];

	renderer__raycast__floor(this, camera);
	renderer__raycast__wall(this, camera, zbuffer);
	renderer__raycast__sprite(this, camera, zbuffer);
}
