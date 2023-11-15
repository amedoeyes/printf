#include "../tests.h"

static int test_print(void)
{
	int len = 0;

	len += _printf("%R", "abcdefghijklmnopqrstuvwxyz123456789");

	return len;
}

static int expect_print(void)
{
	int len = 0;

	len += printf("nopqrstuvwxyzabcdefghijklm123456789");

	return len;
}

void str_rot13_test(void)
{
	test_case("str_rot13", test_print, expect_print);
}
