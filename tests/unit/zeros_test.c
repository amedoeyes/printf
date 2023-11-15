#include "../tests.h"

static int test_print(void)
{
	int len = 0;

	len += _printf("%010d", 123);
	len += _printf("%-010d", 123);
	len += _printf("%-010.5d", 123);
	len += _printf("%010.5d", 123);
	len += _printf("%010.*d", 5, 123);

	len += _printf("%010b", 123);
	len += _printf("%-010b", 123);
	len += _printf("%-010.5b", 123);
	len += _printf("%010.5b", 123);
	len += _printf("%010.*b", 5, 123);

	len += _printf("%010u", 123);
	len += _printf("%-010u", 123);
	len += _printf("%-010.5u", 123);
	len += _printf("%010.5u", 123);
	len += _printf("%010.*u", 5, 123);

	len += _printf("%010o", 123);
	len += _printf("%-010o", 123);
	len += _printf("%-010.5o", 123);
	len += _printf("%010.5o", 123);
	len += _printf("%010.*o", 5, 123);

	len += _printf("%010x", 123);
	len += _printf("%-010x", 123);
	len += _printf("%-010.5x", 123);
	len += _printf("%010.5x", 123);
	len += _printf("%010.*x", 5, 123);

	len += _printf("%010X", 123);
	len += _printf("%-010X", 123);
	len += _printf("%-010.5X", 123);
	len += _printf("%010.5X", 123);
	len += _printf("%010.*X", 5, 123);

	len += _printf("%010p", (void *)0x123fea);
	len += _printf("%-010p", (void *)0x123fea);
	len += _printf("%-010.5p", (void *)0x123fea);
	len += _printf("%010.5p", (void *)0x123fea);
	len += _printf("%010.*p", 5, (void *)0x123fea);

	return len;
}

static int expect_print(void)
{
	int len = 0;

	len += printf("%010d", 123);
	len += printf("%-010d", 123);
	len += printf("%-010.5d", 123);
	len += printf("%010.5d", 123);
	len += printf("%010.*d", 5, 123);

	len += printf("%010b", 123);
	len += printf("%-010b", 123);
	len += printf("%-010.5b", 123);
	len += printf("%010.5b", 123);
	len += printf("%010.*b", 5, 123);

	len += printf("%010u", 123);
	len += printf("%-010u", 123);
	len += printf("%-010.5u", 123);
	len += printf("%010.5u", 123);
	len += printf("%010.*u", 5, 123);

	len += printf("%010o", 123);
	len += printf("%-010o", 123);
	len += printf("%-010.5o", 123);
	len += printf("%010.5o", 123);
	len += printf("%010.*o", 5, 123);

	len += printf("%010x", 123);
	len += printf("%-010x", 123);
	len += printf("%-010.5x", 123);
	len += printf("%010.5x", 123);
	len += printf("%010.*x", 5, 123);

	len += printf("%010X", 123);
	len += printf("%-010X", 123);
	len += printf("%-010.5X", 123);
	len += printf("%010.5X", 123);
	len += printf("%010.*X", 5, 123);

	len += printf("%010p", (void *)0x123fea);
	len += printf("%-010p", (void *)0x123fea);
	len += printf("%-010.5p", (void *)0x123fea);
	len += printf("%010.5p", (void *)0x123fea);
	len += printf("%010.*p", 5, (void *)0x123fea);

	return len;
}

void zeros_test(void)
{
	test_case("zeros", test_print, expect_print);
}
