#include "../tests.h"

static int test_print(void)
{
	int len = 0;

	len += _printf("%10c", 'a');
	len += _printf("%-10c", 'a');

	len += _printf("%10s", "aa");
	len += _printf("%10s", NULL);
	len += _printf("%-10s%s", "aa", "aa");

	len += _printf("%10d", 123);
	len += _printf("%10d", -123);
	len += _printf("% 10d", 123);
	len += _printf("% 10d", -123);
	len += _printf("%+10d", 123);
	len += _printf("%+10d", -123);
	len += _printf("%-10d", 123);
	len += _printf("%-10d", -123);

	len += _printf("%10b", 123);
	len += _printf("%10b", -123);
	len += _printf("%-10b", 123);
	len += _printf("%-10b", -123);

	len += _printf("%10x", 123);
	len += _printf("%10x", -123);
	len += _printf("%-10x", 123);
	len += _printf("%-10x", -123);

	len += _printf("%10X", 123);
	len += _printf("%10X", -123);
	len += _printf("%-10X", 123);
	len += _printf("%-10X", -123);

	len += _printf("%#10x", 123);
	len += _printf("%#10x", -123);
	len += _printf("%#-10x", 123);
	len += _printf("%#-10x", -123);

	len += _printf("%#10X", 123);
	len += _printf("%#10X", -123);
	len += _printf("%#-10X", 123);
	len += _printf("%#-10X", -123);

	len += _printf("%10o", 123);
	len += _printf("%10o", -123);
	len += _printf("%-10o", 123);
	len += _printf("%-10o", -123);

	len += _printf("%#10o", 123);
	len += _printf("%#10o", -123);
	len += _printf("%#-10o", 123);
	len += _printf("%#-10o", -123);

	len += _printf("%10u", 123);
	len += _printf("%10u", -123);
	len += _printf("%-10u", 123);
	len += _printf("%-10u", -123);

	len += _printf("%10p", (void *)0x7ffe637541f0);
	len += _printf("%10p", NULL);

	len += _printf("%*c", 10, 'c');
	len += _printf("%*s", 10, "hello");
	len += _printf("%*d", 10, 123);
	len += _printf("%*b", 10, 123);
	len += _printf("%*x", 10, 123);
	len += _printf("%*o", 10, 123);
	len += _printf("%*u", 10, 123);
	len += _printf("%*p", 10, (void *)0x7ffe637541f0);

	return len;
}

static int expect_print(void)
{
	int len = 0;

	len += printf("%10c", 'a');
	len += printf("%-10c", 'a');

	len += printf("%10s", "aa");
	len += printf("%10s", NULL);
	len += printf("%-10s%s", "aa", "aa");

	len += printf("%10d", 123);
	len += printf("%10d", -123);
	len += printf("% 10d", 123);
	len += printf("% 10d", -123);
	len += printf("%+10d", 123);
	len += printf("%+10d", -123);
	len += printf("%-10d", 123);
	len += printf("%-10d", -123);

	len += printf("%10b", 123);
	len += printf("%10b", -123);
	len += printf("%-10b", 123);
	len += printf("%-10b", -123);

	len += printf("%10x", 123);
	len += printf("%10x", -123);
	len += printf("%-10x", 123);
	len += printf("%-10x", -123);

	len += printf("%10X", 123);
	len += printf("%10X", -123);
	len += printf("%-10X", 123);
	len += printf("%-10X", -123);

	len += printf("%#10x", 123);
	len += printf("%#10x", -123);
	len += printf("%#-10x", 123);
	len += printf("%#-10x", -123);

	len += printf("%#10X", 123);
	len += printf("%#10X", -123);
	len += printf("%#-10X", 123);
	len += printf("%#-10X", -123);

	len += printf("%10o", 123);
	len += printf("%10o", -123);
	len += printf("%-10o", 123);
	len += printf("%-10o", -123);

	len += printf("%#10o", 123);
	len += printf("%#10o", -123);
	len += printf("%#-10o", 123);
	len += printf("%#-10o", -123);

	len += printf("%10u", 123);
	len += printf("%10u", -123);
	len += printf("%-10u", 123);
	len += printf("%-10u", -123);

	len += printf("%10p", (void *)0x7ffe637541f0);
	len += printf("%10p", NULL);

	len += printf("%*c", 10, 'c');
	len += printf("%*s", 10, "hello");
	len += printf("%*d", 10, 123);
	len += printf("%*b", 10, 123);
	len += printf("%*x", 10, 123);
	len += printf("%*o", 10, 123);
	len += printf("%*u", 10, 123);
	len += printf("%*p", 10, (void *)0x7ffe637541f0);

	return len;
}

void space_pad_test(void)
{
	test_case("space_pad", test_print, expect_print);
}
