#include "std__math.h"
#include <math.h>
#include <stddef.h>

int	math__max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

int	math__min(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}

int	math__clamp(int n, t_irange range)
{
	return (math__min(math__max(n, range.start), range.end));
}

int	math__digit_len(int num)
{
	int	result;

	result = 0;
	while (num)
	{
		num /= 10;
		result++;
	}
	return (result);
}

int	math__normalize(int num, t_irange from, t_irange to)
{
	const int	map_len = math__max(from.end - from.start, 1);
	const int	num_len = math__max(to.end - to.start, 1);

	return ((num - from.start) * num_len / map_len);
}
