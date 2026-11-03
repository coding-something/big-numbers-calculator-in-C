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
Inserts decimal point into its position using decimal_count. Assumes the num string array has reserve indexes for all the decimals. Adds lead zero if 
decimal point is at index zero.
*/
void insert_decimal_point(char* num, size_t decimal_count);

/*
Removes trailing zeros after decimal point.
*/
void remove_decimal_trailing_zeros(char* num_str, size_t decimal_point);

/*
This function is used to add trailing zeros so multiple number strings can have the same amount of decimals. Assumes reserve memory has been allocated.
*/
char* get_equal_decimals_num(char* num_str, size_t decimal_point_i, size_t equalized_decimal_count);

#endif