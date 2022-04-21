#include "renderer.h"
#include "std__math.h"
#include <math.h>

void	renderer__draw__vertical_wall(t_renderer *this,
									int lineheight,
									int color,
									int x)
{
	int	draw_start;
	int	draw_end;
	int	y;

	draw_start = math__max(-lineheight / 2 + HEIGHT / 2, 0);
	draw_end = math__min(lineheight / 2 + HEIGHT / 2, HEIGHT - 1);
	y = draw_start - 1;
	while (++y < draw_end)
		this->buf[y][x] = color;
}

void walldata__raycast__set_dda_vector(t_walldata *this, t_camera *camera, int current_x, t_world *world)
{
	this->camera_x = dda__normalized_plane_x(current_x);
	this->ray_dir = camera__ray_dir_at_position(camera, this->camera_x);
	this->map_pos = camera__to_pos_at_map(camera);
	this->delta_dist = dda__dist_to_next_closest_grid(&this->ray_dir);
	this->step = dda__initial_step(camera, &this->map_pos, &this->ray_dir, &this->delta_dist);
	dda__advance_step_until_hit(&this->step, &this->map_pos, &this->delta_dist, world);
	this->perpWallDist = dda__perpendicular_dist_to_closest_grid(
		&this->step, camera, &this->map_pos, &this->ray_dir);
}

void walldata__draw__set_wall_data(t_walldata *this, t_camera *camera)
{
	this->lineheight = (int)(HEIGHT / this->perpWallDist * 1);
	this->draw_start = math__max(-this->lineheight / 2 + HEIGHT / 2, 0);
	this->draw_end = math__min(this->lineheight / 2 + HEIGHT / 2, HEIGHT - 1);
	if (this->step.is_hit_y_side == 0)
		this->wallx = camera->pos.y + this->perpWallDist * this->ray_dir.y;
	else
		this->wallx = camera->pos.x + this->perpWallDist * this->ray_dir.x;
	this->wallx -= floor(this->wallx);
}

void walldata__draw__set_texture_data(t_walldata *this, t_world *world)
{
	this->texX = (int)(this->wallx * (double)world->tex_width);
	if (this->step.is_hit_y_side == 0 && this->ray_dir.x > 0)
		this->texX = world->tex_width - this->texX - 1;
	if (this->step.is_hit_y_side == 1 && this->ray_dir.y < 0)
		this->texX = world->tex_width - this->texX - 1;
	this->step_val = 1.0 * world->tex_height / this->lineheight;
	this->texPos = (this->draw_start - HEIGHT / 2 + this->lineheight / 2) * this->step_val;
}

int renderer__draw__wall_texture(t_renderer *this, t_walldata *data)
{
	int texY;
	int texnum;
	int color;

	texY = (int)data->texPos & (this->world.tex_height - 1);
	data->texPos += data->step_val;
	if (data->step.is_hit_y_side && (data->step.y_sign == POSITIVE))
		texnum = WNORTH;
	else if (data->step.is_hit_y_side && (data->step.y_sign == NEGATIVE))
		texnum = WSOUTH;
	else if (!data->step.is_hit_y_side && (data->step.x_sign == POSITIVE))
		texnum = WEAST;
	else
		texnum = WWEST;
	color = this->world.texture[texnum][this->world.tex_height * texY + data->texX];
	color = distance_shade(color, data->perpWallDist);
	return (color);
}
