#ifndef MULTIPLICATION_LOGIC_H
#define MULTIPLICATION_LOGIC_H

/*
This function is more complex, it takes 2 numbers represented by strings and multiplies them by going through each digit.
A result array is returned and the input arrays are freed.
*/
char* multiply (char* raw_a, char* raw_b);

/*
A function that clears zeros from front of a string by shifting the whole number forwards to be at the start of the string.
*/
void clear_zeroes_from_front(char* str, int full_str_len, int full_result_first_i);

/*
Simple function that writes 0 chars into a string.
*/
void zero_str_arr(char* str, int str_len);

/*
A function that returns a string without leading zeros.
*/
char* filter_str_zeros(const char* raw_str);

#endif