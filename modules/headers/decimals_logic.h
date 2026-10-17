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
Removes decimal point from string and numbers after it are shifted by one to start.
*/
void remove_decimal_point(char* num, size_t d_i);

/*
Function which is used to fill a number string with zeroes before inserting decimal point, used in edge cases inside the insert_decimal_point function.
*/
void pre_fill_decimal_with_zeroes(char* num, size_t zero_count);

/*
Inserts decimal point into its position using decimal_count. Assumes the num string array has reserve indexes for all the decimals.
*/
void insert_decimal_point(char* num, size_t decimal_count);

#endif