#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILE_PATH_TEST "/tmp/stdout_test.txt"
#define FILE_PATH_EXPECT "/tmp/stdout_expect.txt"

void write_to_files(int (*test)(), int (*expect)())
{
	freopen(FILE_PATH_TEST, "w", stdout);
	test();
	fclose(stdout);

	freopen(FILE_PATH_EXPECT, "w", stdout);
	expect();
	fclose(stdout);

	freopen("/dev/tty", "w", stdout);
}

void read_from_files(char **test_buf, char **expect_buf)
{
	long test_len;
	long expect_len;
	FILE *test_file = fopen(FILE_PATH_TEST, "r");
	FILE *expect_file = fopen(FILE_PATH_EXPECT, "r");

	fseek(test_file, 0, SEEK_END);
	test_len = ftell(test_file);
	fseek(test_file, 0, SEEK_SET);

	fseek(expect_file, 0, SEEK_END);
	expect_len = ftell(expect_file);
	fseek(expect_file, 0, SEEK_SET);

	*test_buf = malloc(test_len + 1);
	fread(*test_buf, 1, test_len, test_file);
	(*test_buf)[test_len] = '\0';
	fclose(test_file);

	*expect_buf = malloc(expect_len + 1);
	fread(*expect_buf, 1, expect_len, expect_file);
	(*expect_buf)[expect_len] = '\0';
	fclose(expect_file);
}

bool compare_stdout(int (*test)(), int (*expect)())
{
	char *test_buf;
	char *expect_buf;
	bool result;

	write_to_files(test, expect);

	read_from_files(&test_buf, &expect_buf);

	result = strcmp(test_buf, expect_buf) == 0;

	free(test_buf);
	free(expect_buf);

	return (result);
}
