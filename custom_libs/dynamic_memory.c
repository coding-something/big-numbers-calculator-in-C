#include "dynamic_memory.h"
#include <stdlib.h>
#include <stdio.h>

//Check if memory has been successfully allocated or not
bool check_allocated_memory_of_str(char* str){
  if (str != NULL){
    return true;
  }
  printf("Error, memory allocation failed.");
  return false;
}

//Resize arr to double its original limit
char* resize_str_arr(char* original_str, size_t* current_limit){
  *current_limit *= 2;
  char* temp_str = realloc(original_str, *current_limit);
  if (check_allocated_memory_of_str(temp_str) == false){
    free(original_str);
  }
  return temp_str;
}
