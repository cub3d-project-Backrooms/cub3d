#include "std__math.h"

bool	ivec__is_equal(const t_ivec *v1, const t_ivec *v2)
{
	return (v1->x == v2->x && v1->y == v2->y);
}

t_ivec	vec__to_ivec(const t_vec *vec)
{
	return ((t_ivec){
		.x = (int)vec->x,
		.y = (int)vec->y,
	});
}
