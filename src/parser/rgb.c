#include "types__parser.h"
#include "std__color.h"
#include "std__math.h"
#include <stdio.h>

void	rgb__print(t_rgb rgb)
{
	const int	r = rgb >> 16 & 0xFF;
	const int	g = rgb >> 8 & 0xFF;
	const int	b = rgb & 0xFF;

	printf(BWHT "[" HRED
		"%03d " HGRN "%03d " HBLU "%03d"
		BWHT "]" END, r, g, b);
}

t_rgb	rgb__from_arr(int raw_rgb[3])
{
	const int	r = raw_rgb[0] << 16;
	const int	g = raw_rgb[1] << 8;
	const int	b = raw_rgb[2] << 0;

	return (r | g | b);
}

t_rgb	rgb__from_string(t_const_string str, t_const_string delim)
{
	int			i;
	int			raw_rgb[3];
	t_int_res	parse_res;
	t_string	*arr;
	int			arr_len;

	arr = str__new_split(str, delim);
	arr_len = str__len__arr(arr);
	if (arr_len != 3)
		std__panic__index("rgb__from_string", arr_len, 3);
	i = -1;
	while (++i < 3)
	{
		str__strip(&arr[i], STD__SPACES);
		parse_res = str__to_int(arr[i]);
		if (parse_res.err)
			std__panic__value("rgb__from_string", arr[i]);
		raw_rgb[i] = parse_res.num;
		if (not math__in_range(raw_rgb[i], (t_irange){0, 255}))
			std__panic__index("rgb__from_string", raw_rgb[i], 255);
	}
	str__delete__arr(&arr);
	return (rgb__from_arr(raw_rgb));
}
