#ifndef MODE_SWITCH
#define MODE_SWITCH
//Work in progress.
#include <stdio.h>

/*
This function gets user input and returns the char, which also represents the calculator mode.
*/
char get_mode();

/*
This function will switch the mode of the calculator when called.
*/
void switch_mode(char current_mode, char old_mode);

#endif