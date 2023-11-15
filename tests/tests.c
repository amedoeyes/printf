#include "tests.h"
#include "../main.h"
#include <stdio.h>

int main(void)
{
	char_test();
	str_test();
	int_test();
	bin_test();
	uint_test();
	oct_test();
	hex_test();
	str_np_test();
	addr_test();
	str_rev_test();
	str_rot13_test();
	space_pad_test();
	length_test();
	precision_test();

	return (0);
}
