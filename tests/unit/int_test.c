#include "../tests.h"

static int test_print(void)
{
	int len = 0;
	int i;

	for (i = 0; i <= 100; i++)
		len += _printf("%d", i);

	for (i = 0; i >= -100; i--)
		len += _printf("%d", i);

	len += _printf("%d", INT_MAX);
	len += _printf("%d", INT_MIN);

	len += _printf("%+d", 123);
	len += _printf("%++d", 123);
	len += _printf("%+d", -123);
	len += _printf("%++d", -123);

	len += _printf("% d", 123);
	len += _printf("%  d", 123);
	len += _printf("% d", -123);
	len += _printf("%  d", -123);

	len += _printf("%+ d", 123);
	len += _printf("%+ d", -123);

	return len;
}

static int expect_print(void)
{
	int len = 0;
	int i;

	for (i = 0; i <= 100; i++)
		len += printf("%d", i);

	for (i = 0; i >= -100; i--)
		len += printf("%d", i);

	len += printf("%d", INT_MAX);
	len += printf("%d", INT_MIN);

	len += printf("%+d", 123);
	len += printf("%++d", 123);
	len += printf("%+d", -123);
	len += printf("%++d", -123);

	len += printf("% d", 123);
	len += printf("%  d", 123);
	len += printf("% d", -123);
	len += printf("%  d", -123);

	len += printf("%+ d", 123);
	len += printf("%+ d", -123);

	return len;
}

void int_test(void)
{
	test_case("int", test_print, expect_print);
}
