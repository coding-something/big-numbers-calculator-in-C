#ifndef MODE_LOGIC
#define MODE_LOGIC
//Work in progress.
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

/*
This function gets user input and returns the char, which also represents the calculator mode.
*/
char get_mode();

/*
This function will switch the mode of the calculator when called.
*/
void switch_mode(char current_mode);

/*
This function triggers secondary loop for multiplication.
*/
void trigger_multiplication_mode();

/*
This function triggers secondary loop for factorial. NOT IMPLEMENTED YET.
*/
void trigger_factorial_mode();

/*
This function checks if user wants to exit mode or the whole program and returns bool.
*/
bool check_for_user_exit(bool is_mode);

#endif