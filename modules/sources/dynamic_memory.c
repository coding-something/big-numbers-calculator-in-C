#include "../headers/dynamic_memory.h"
#include <stdlib.h>
#include <stdio.h>

//Check if memory has been successfully allocated or not
bool check_allocated_memory_of_str(char* str){
  return (str != NULL) ? true : false;
}

//Resize arr to double its original limit
char* resize_str_arr(char* original_str, size_t* current_limit){
  *current_limit *= 2;
  char* temp_str = realloc(original_str, *current_limit);
  if (check_allocated_memory_of_str(temp_str) == false){
    printf("Memory allocation failure in resize_str_arr function. Exiting program.");
    exit(1);
  }
  return temp_str;
}
