#include "../tests.h"

static int test_print(void)
{
	int len = 0;

	len += _printf("%S\n", "Best\nSchool");

	return len;
}

static int expect_print(void)
{
	int len = 0;

	len += printf("Best\\x0ASchool\n");

	return len;
}

void str_np_test(void)
{
	test_case("str_np", test_print, expect_print);
}
