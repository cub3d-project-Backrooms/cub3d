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
	return (result);
}

// calculate lowest and highest pixel to fill in current stripe
void	renderer__draw__vertical_wall(t_renderer *this,
								int lineheight, int color, int x)
{
	int draw_start;
	int draw_end;
	int	y;

	draw_start = math__max(-lineheight / 2 + HEIGHT / 2, 0);
	draw_end = math__min(lineheight / 2 + HEIGHT / 2, HEIGHT - 1);
	y = draw_start - 1;
	while (++y < draw_end)
		this->buf[y][x] = color;
}

void	renderer__raycast__set_raydir_vector(t_renderer *this, t_floordata *vecs, t_camera *camera)
{
	(void)this;
	vecs->ray_dir0 = (t_vec){camera->dir.x - camera->plane.x, camera->dir.y - camera->plane.y};
	vecs->ray_dir1 = (t_vec){camera->dir.x + camera->plane.x, camera->dir.y + camera->plane.y};
}

void renderer__raycast__set_row_distance(t_renderer *this, t_floordata *vecs, int current_y)
{
	int position_from_center;
	float vertical_camera_position;

	(void)this;
	position_from_center = current_y - HEIGHT / 2;
	vertical_camera_position = 0.5 * HEIGHT;
	vecs->rowDistance = vertical_camera_position / position_from_center;
}

void renderer__raycast__set_floor_vectors(t_renderer *this, t_floordata *vecs, t_camera *camera)
{
	(void)this;
	vecs->floorStep.x = vecs->rowDistance * (vecs->ray_dir1.x - vecs->ray_dir0.x) / WIDTH;
	vecs->floorStep.y = vecs->rowDistance * (vecs->ray_dir1.y - vecs->ray_dir0.y) / WIDTH;
	vecs->floor.x = camera->pos.x + vecs->rowDistance * vecs->ray_dir0.x;
	vecs->floor.y = camera->pos.y + vecs->rowDistance * vecs->ray_dir0.y;
}

void renderer__raycast__set_delta_texture_vector(t_renderer *this, t_floordata *vecs)
{
	(void)this;
	vecs->cell.x = (int)(vecs->floor.x);
	vecs->cell.y = (int)(vecs->floor.y);
	vecs->deltaT.x = (int)(TEX_WIDTH * (vecs->floor.x - vecs->cell.x)) & (TEX_WIDTH - 1);
	vecs->deltaT.y = (int)(TEX_HEIGHT * (vecs->floor.y - vecs->cell.y)) & (TEX_HEIGHT - 1);
	vecs->floor.x += vecs->floorStep.x;
	vecs->floor.y += vecs->floorStep.y;
}

void renderer__draw__checkerboard(t_renderer *this, t_floordata *vecs)
{
	bool checkerboard;

	(void)this;
	checkerboard = ((int)vecs->floor.x + (int)vecs->floor.y) % 2;
	if (checkerboard)
	{
		vecs->floorTexture = WOOD;
		vecs->ceilingTexture = GRAYSTONE;
	}
	else
	{
		vecs->floorTexture = REDBRICK;
		vecs->ceilingTexture = MOSSY;
	}
}

void renderer__draw__floor(t_renderer *this, t_floordata *vecs, int current_x, int current_y)
{
	int color;

	color = texture[vecs->floorTexture][(int)(TEX_WIDTH * vecs->deltaT.y + vecs->deltaT.x)];
	color = (color >> 1) & 8355711;  // make a bit darker
	this->buf[current_y][current_x] = color;
	color = texture[vecs->ceilingTexture][(int)(TEX_WIDTH * vecs->deltaT.y + vecs->deltaT.x)];
	color = (color >> 1) & 8355711;  // make a bit darker
	this->buf[HEIGHT - current_y - 1][current_x] = color;
}

// FLOOR CASTING
void renderer__raycast__floor(t_renderer* this, t_camera* camera)
{
	t_floordata floordata;
	int y;
	int x;

	y = HEIGHT / 2;
	while (++y < HEIGHT)
	{
		renderer__raycast__set_raydir_vector(this, &floordata, camera);
		renderer__raycast__set_row_distance(this, &floordata, y);
		renderer__raycast__set_floor_vectors(this, &floordata, camera);
		x = -1;
		while (++x < WIDTH)
		{
			renderer__raycast__set_delta_texture_vector(this, &floordata);
			renderer__draw__checkerboard(this, &floordata);
			renderer__draw__floor(this, &floordata, x, y);
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
