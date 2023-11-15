#include "../tests.h"

static int test_print(void)
{
	int len = 0;

	len += _printf("%x", 123);
	len += _printf("%x", -123);
	len += _printf("%X", 123);
	len += _printf("%X", -123);

	len += _printf("%#X", 123);
	len += _printf("%#X", -123);
	len += _printf("%##X", 123);
	len += _printf("%##X", -123);

	len += _printf("%#x", 123);
	len += _printf("%#x", -123);
	len += _printf("%##x", 123);
	len += _printf("%##x", -123);

	len += _printf("%#x", 0);
	len += _printf("%#X", 0);

	return len;
}

static int expect_print(void)
{
	int len = 0;

	len += printf("%x", 123);
	len += printf("%x", -123);
	len += printf("%X", 123);
	len += printf("%X", -123);

	len += printf("%#X", 123);
	len += printf("%#X", -123);
	len += printf("%##X", 123);
	len += printf("%##X", -123);

	len += printf("%#x", 123);
	len += printf("%#x", -123);
	len += printf("%##x", 123);
	len += printf("%##x", -123);

	len += printf("%#x", 0);
	len += printf("%#X", 0);

	return len;
}

void hex_test(void)
{
	test_case("hex", test_print, expect_print);
}
