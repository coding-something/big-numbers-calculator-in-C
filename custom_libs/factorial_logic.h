#ifndef FACTORIAL_LOGIC
#define FACTORIAL_LOGIC
#include <stddef.h>

/*
This function calculates the factorial value and returns string representing the result.
*/
char* calculate_factorial(int n);

/*
This function does factorial multiplication, used in calculate_factorial, returns string.
*/
char* multiply_factorial_str(char* fact_str, int multiplier, size_t* arr_size);

/*
Simple function that calculates the amount of digits in an int.
*/
int get_len_of_int(int n);

#endif