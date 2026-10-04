#ifndef DECIMALS_LOGIC
#define DECIMALS_LOGIC
#include <stdlib.h>
#include <stdbool.h>

/*
Returns size_t index where the decimal point is located, if decimal point doesnt exist, returns 0.
*/
size_t find_decimal_point_i(char* num);

/*
Returns amount of decimals between decimal point and null terminator.
*/
int count_decimals(char* num, size_t d_i);

/*
Returns original string with decimal point removed and numbers after it shifted by one to start.
*/
char* remove_decimal_point(char* num, size_t d_i);

/*
Returns the original array with decimal point added at input index. Assumes the num string array has at least 1 reserve index.
*/
char* insert_decimal_point(char* num, int decimal_count);

#endif