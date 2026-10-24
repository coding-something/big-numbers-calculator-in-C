#ifndef DYNAMIC_MEMORY_H
#define DYNAMIC_MEMORY_H

#include <stddef.h>
#include <stdbool.h>

/*
A function that is used to properly resize a string, mostly used when more memory is needed.
Custom_resize_value is optional, input 0 or less if you want it disabled, on default doubles array size.
Also contains primitive realloc failure handling, but as of now it only returns and causes a crash.
*/
char* resize_str_arr(char* original_str, size_t* current_limit, size_t custom_resize_value);

/*
This function just checks if the string was allocated successfully or not.
*/
bool check_allocated_memory_of_str(char* str);

#endif