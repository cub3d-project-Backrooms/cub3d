#include "renderer.h"

void	floordata__raycast__set_raydir_vector(t_floordata *this, t_camera *camera)
{
	this->ray_dir0 = (t_vec){camera->dir.x - camera->plane.x, camera->dir.y
		- camera->plane.y};
	this->ray_dir1 = (t_vec){camera->dir.x + camera->plane.x, camera->dir.y
		+ camera->plane.y};
}

void	floordata__raycast__set_row_distance(t_floordata *this, int current_y)
{
	int		position_from_center;
	float	vertical_camera_position;

	position_from_center = current_y - HEIGHT / 2;
	vertical_camera_position = 0.5 * HEIGHT;
	this->row_distance = vertical_camera_position / position_from_center;
}

void	floordata__raycast__set_floor_vectors(t_floordata *this, t_camera *camera)
{
	this->floor_step.x = this->row_distance * (this->ray_dir1.x
			- this->ray_dir0.x) / WIDTH;
	this->floor_step.y = this->row_distance * (this->ray_dir1.y
			- this->ray_dir0.y) / WIDTH;
	this->floor.x = camera->pos.x + this->row_distance * this->ray_dir0.x;
	this->floor.y = camera->pos.y + this->row_distance * this->ray_dir0.y;
}

void	floordata__raycast__set_dtexture_vector(t_floordata *this)
{
	this->cell.x = (int)(this->floor.x);
	this->cell.y = (int)(this->floor.y);
	this->dt.x = (int)(TEX__WIDTH * (this->floor.x
				- this->cell.x)) & (TEX__WIDTH - 1);
	this->dt.y = (int)(TEX__HEIGHT * (this->floor.y
				- this->cell.y)) & (TEX__HEIGHT - 1);
	this->floor.x += this->floor_step.x;
	this->floor.y += this->floor_step.y;
}

void	renderer__draw__floor(t_renderer *this, t_floordata *vecs,
		int current_x, int current_y)
{
	int	color;

	color = this->world.texture[vecs->floor_texture][(int)(TEX__WIDTH * vecs->dt.y
			+ vecs->dt.x)];
	color = (color >> 1) & 8355711;
	color = distance_shade(color, vecs->row_distance);
	this->buf[current_y][current_x] = color;
	color = this->world.texture[vecs->ceiling_texture][(int)(TEX__WIDTH * vecs->dt.y
			+ vecs->dt.x)];
	color = (color >> 1) & 8355711;
	color = distance_shade(color, vecs->row_distance);
	this->buf[HEIGHT - current_y - 1][current_x] = color;
}