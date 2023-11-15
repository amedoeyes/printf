#include "../tests.h"

static int test_print(void)
{
	int len = 0;

	len += _printf("%p", (void *)0x7ffe637541f0);
	len += _printf("%p", NULL);

	return len;
}

static int expect_print(void)
{
	int len = 0;

	len += printf("%p", (void *)0x7ffe637541f0);
	len += printf("%p", NULL);

	return len;
}

void addr_test(void)
{
	test_case("addr", test_print, expect_print);
}
