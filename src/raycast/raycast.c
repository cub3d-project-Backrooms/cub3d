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
#include "raycast.h"
#include "renderer.h"

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

void	renderer__raycast__sprites(
	t_renderer* this, t_camera* camera, double zbuffer[WIDTH]) {
	t_sprites	sprites;
	(void)zbuffer;

	sprites = this->world.sprites;
	// SPRITE CASTING
	// sort sprites from far to close
	for (int i = 0; i < this->world.num_sprites; i++) {
	//   spriteOrder[i] = i;
	  sprites[i].distance =
	      ((camera->pos.x - sprites[i].pos.x) * (camera->pos.x - sprites[i].pos.x) +
	       (camera->pos.y - sprites[i].pos.y) * (camera->pos.y - sprites[i].pos.y));  // sqrt not taken, unneeded
	}
	// sortSprites(spriteOrder, spriteDistance, numSprites);
	// after sorting the sprites, do the projection and draw them
	for (int i = 0; i < this->world.num_sprites; i++) {
		renderer__raycast__sprite(this, camera, zbuffer, i);
	}
}

void	renderer__raycast(t_renderer *this, t_camera *camera)
{
	double zbuffer[WIDTH];

	renderer__raycast__floor(this, camera);
	renderer__raycast__wall(this, camera, zbuffer);
	renderer__raycast__sprites(this, camera, zbuffer);
}
