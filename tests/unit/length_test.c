#include "../tests.h"

static int test_print(void)
{
	int len = 0;

	len += _printf("%dh", (short)INT_MAX);
	len += _printf("%dl", (long)INT_MAX + 10);

	len += _printf("%oh", (short)INT_MAX);
	len += _printf("%ol", (long)INT_MAX + 10);

	len += _printf("%uh", (short)INT_MAX);
	len += _printf("%ul", (long)INT_MAX + 10);

	len += _printf("%xh", (short)INT_MAX);
	len += _printf("%xl", (long)INT_MAX + 10);

	len += _printf("%Xh", (short)INT_MAX);
	len += _printf("%Xl", (long)INT_MAX + 10);

	return len;
}

static int expect_print(void)
{
	int len = 0;

	len += printf("%dh", (short)INT_MAX);
	len += printf("%dl", (long)INT_MAX + 10);

	len += printf("%oh", (short)INT_MAX);
	len += printf("%ol", (long)INT_MAX + 10);

	len += printf("%uh", (short)INT_MAX);
	len += printf("%ul", (long)INT_MAX + 10);

	len += printf("%xh", (short)INT_MAX);
	len += printf("%xl", (long)INT_MAX + 10);

	len += printf("%Xh", (short)INT_MAX);
	len += printf("%Xl", (long)INT_MAX + 10);

	return len;
}

void length_test(void)
{
	test_case("length", test_print, expect_print);
}
