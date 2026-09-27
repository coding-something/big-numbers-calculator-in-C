#include "dynamic_input.h"
#include "dynamic_memory.h"
#include <stddef.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

//Get user input as string and handle automatically allocating memory to the arr
char* get_user_input_str(){
  char input_character = ' ';
  size_t current_limit = 50;
  size_t char_i = 0;
  bool is_newline = false;
  char* str = malloc(current_limit);

  while (is_newline == false){
    //Check if next char isnt outside of limit
    if (char_i >= current_limit - 1){
      str = resize_str_arr(str, &current_limit);
    }

    input_character = getchar();
    if (input_character == '\n'){
      is_newline = true;
      break;
    }
    str[char_i] = input_character;
    char_i++;
  }
  //Adding null terminator to end
  str[char_i] = '\0';
  return str;
}

//Flush old terminal input
void flush_input(){
  while(getchar() != '\n');
}