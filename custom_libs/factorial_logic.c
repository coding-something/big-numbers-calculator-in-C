#include "factorial_logic.h"
#include "dynamic_memory.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


char* calculate_factorial(int n){
  if (n < 0){
    char* str = malloc(1);
    str[0] = '\0';
    return str;
  }
  if (n == 0){
    char* str = malloc(2);
    str[0] = '1';
    str[1] = '\0';
    return str;
  }
  
  //Final factorial string
  size_t arr_size = 10;
  char* factorial_result = calloc(arr_size, sizeof(char));
  
  //Starting with 1 so it can work
  strcpy(factorial_result, "1");
  
  //Factorial loop for each multiplication
  for (int i = 2; i <= n; i++){
    factorial_result = multiply_factorial_str(factorial_result, i, &arr_size);
  }
  return factorial_result;
}

char* multiply_factorial_str(char* fact_str, int multiplier, size_t* arr_size){
  
  size_t len = strlen(fact_str);
  int carry = 0;
  
  //Multiplication of each digit
  for (int i = (int)len - 1; i >= 0; i--){
    int previous_digit = fact_str[i] - '0';
    int value = previous_digit * multiplier + carry;
    
    //Putting new digit into place of original one
    fact_str[i] = value % 10 + '0';
    carry = value / 10;
  }
  
  int carry_len = get_len_of_int(carry);
  if (carry_len + len >= *arr_size){
    fact_str = resize_str_arr(fact_str, arr_size);
  }
  //Adding null terminator in advance
  fact_str[len + carry_len] = '\0';

  //Adding carry value to the front by shifting the whole string
  if (carry > 0){
    for (int i = (int)len - 1; i >= 0; i--){
      fact_str[i + carry_len] = fact_str[i];
    }
    while (carry > 0){
      fact_str[carry_len - 1] = carry % 10 + '0';
      carry /= 10;
      carry_len--;
    }
  }
  return fact_str;
}

int get_len_of_int(int n){
  int len = 0;
  while (n > 0){
    len++;
    n /= 10;
  }
  return len;
}