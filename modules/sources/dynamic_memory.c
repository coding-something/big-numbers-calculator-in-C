#include "../headers/dynamic_memory.h"
#include <stdlib.h>
#include <stdio.h>

//Check if memory has been successfully allocated or not
bool check_allocated_memory_of_str(char* str){
  return (str != NULL) ? true : false;
}

//Resize arr to new limit by adding custom_resize_value on top of current limit, otherwise use default value and double it
char* resize_str_arr(char* original_str, size_t* current_limit, size_t custom_resize_value){
  //Handle optional input custom_resize_value
  if (custom_resize_value > 0){
    *current_limit += custom_resize_value;
  }
  else{
    *current_limit *= 2;
  }
  char* temp_str = realloc(original_str, *current_limit);
  if (check_allocated_memory_of_str(temp_str) == false){
    printf("Memory allocation failure in resize_str_arr function. Exiting program.");
    exit(1);
  }
  return temp_str;
}
