#ifndef DYNAMIC_INPUT_H
#define DYNAMIC_INPUT_H

/*
This function saves terminal input into a string, unlike scanf, this function creates the array for the string ahead of time,
which means it can handle strings of any size and the array does not have to be allocated before getting the input.
The function returns an array of chars of what the user wrote, it stops saving on a newline.
*/
char* get_user_input_str();

/*
Just a simple function used to clear any newline characters before get_user_input_str is used again to prevent a bug.
*/
void flush_input();

#endif