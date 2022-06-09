#include "std__math.h"

t_vec	vec__mul(const t_vec *vec, double amount)
{
	return ((t_vec){
		.x = vec->x * amount,
		.y = vec->y * amount
	});
}

void	vec__mul_assign(t_vec *vec, double amount)
{
	vec->x *= amount;
	vec->y *= amount;
}
