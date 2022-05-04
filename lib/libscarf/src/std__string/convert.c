#include "std__math.h"
#include "std__string.h"
#include "std__system.h"
#include <limits.h>

t_string	str__new_from_int(int num)
{
	t_string	str;
	int			digit;

	if (num == 0)
		return (str__new("0"));
	digit = math__digit_len(num);
	if (num < 0)
		digit++;
	str = std__allocate(sizeof(char), digit);
	if (num < 0)
	{
		num = -num;
		str[0] = '-';
	}
	while (num > 0)
	{
		str[--digit] = '0' + (num % 10);
		num /= 10;
	}
	return (str);
}

t_int_res	str__to_int(t_const_string str)
{
	int		i;
	int		sign;
	t_i64	num;

	num = 0;
	sign = 1;
	if (!str)
		return ((t_int_res){ERR, 0});
	i = str__find_first_not_of(str, STD__SPACES);
	if (i == ERR)
		return ((t_int_res){ERR, 0});
	if (str__is_in("-+", str[i]))
		if (str[i++] == '-')
			sign = -1;
	while (is_digit(str[i]))
	{
		num = 10 * num + (str[i++] - '0');
		if ((sign == 1 && num > INT_MAX) || (sign == -1 && num > INT_MIN_ABS))
			return ((t_int_res){ERR, 0});
	}
	if (!str[i] || str__find_first_not_of(str + i, STD__SPACES) == ERR)
		return ((t_int_res){OK, sign * num});
	return ((t_int_res){ERR, ERR});
}
