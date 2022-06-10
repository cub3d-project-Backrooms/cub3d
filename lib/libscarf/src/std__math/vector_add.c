#include "std__math.h"

t_vec	vec__add(const t_vec *v1, const t_vec *v2)
{
	return ((t_vec){
		v1->x + v2->x,
		v1->y + v2->y,
	});
}

void	vec__add_assign(t_vec *v1, t_vec *v2)
{
	v1->x += v2->x;
	v1->y += v2->y;
}

t_vec	vec__sub(const t_vec *v1, const t_vec *v2)
{
	return ((t_vec){
		v1->x - v2->x,
		v1->y - v2->y,
	});
}

void	vec__sub_assign(t_vec *v1, t_vec *v2)
{
	v1->x -= v2->x;
	v1->y -= v2->y;
}
