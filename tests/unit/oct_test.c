#include "../tests.h"

static int test_print(void)
{
	int len = 0;

	len += _printf("%o", 123);
	len += _printf("%o", -123);

	len += _printf("%#o", 123);
	len += _printf("%##o", 123);
	len += _printf("%###o", -123);

	len += _printf("%#o", 0);

	return len;
}

static int expect_print(void)
{
	int len = 0;

	len += printf("%o", 123);
	len += printf("%o", -123);

	len += printf("%#o", 123);
	len += printf("%##o", 123);
	len += printf("%###o", -123);

	len += printf("%#o", 0);

	return len;
}

void oct_test(void)
{
	test_case("oct", test_print, expect_print);
}
