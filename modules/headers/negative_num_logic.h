#ifndef NEGATIVE_NUMBER_LOGIC
#define NEGATIVE_NUMBER_LOGIC
#include <stdbool.h>
#include <stdlib.h>

//Checks if number is negative, returns true if yes otherwise false.
bool check_for_minus_sign(char* num);

//Removes minus or plus sign from start of the string.
void remove_sign(char* num, size_t len);

//Adds minus sign to the start of string, assumes string has one reserve index.
void add_minus_sign(char* num, size_t len);

#endif