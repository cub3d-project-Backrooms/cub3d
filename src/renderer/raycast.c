#include "engine.h"
#include "renderer.h"
#include <stdio.h>

void	renderer__raycast__floor(t_renderer *this, t_camera *camera)
{
	t_floordata	floordata;
	int			y;
	int			x;

	y = HEIGHT / 2;
	while (++y < HEIGHT)
	{
		floordata__raycast__set_raydir_vector(&floordata, camera);
		floordata__raycast__set_row_distance(&floordata, y);
		floordata__raycast__set_floor_vectors(&floordata, camera);
		x = -1;
		while (++x < WIDTH)
		{
			floordata__raycast__set_delta_texture_vector(&floordata, &this->world);
			floordata__draw__checkerboard(&floordata);
			renderer__draw__floor(this, &floordata, x, y);
		}
	}
}

void renderer__raycast__wall(t_renderer* this, t_camera* camera, double zbuffer[WIDTH])
{
	t_walldata walldata;
	int x;
	int y;

	x = -1;
	while (++x < WIDTH)
	{
		walldata__raycast__set_dda_vector(&walldata, camera, x, &this->world);
		zbuffer[x] = walldata.perpWallDist;
		walldata__draw__set_wall_data(&walldata, camera);
		walldata__draw__set_texture_data(&walldata, &this->world);
		y = walldata.draw_start - 1;
		while (++y < walldata.draw_end)
			this->buf[y][x] = renderer__draw__wall_texture(this, &walldata);
	}
}

void	renderer__raycast(t_renderer *this, t_camera *camera)
{
	double	zBuffer[WIDTH];

	renderer__raycast__floor(this, camera);
	renderer__raycast__wall(this, camera, zBuffer);
}
