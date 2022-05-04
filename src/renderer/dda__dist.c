#include "engine.h"
#include "renderer.h"
#include "types__renderer.h"
#include <math.h>

/**
 * @brief length of ray from one x || y-side to next x || y-side
 * rayDirX : raydirY = 1 : deltadistX_height
 * deltadistX = sqrt(1 + deltadistX_height ** 2)
 * = sqrt(1 + rayDirY ** 2 / rayDirX ** 2)
 * |rayDir| ** 2 = rayDirX ** 2 + rayDirY ** 2
 * rayDirY = sqrt(rayDirX ** 2 + 1)
 *
 * simplified from:
 * deltaDistX = sqrt(1 + (rayDirY * rayDirY) / (rayDirX * rayDirX))
 * deltaDistY = sqrt(1 + (rayDirX * rayDirX) / (rayDirY * rayDirY))
 * @param ray_dir
 * @return t_vec
 */
t_vec	dda__dist_to_next_closest_grid(t_vec *ray_dir)
{
	return ((t_vec){fabs(1 / ray_dir->x), fabs(1 / ray_dir->y)});
}

double	dda__normalized_plane_x(double x)
{
	return (2 * x / (double)WIDTH - 1);
}

double	dda__perpendicular_dist_to_closest_grid(t_dda__step *step,
												t_camera *camera,
												t_ivec *map_pos,
												t_vec *ray_dir)
{
	double	perp_wall_dist;

	if (step->is_hit_y_side)
		perp_wall_dist = (map_pos->y - camera->pos.y + (1 - step->y_sign) / 2)
			/ ray_dir->y;
	else
		perp_wall_dist = (map_pos->x - camera->pos.x + (1 - step->x_sign) / 2)
			/ ray_dir->x;
	return (perp_wall_dist);
}
