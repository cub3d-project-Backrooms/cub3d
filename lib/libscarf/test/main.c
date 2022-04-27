//a

#include <assert.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include "std__string.h"
#include "std__system.h"
#include "std__test.h"
#include "std__string.h"
// #include "theft.h"

int main() {
	t_string str = str__new("hello");
	str__pad_right(&str, 3, '!');
	str__pad_left(&str, 3, '!');
	printf("[%s]\n", str);
	str__delete(&str);
	printf("DONE.\n");
}
