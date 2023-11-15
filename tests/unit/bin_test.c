#include "../tests.h"

static int test_print(void)
{
	int len = 0;

	len += _printf("%b", 123);
	len += _printf("%b", -123);

	return len;
}

static int expect_print(void)
{
	int len = 0;

	len += printf("%b", 123);
	len += printf("%b", -123);

	return len;
}

void bin_test(void)
{
	test_case("bin", test_print, expect_print);
}
