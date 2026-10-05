#ifndef DECIMALS_LOGIC
#define DECIMALS_LOGIC
#include <stdlib.h>
#include <stdbool.h>

/*
Checks if decimal point exists in number, if yes returns true otherwise false.
*/
bool check_if_decimal_point_exists(char* num);

/*
Returns size_t index where the decimal point is located, if decimal point doesnt exist, returns 0.
*/
size_t find_decimal_point_i(char* num);

/*
Returns amount of decimals between decimal point and null terminator.
*/
size_t count_decimals(char* num, size_t d_i);

/*
Returns original string with decimal point removed and numbers after it shifted by one to start.
*/
char* remove_decimal_point(char* num, size_t d_i);

/*
Function which is used to fill a number string with zeroes before inserting decimal point, used in edge cases inside the insert_decimal_point function.
*/
char* pre_fill_decimal_with_zeroes(char* num, size_t zero_count);

/*
Returns the original array with decimal point added at input index. Assumes the num string array has reserve indexes for all the decimals.
*/
char* insert_decimal_point(char* num, size_t decimal_count);

#endif