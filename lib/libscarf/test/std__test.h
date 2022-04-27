#ifndef STD__TEST_H
# define STD__TEST_H

# include "std__color.h"
# include "std__types.h"
# include "std__types__error.h"
# include <stdio.h>
# include <stdlib.h>

void	test__header(t_const_string text)
{
	printf(BHYEL "\n----------------------------------------\n");
	printf("[[[ Testing " BBLU "%s" BHYEL " ]]]\n", text);
}

void	test__subject(t_const_string text)
{
	printf(MAG "  [ case " BCYN "%s" MAG " ]\n" END, text);
}

# define TEST__ASSERT_EQ(left, right)                                         \
	do                                                                       \
	{                                                                        \
		assert(left == right);                                               \
		printf(HWHT "{ " BBLU #left " == " #right HWHT " } " BGRN " OK!" END \
					"\n");                                                   \
	} while (0);

# define TEST__ASSERT_EQ_FREE(left, right)                                    \
	do                                                                       \
	{                                                                        \
		assert(left == right);                                               \
		printf(HWHT "{ " BBLU #left " == " #right HWHT " } " BGRN " OK!" END \
					"\n");                                                   \
		free(left);                                                          \
	} while (0);

# define TEST__ASSERT_EQ_STR_FREE(left, right)                                \
	do                                                                       \
	{                                                                        \
		char *str = left;                                                    \
		assert(str__is_equal(str, right));                                   \
		printf(HWHT "{ " BBLU #left " == " #right HWHT " } " BGRN " OK!" END \
					"\n");                                                   \
		free(str);                                                           \
	} while (0);

# define TEST__ASSERT_EXPR(expr)                                    \
	do                                                             \
	{                                                              \
		assert(expr);                                              \
		printf(HWHT "{ " BBLU #expr HWHT " } " BGRN " OK!\n" END); \
	} while (0);

#endif
