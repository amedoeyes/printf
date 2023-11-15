#include "../tests.h"

static int test_print(void)
{
	int len = 0;

	len += _printf("%r", "abcdefghijklmnopqrstuvwxyz123456789");

	return len;
}

static int expect_print(void)
{
	int len = 0;

	len += printf("987654321zyxwvutsrqponmlkjihgfedcba");

	return len;
}

void str_rev_test(void)
{
	test_case("str_rev", test_print, expect_print);
}
