#ifndef MULTIPLICATION_LOGIC_H
#define MULTIPLICATION_LOGIC_H

/*
This function is more complex, it takes 2 numbers represented by strings and multiplies them by going through each digit.
A result array is returned and the input arrays are freed.
*/
char* multiply (char* raw_a, char* raw_b);

/*
Simple function that writes 0 chars into char array and adds null terminator.
*/
void populate_str_with_zeros(char* str, int str_len);

/*
A function that returns the same, newly allocated string without leading zeros, does not free original str.
*/
char* filter_str_zeros(const char* raw_str);

#endif