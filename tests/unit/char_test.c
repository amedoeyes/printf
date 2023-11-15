#include "../tests.h"

static int test_print(void)
{
	int len = 0;
	int i;

	for (i = 0; i <= 128; i++)
		len += _printf("%c", i);

	len += _printf("char: %c.", 'a');

	return len;
}

static int expect_print(void)
{
	int len = 0;
	int i;

	for (i = 0; i <= 128; i++)
		len += printf("%c", i);

	len += printf("char: %c.", 'a');

	return len;
}

void char_test(void)
{
	test_case("char", test_print, expect_print);
}
