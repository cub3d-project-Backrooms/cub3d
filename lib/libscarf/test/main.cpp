#include <assert.h>
#include <stdio.h>
#include "std__string.h"
#include "std__system.h"
#include "std__test.h"

void test__malloc(void) {
  test__header("malloc NULL terminates last element");
  for (int i = 0; i < 128; i++) {
    char* char_ptr = std__allocate(i, sizeof(char));
    // for (int j = 0; char_ptr[j]; j++)
    assert(char_ptr[i] == '\0');
    std__dealloc((void**)&char_ptr);
    int* int_ptr = std__allocate(i, sizeof(int));
    // for (int j = 0; int_ptr[j]; j++);
    assert(int_ptr[i] == '\0');
    std__dealloc((void**)&int_ptr);
    double* float_ptr = std__allocate(i, sizeof(double));
    // for (int j = 0; float_ptr[j]; j++);
    assert(float_ptr[i] == '\0');
    std__dealloc((void**)&float_ptr);
  }
  test__subject("done.");
}

void test__string__cmp(void) {
  test__header("string::cmp");
  TEST__ASSERT_EQ(str__ncmp("abc", "abc", 3), 0);
  TEST__ASSERT_EQ(str__ncmp("abc", "abcd", 3), 0);
  TEST__ASSERT_EQ(str__ncmp("abc", "abb", 3), 1);
  TEST__ASSERT_EQ(str__ncmp("abb", "abc", 3), -1);
  TEST__ASSERT_EQ(str__ncmp("abcd", "abc", 4), 'd');
}

void test__string__len(void) {
  test__header("str::len");
  TEST__ASSERT_EQ(str__len("abc"), 3);
  TEST__ASSERT_EQ(str__len(""), 0);
  TEST__ASSERT_EQ(str__len(NULL), -1);
}

void test__string__is_equal(void) {
  test__header("str::is_equal");
  TEST__ASSERT_EXPR(str__is_equal("hello world", "hello world"));
  TEST__ASSERT_EXPR(not str__is_equal("hello world", "hello world!"));
  TEST__ASSERT_EXPR(not str__is_equal("hello world", "bye world"));
  TEST__ASSERT_EXPR(not str__is_equal("hello world", NULL));
}

void test__string__find(void) {
  test__header("str::find related");
  test__subject("str::find");
  TEST__ASSERT_EQ(str__find("hello world", "hello"), 0);
  TEST__ASSERT_EQ(str__find("hello world", "world"), 6);
  TEST__ASSERT_EQ(str__find("hello world", "bye"), ERR);
  TEST__ASSERT_EQ(str__find("hello world", ""), 0);
  TEST__ASSERT_EQ(str__find("hello world", NULL), ERR);
  test__subject("str::find_first_of");
  TEST__ASSERT_EQ(str__find_first_of("hello world", "abc"), ERR);
  TEST__ASSERT_EQ(str__find_first_of("hello world", "def"), 1);
  TEST__ASSERT_EQ(str__find_first_of("hello world", ""), ERR);
  TEST__ASSERT_EQ(str__find_first_of("hello world", NULL), ERR);
  test__subject("str::find_first_not_of");
  TEST__ASSERT_EQ(str__find_first_not_of("hello world", "abc"), 0);
  TEST__ASSERT_EQ(str__find_first_not_of("hello world", "helo"), 5);
  TEST__ASSERT_EQ(str__find_first_not_of("hello world", ""), 0);
  TEST__ASSERT_EQ(str__find_first_not_of("hello world", "hello world"), ERR);
  TEST__ASSERT_EQ(str__find_first_not_of("hello world", NULL), ERR);
  test__subject("str::at");
  TEST__ASSERT_EQ(str__at("hello world", 0), 'h');
  TEST__ASSERT_EQ(str__at("hello world", 1), 'e');
  TEST__ASSERT_EQ(str__at("hello world", -1), 'd');
  TEST__ASSERT_EQ(str__at("hello world", -2), 'l');
}

void test__string__conversion(void) {
  test__header("str::conversion");
  test__subject("str__to_int");
  TEST__ASSERT_EQ(str__to_int("123").num, 123);
  TEST__ASSERT_EQ(str__to_int("-123").num, -123);
  TEST__ASSERT_EQ(str__to_int("123a").err, ERR);
  TEST__ASSERT_EQ(str__to_int("a123").err, ERR);
  test__subject("int min/max");
  TEST__ASSERT_EQ(str__to_int("2147483647").num, 2147483647);
  TEST__ASSERT_EQ(str__to_int("-2147483648").num, -2147483648);
  test__subject("integer overflow");
  TEST__ASSERT_EQ(str__to_int("2147483648").err, ERR);
  TEST__ASSERT_EQ(str__to_int("-2147483649").err, ERR);
}

void test__string__substr(void) {
  test__header("str::substr");
  TEST__ASSERT_EQ_STR_FREE(
      str__new_substr("hello world", 0, 5), "hello");
  TEST__ASSERT_EQ_STR_FREE(
      str__new_substr("hello world", 6, 5), "world");
  TEST__ASSERT_EQ_STR_FREE(
      str__new_substr("hello world", 0, -1), "hello world");
}

void test__string__split(void) {
	test__header("str::count_of");
	TEST__ASSERT_EQ(str__count_of("hello world", " "), 1);
	TEST__ASSERT_EQ(str__count_of("hello world", "l"), 3);
	TEST__ASSERT_EQ(str__count_of("hello world", "ll"), 1);
	TEST__ASSERT_EQ(str__count_of("hello world", "lll"), 0);

	test__header("str::split");
	test__subject("by \" \"");
	t_string s = str__new("hello world");
	t_string* split1 = str__new_split(s, " ");
	for (int i = 0; split1[i]; i++) {
		printf("%s\n", split1[i]);
	}
	TEST__ASSERT_EXPR(str__is_equal(split1[0], "hello"));
	TEST__ASSERT_EXPR(str__is_equal(split1[1], "world"));
	TEST__ASSERT_EXPR(split1[2] == NULL);
	test__subject("by l");
	t_string* split2 = str__new_split(s, "l");
	TEST__ASSERT_EXPR(str__is_equal(split2[0], "he"));
	TEST__ASSERT_EXPR(str__is_equal(split2[1], ""));
	TEST__ASSERT_EXPR(str__is_equal(split2[2], "o wor"));
	TEST__ASSERT_EXPR(str__is_equal(split2[3], "d"));
	TEST__ASSERT_EXPR(split2[4] == NULL);
	test__subject("by ll");
	t_string* split3 = str__new_split(s, "ell");
	TEST__ASSERT_EXPR(str__is_equal(split3[0], "h"));
	TEST__ASSERT_EXPR(str__is_equal(split3[1], "o world"));
	TEST__ASSERT_EXPR(split3[2] == NULL);
	test__subject("by non-existing");
	t_string* split4 = str__new_split(s, "z");
	TEST__ASSERT_EXPR(str__is_equal(split4[0], "hello world"));
	TEST__ASSERT_EXPR(split4[1] == NULL);
}

int main(void) {
  test__string__cmp();
  test__string__len();
  test__string__is_equal();
  test__string__find();
  test__string__conversion();
  test__string__substr();
  test__string__split();
  test__malloc();

  // t_string str = str__new("hello world");
  // str__delete(&str);
  // TEST__ASSERT_EQ(str, NULL);
  // str__at("hello", 20);
  // std__panic("str__new");
  return (0);
}
