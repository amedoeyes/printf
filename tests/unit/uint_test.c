#include "../tests.h"

static int test_print(void)
{
	int len = 0;

	len += _printf("%u", (unsigned int)INT_MAX + 10);

	return len;
}

static int expect_print(void)
{
	int len = 0;

	len += printf("%u", (unsigned int)INT_MAX + 10);

	return len;
}

void uint_test(void)
{
	test_case("uint", test_print, expect_print);
}
