#include "multiplication_logic.h"
#include "decimals_logic.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

//Multiply big numbers
char* multiply (char* raw_a, char* raw_b) {
  bool is_a_decimal = check_if_decimal_point_exists(raw_a);
  bool is_b_decimal = check_if_decimal_point_exists(raw_b);
  size_t raw_a_decimal_point_i = 0;
  size_t raw_b_decimal_point_i = 0;
  size_t total_decimal_count = 0;

  //Call these functions for decimal numbers
  if (is_a_decimal == true){
    raw_a_decimal_point_i = find_decimal_point_i(raw_a);
    total_decimal_count += count_decimals(raw_a, raw_a_decimal_point_i);
    raw_a = remove_decimal_point(raw_a, raw_a_decimal_point_i);
  }
  if (is_b_decimal == true){
    raw_b_decimal_point_i = find_decimal_point_i(raw_b);
    total_decimal_count += count_decimals(raw_b, raw_b_decimal_point_i);
    raw_b = remove_decimal_point(raw_b, raw_b_decimal_point_i);
  }

  char* a = filter_str_zeros(raw_a);
  char* b = filter_str_zeros(raw_b);
  //Calculate length of result ahead of time, add reserve indexes for decimal point and null terminator
  int result_len = strlen(a) + strlen(b) + total_decimal_count + 1;
  char* result = calloc(result_len, sizeof(char));
  zero_str_arr(result, result_len);
  
  int i_shift = 0;
  int b_len = strlen(b);
  int partial_result_first_i;
  int full_result_first_i;
  
  for (int a_i = strlen(a) - 1; a_i >= 0; a_i--){
    int carry = 0;
    int digit_a = a[a_i] - '0';
    //Multiply every digit and write it in result
    for (int b_i = b_len - 1; b_i >= 0; b_i--){
      int digit_b = b[b_i] - '0';
      int current_product_value = digit_a * digit_b + carry;
      int current_product_i = result_len - 1 - (b_len - 1 - b_i);
      int previous_product_value = result[current_product_i - i_shift] - '0';
      result[current_product_i - i_shift] = (previous_product_value + current_product_value) % 10 + '0';
      carry = (previous_product_value + current_product_value) / 10;

      //Get first index of partial result
      if (b_i == 0){
        partial_result_first_i = current_product_i - i_shift;
      }
    }
    //Put carry in front of number
    full_result_first_i = partial_result_first_i - 1;
    while (carry > 0){
      int previous_digit = result[full_result_first_i] - '0';
      carry += previous_digit;
      result[full_result_first_i] = carry % 10 + '0';
      carry /= 10;
      full_result_first_i--;
      }
    //Correct full_result_first_i after adding carry
    full_result_first_i++;
    
    i_shift++;
    }
  free(a);
  free(b);
  clear_zeroes_from_front(result, result_len, full_result_first_i);
  if (total_decimal_count > 0){
    insert_decimal_point(result, total_decimal_count);
  }
  

  return result;
  }

//Remove zeros from front of string
void clear_zeroes_from_front(char* str, int full_str_len, int full_result_first_i){
  int first_non_zero_i = 0;
  while (first_non_zero_i < full_str_len && str[first_non_zero_i] == '0'){
    first_non_zero_i++;
  }
  //Result is 0
  if (first_non_zero_i == full_str_len){
    str[0] = '0';
    str[1] = '\0';
    return;
  }
  
  for (int i = full_result_first_i; i < full_str_len; i++){
    str[i - first_non_zero_i] = str[i];
  }
  //Adding null terminator after whole result
  int full_result_last_i = full_str_len - full_result_first_i;
  str[full_result_last_i] = '\0';
}

//Fill arr with zeros
void zero_str_arr(char* str, int str_len){
  for (int i = 0; i < str_len; i++){
    str[i] = '0';
  } 
}

//Return string without leading zeros
char* filter_str_zeros(const char* raw_str){
  int raw_str_len = strlen(raw_str);
  int first_non_zero_i = 0;
  while (first_non_zero_i < raw_str_len && raw_str[first_non_zero_i] == '0'){
    first_non_zero_i++;
  }
  //Filtered string is 0
  if (first_non_zero_i == raw_str_len){
    char* filtered_str = malloc(2 * sizeof(char)); 
    filtered_str[0] = '0';
    filtered_str[1] = '\0';
    return filtered_str;
  }
  //Making copy without lead zeros
  int filtered_str_len = raw_str_len - first_non_zero_i;
  char* filtered_str = malloc((filtered_str_len + 1) * sizeof(char));
  for (int i = 0; i < filtered_str_len; i++){
    filtered_str[i] = raw_str[i + first_non_zero_i];
  }
  filtered_str[filtered_str_len] = '\0';
  return filtered_str;
}