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
	this->rowDistance = vertical_camera_position / position_from_center;
}

void	floordata__raycast__set_floor_vectors(t_floordata *this, t_camera *camera)
{
	this->floorStep.x = this->rowDistance * (this->ray_dir1.x
			- this->ray_dir0.x) / WIDTH;
	this->floorStep.y = this->rowDistance * (this->ray_dir1.y
			- this->ray_dir0.y) / WIDTH;
	this->floor.x = camera->pos.x + this->rowDistance * this->ray_dir0.x;
	this->floor.y = camera->pos.y + this->rowDistance * this->ray_dir0.y;
}

void	floordata__raycast__set_delta_texture_vector(t_floordata *this, t_world *world)
{
	this->cell.x = (int)(this->floor.x);
	this->cell.y = (int)(this->floor.y);
	this->deltaT.x = (int)(world->tex_width * (this->floor.x
				- this->cell.x)) & (world->tex_width - 1);
	this->deltaT.y = (int)(world->tex_height * (this->floor.y
				- this->cell.y)) & (world->tex_height - 1);
	this->floor.x += this->floorStep.x;
	this->floor.y += this->floorStep.y;
}

void	renderer__draw__floor(t_renderer *this, t_floordata *vecs,
		int current_x, int current_y)
{
	int	color;

	color = this->world.texture[vecs->floorTexture][(int)(this->world.tex_width * vecs->deltaT.y
			+ vecs->deltaT.x)];
	color = (color >> 1) & 8355711;
	color = distance_shade(color, vecs->rowDistance);
	this->buf[current_y][current_x] = color;
	color = this->world.texture[vecs->ceilingTexture][(int)(this->world.tex_width * vecs->deltaT.y
			+ vecs->deltaT.x)];
	color = (color >> 1) & 8355711;
	color = distance_shade(color, vecs->rowDistance);
	this->buf[HEIGHT - current_y - 1][current_x] = color;
}