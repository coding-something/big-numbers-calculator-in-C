#ifndef ADD_SUBTRACT_LOGIC
#define ADD_SUBTRACT_LOGIC
#include <stdbool.h>

/*
This function handles addition and subtraction between 2 numbers in strings, returns dynamically allocated string.
*/
char* add_or_subtract(char* num1, char* num2);

/*
This function checks if adding up 2 numbers will result in negative result, input numbers must be stripped of minus signs and decimal points.
*/
bool check_for_negative_addition_result(char* stripped_num_a, char* stripped_num_b, bool is_a_negative, bool is_b_negative);

/*
A function which compares 2 numbers stored in strings and finds the larger one, input numbers must be stripped of minus signs and decimal points.
*/
char* find_larger_number(char* stripped_num_a, char* stripped_num_b);

/*
This function returns the number string resized so it is the same length as the bigger number, calling this on the bigger number does not resize it.
*/
char* get_equal_size_num(char* num_to_resize, char* other_num);
#endif