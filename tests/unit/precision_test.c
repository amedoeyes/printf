#include "../tests.h"

static int test_print(void)
{
	int len = 0;

	len += _printf("%.s", "Hello");
	len += _printf("%.4s", "Hello");
	len += _printf("%.10s", "Hello");

	len += _printf("%.d", 123);
	len += _printf("%.2d", 123);
	len += _printf("%.5d", 123);
	len += _printf("%.*d", 5, 123);
	len += _printf("%.d", 123);
	len += _printf("%.0d", 123);
	len += _printf("%.d", -123);
	len += _printf("%.0d", -123);

	len += _printf("%.b", 123);
	len += _printf("%.2b", 123);
	len += _printf("%.5b", 123);
	len += _printf("%.*b", 5, 123);

	len += _printf("%.u", 123);
	len += _printf("%.2u", 123);
	len += _printf("%.5u", 123);
	len += _printf("%.*u", 5, 123);

	len += _printf("%.o", 123);
	len += _printf("%.2o", 123);
	len += _printf("%.5o", 123);
	len += _printf("%.*o", 5, 123);

	len += _printf("%.x", 123);
	len += _printf("%.2x", 123);
	len += _printf("%.5x", 123);
	len += _printf("%.*x", 5, 123);

	len += _printf("%.X", 123);
	len += _printf("%.2X", 123);
	len += _printf("%.5X", 123);
	len += _printf("%.*X", 5, 123);

	len += _printf("%.p", (void *)0x123f23b);
	len += _printf("%.2p", 5, (void *)0x123f23b);
	len += _printf("%.5p", (void *)0x123f23b);
	len += _printf("%.*p", 5, (void *)0x123f23b);

	len += _printf("%.*d", -5, 123);

	return len;
}

static int expect_print(void)
{
	int len = 0;

	len += printf("%.s", "Hello");
	len += printf("%.4s", "Hello");
	len += printf("%.10s", "Hello");

	len += printf("%.d", 123);
	len += printf("%.2d", 123);
	len += printf("%.5d", 123);
	len += printf("%.*d", 5, 123);
	len += printf("%.d", 123);
	len += printf("%.0d", 123);
	len += printf("%.d", -123);
	len += printf("%.0d", -123);

	len += printf("%.b", 123);
	len += printf("%.2b", 123);
	len += printf("%.5b", 123);
	len += printf("%.*b", 5, 123);

	len += printf("%.u", 123);
	len += printf("%.2u", 123);
	len += printf("%.5u", 123);
	len += printf("%.*u", 5, 123);

	len += printf("%.o", 123);
	len += printf("%.2o", 123);
	len += printf("%.5o", 123);
	len += printf("%.*o", 5, 123);

	len += printf("%.x", 123);
	len += printf("%.2x", 123);
	len += printf("%.5x", 123);
	len += printf("%.*x", 5, 123);

	len += printf("%.X", 123);
	len += printf("%.2X", 123);
	len += printf("%.5X", 123);
	len += printf("%.*X", 5, 123);

	len += printf("%.p", (void *)0x123f23b);
	len += printf("%.2p", 5, (void *)0x123f23b);
	len += printf("%.5p", (void *)0x123f23b);
	len += printf("%.*p", 5, (void *)0x123f23b);

	len += printf("%.*d", -5, 123);

	return len;
}

void precision_test(void)
{
	test_case("precision", test_print, expect_print);
}
