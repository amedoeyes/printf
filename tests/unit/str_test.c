#include "../tests.h"

static int test_print(void)
{
	int len = 0;

	len += _printf("%s", "Hello");
	len += _printf("%s", NULL);
	len += _printf("%s", "1234567890");
	len += _printf("%s", "aaaaaaaaaa\0AAAAAAA");
	len += _printf("%s", "");
	len += _printf("%s", "This is a very long string to test the handling of "
						 "large strings in %s");
	len += _printf("%s", "Newline \n Tab \t Backslash \\ Quote \" ");
	len += _printf("%s", "!@#$%^&*()_+1234567890");
	len += _printf("%s", "你好，世界");
	len += _printf("%s", "AbCdEfGhIjKlMnOpQrStUvWxYz");
	len += _printf("%s", "   This has leading and trailing spaces   ");
	len += _printf("%s", "abc\0def\0ghi");
	len += _printf(NULL);

	return len;
}

static int expect_print(void)
{
	int len = 0;

	len += printf("%s", "Hello");
	len += printf("%s", NULL);
	len += printf("%s", "1234567890");
	len += printf("%s", "aaaaaaaaaa\0AAAAAAA");
	len += _printf("%s", "");
	len += printf("%s", "This is a very long string to test the handling of "
						"large strings in %s");
	len += printf("%s", "Newline \n Tab \t Backslash \\ Quote \" ");
	len += printf("%s", "!@#$%^&*()_+1234567890");
	len += printf("%s", "你好，世界");
	len += printf("%s", "AbCdEfGhIjKlMnOpQrStUvWxYz");
	len += printf("%s", "   This has leading and trailing spaces   ");
	len += printf("%s", "abc\0def\0ghi");
	len += _printf(NULL);

	return len;
}

void str_test(void)
{
	test_case("str", test_print, expect_print);
}
