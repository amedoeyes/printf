#ifndef TEST_H
#define TEST_H

#include "../main.h"
#include <limits.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>

bool compare_stdout(int (*test)(), int (*expect)());
void test_case(const char *name, int (*test)(), int (*expect)());

void char_test(void);
void str_test(void);
void int_test(void);
void bin_test(void);
void uint_test(void);
void oct_test(void);
void hex_test(void);
void str_np_test(void);
void addr_test(void);
void str_rev_test(void);
void str_rot13_test(void);
void space_pad_test(void);
void length_test(void);
void precision_test(void);
void zeros_test(void);

#endif
