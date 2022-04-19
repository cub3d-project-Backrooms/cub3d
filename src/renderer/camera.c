#include "renderer.h"
#include <math.h>

// the direction of the ray can be calculated as was explained earlier: as the
// sum of the direction vector, and a part of the plane vector.
t_vec	camera__ray_dir_at_position(t_camera *this, double x)
{
	return (t_vec){this->dir.x + this->plane.x * x,
					this->dir.y + this->plane.y * x};
}

t_ivec	camera__to_pos_at_map(t_camera *this)
{
	return ((t_ivec){(int)this->pos.x, (int)this->pos.y});
}
