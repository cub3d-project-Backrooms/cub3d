#include <math.h>
#include "engine.h"
#include "renderer.h"
#include "std__math.h"

const extern int g_worldmap[24][24];
extern int texture[8][TEX_HEIGHT * TEX_WIDTH];

t_colors get_color(t_ivec* map, bool is_hit_y_side)
{
	const t_colors colors[] = {
		COLOR__YELLOW, COLOR__RED, COLOR__GREEN, COLOR__BLUE, COLOR__WHITE,
	};
	const int index = g_worldmap[map->y][map->x];
	int result;

	if (index > 4)
		result = colors[0];
	else
		result = colors[index];
	if (is_hit_y_side)
		result /= 2;
	return result;
}

// calculate lowest and highest pixel to fill in current stripe
void	renderer__draw__vertical_wall(t_renderer *this,
								int lineheight, int color, int x)
{
	int draw_start = math__max(-lineheight / 2 + HEIGHT / 2, 0);
	int draw_end = math__min(lineheight / 2 + HEIGHT / 2, HEIGHT - 1);

	for (int y = draw_start; y < draw_end; y++)
		this->buf[y][x] = color;
}

// FLOOR CASTING
void renderer__raycast__floor(t_renderer* this, t_camera* camera)
{
	for (int y = HEIGHT / 2 + 1; y < HEIGHT; y++) {
		// rayDir for leftmost ray (x = 0) and rightmost ray (x = w)
		t_vec ray_dir0 = (t_vec){camera->dir.x - camera->plane.x,
								camera->dir.y - camera->plane.y};
		t_vec ray_dir1 = (t_vec){camera->dir.x + camera->plane.x,
								camera->dir.y + camera->plane.y};
		// t_ivec map_pos = camera__to_pos_at_map(camera);

		// Current y position compared to the center of the screen (the horizon)
		int p = y - HEIGHT / 2;

		// Vertical position of the camera.
		float posZ = 0.5 * HEIGHT;

		// Horizontal distance from the camera to the floor for the current row.
		// 0.5 is the z position exactly in the middle between floor and ceiling.
		float rowDistance = posZ / p;

		// calculate the real world step vector we have to add for each x (parallel
		// to camera plane) adding step by step avoids multiplications with a weight
		// in the inner loop
		float floorStepx = rowDistance * (ray_dir1.x - ray_dir0.x) / WIDTH;
		float floorStepy = rowDistance * (ray_dir1.y - ray_dir0.y) / WIDTH;

		// real world coordinates of the leftmost column. This will be updated as we
		// step to the right.
		float floorx = camera->pos.x + rowDistance * ray_dir0.x;
		float floory = camera->pos.y + rowDistance * ray_dir0.y;

		for (int x = 0; x < WIDTH; ++x) {
		// the cell coord is simply got from the integer parts of floorx and
		// floory
		int cellx = (int)(floorx);
		int celly = (int)(floory);

		// get the texture coordinate from the fractional part
		int tx = (int)(TEX_WIDTH * (floorx - cellx)) & (TEX_WIDTH - 1);
		int ty = (int)(TEX_HEIGHT * (floory - celly)) & (TEX_HEIGHT - 1);

		floorx += floorStepx;
		floory += floorStepy;

		bool checkerboard = ((int)floorx + (int)floory) % 2;

		// choose texture and draw the pixel
		int floorTexture = checkerboard ? 6 : 1;
		int ceilingTexture = checkerboard ? 3 : 5;

		int color;

		// floor
		color = texture[floorTexture][TEX_WIDTH * ty + tx];
		color = (color >> 1) & 8355711;  // make a bit darker

		this->buf[y][x] = color;

		// ceiling (symmetrical, at screenHeight - y - 1 instead of y)
		color = texture[ceilingTexture][TEX_WIDTH * ty + tx];
		color = (color >> 1) & 8355711;  // make a bit darker

		this->buf[HEIGHT - y - 1][x] = color;
		}
	}
}

void renderer__raycast__wall(t_renderer* this,
							t_camera* camera, double zbuffer[WIDTH]) {
	for (int x = 0; x < WIDTH; x++) {
		double camera_x = dda__normalized_plane_x(x);
		t_vec ray_dir = camera__ray_dir_at_position(camera, camera_x);
		t_ivec map_pos = camera__to_pos_at_map(camera);
		t_vec delta_dist = dda__dist_to_next_closest_grid(&ray_dir);
		t_dda__step step =
			dda__initial_step(camera, &map_pos, &ray_dir, &delta_dist);
		dda__advance_step_until_hit(&step, &map_pos, &delta_dist);

		double perpWallDist = dda__perpendicular_dist_to_closest_grid(
			&step, camera, &map_pos, &ray_dir);
		zbuffer[x] = perpWallDist;

		int lineheight = (int)(HEIGHT / perpWallDist * 1);
		// int color = get_color(&map_pos, step.is_hit_y_side);
		// renderer__draw__vertical_wall(this, lineheight, color, x);
		int draw_start = math__max(-lineheight / 2 + HEIGHT / 2, 0);
		int draw_end = math__min(lineheight / 2 + HEIGHT / 2, HEIGHT - 1);

		int texnum = g_worldmap[map_pos.x][map_pos.y] - 1;
		// calculate value of wallx
		double wallx;  // where exactly the wall was hit
		if (step.is_hit_y_side == 0)
			wallx = camera->pos.y + perpWallDist * ray_dir.y;
		else
			wallx = camera->pos.x + perpWallDist * ray_dir.x;
		wallx -= floor(wallx);

		// x coordinate on the texture
		int texx = (int)(wallx * (double)TEX_WIDTH);
		if (step.is_hit_y_side == 0 && ray_dir.x > 0)
			texx = TEX_WIDTH - texx - 1;
		if (step.is_hit_y_side == 1 && ray_dir.y < 0)
			texx = TEX_WIDTH - texx - 1;
		// How much to increase the texture coordinate per screen pixel
		double step_val = 1.0 * TEX_HEIGHT / lineheight;
		// Starting texture coordinate
		double texPos = (draw_start - HEIGHT / 2 + lineheight / 2) * step_val;

		for (int y = draw_start; y < draw_end; y++) {
			// Cast the texture coordinate to integer, and mask with (TEX_HEIGHT - 1)
			// in case of overflow
			int texy = (int)texPos & (TEX_HEIGHT - 1);
			texPos += step_val;

			int color = texture[texnum][TEX_HEIGHT * texy + texx];
			// make color darker for y-sides: R, G and B byte each divided through
			// with a "shift" and an "and"
			if (step.is_hit_y_side)
			color = (color >> 1) & 8355711;
			this->buf[y][x] = color;
		}
	}
}

void renderer__raycast(t_renderer* this, t_camera* camera)
{
	double zBuffer[WIDTH];

	renderer__raycast__floor(this, camera);
	renderer__raycast__wall(this, camera, zBuffer);
}
