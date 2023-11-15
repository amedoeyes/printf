#include "../tests.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

void test_case(const char *name, int (*test)(), int (*expect)())
{
	int test_len;
	int expect_len;
	bool stdout_result;
	bool length_result;
	bool result;

	freopen("/dev/null", "w", stdout);

	test_len = test();
	expect_len = expect();

	freopen("/dev/tty", "w", stdout);

	stdout_result = compare_stdout(test, expect);
	length_result = test_len == expect_len;
	result = stdout_result && length_result;

	printf("----- %s -----\n", name);
	printf("Status: %s\n", result ? "PASS" : "FAIL");

	if (!length_result)
	{
		printf("Expected: %d\n", expect_len);
		printf("Got: %d\n", test_len);

		exit(1);
	}

	if (!stdout_result)
	{
		printf("Expected: ");
		expect();
		printf("\n");

		_printf("Got: ");
		test();
		_printf("\n");

		exit(1);
	}
}
