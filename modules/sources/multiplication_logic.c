#include "../headers/multiplication_logic.h"
#include "../headers/decimals_logic.h"
#include "../headers/negative_num_logic.h"
#include "../struct_headers/number_struct.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

//Multiply big numbers
char* multiply(char* raw_a, char* raw_b){
  struct number a = {
    .raw_value = raw_a,
    .value = NULL,
    .is_decimal = check_if_decimal_point_exists(raw_a),
    .is_negative = check_for_minus_sign(raw_a),
    .raw_value_decimal_point = 0
  };

  struct number b = {
    .raw_value = raw_b,
    .value = NULL,
    .is_decimal = check_if_decimal_point_exists(raw_b),
    .is_negative = check_for_minus_sign(raw_b),
    .raw_value_decimal_point = 0
  };

  size_t total_decimal_count = 0;
  size_t minus_sign_offset = 0;

  //Handle decimals
  if (a.is_decimal){
    a.raw_value_decimal_point = find_decimal_point_i(a.raw_value);
    total_decimal_count += count_decimals(a.raw_value, a.raw_value_decimal_point);
    remove_decimal_point(a.raw_value, a.raw_value_decimal_point);
  }
  if (b.is_decimal){
    b.raw_value_decimal_point = find_decimal_point_i(b.raw_value);
    total_decimal_count += count_decimals(b.raw_value, b.raw_value_decimal_point);
    remove_decimal_point(b.raw_value, b.raw_value_decimal_point);
  }

  //Call functions to handle negative numbers
  if (a.is_negative){
    remove_minus_sign(a.raw_value, strlen(a.raw_value));
    minus_sign_offset = 1;
  }
  if (b.is_negative){
    remove_minus_sign(b.raw_value, strlen(b.raw_value));
    minus_sign_offset = 1;
  }

  a.value = filter_str_zeros(a.raw_value);
  b.value = filter_str_zeros(b.raw_value);
  //Calculate length of result ahead of time, add reserve indexes for decimal point, minus sign and null terminator
  int result_len = strlen(a.value) + strlen(b.value) + total_decimal_count + minus_sign_offset + 1;

  struct number result = {
    .raw_value = malloc(result_len),
    .value = NULL,
    .is_decimal = check_if_decimal_point_exists(raw_b),
    .is_negative = check_for_minus_sign(raw_b),
    .raw_value_decimal_point = 0
  };

  populate_str_with_zeros(result.raw_value, result_len);
  
  int i_shift = 0;
  int b_len = strlen(b.value);
  int partial_result_first_i;
  int full_result_first_i;
  
  for (int a_i = strlen(a.value) - 1; a_i >= 0; a_i--){
    int carry = 0;
    int digit_a = a.value[a_i] - '0';
    //Multiply every digit and write it in result
    for (int b_i = b_len - 1; b_i >= 0; b_i--){
      int digit_b = b.value[b_i] - '0';
      int current_product_value = digit_a * digit_b + carry;
      int current_product_i = result_len - 1 - (b_len - 1 - b_i);
      int previous_product_value = result.raw_value[current_product_i - i_shift] - '0';
      result.raw_value[current_product_i - i_shift] = (previous_product_value + current_product_value) % 10 + '0';
      carry = (previous_product_value + current_product_value) / 10;

      //Get first index of partial result
      if (b_i == 0){
        partial_result_first_i = current_product_i - i_shift;
      }
    }
    //Put carry in front of number
    full_result_first_i = partial_result_first_i - 1;
    while (carry > 0){
      int previous_digit = result.raw_value[full_result_first_i] - '0';
      carry += previous_digit;
      result.raw_value[full_result_first_i] = carry % 10 + '0';
      carry /= 10;
      full_result_first_i--;
      }
    //Correct full_result_first_i after adding carry
    full_result_first_i++;
    
    i_shift++;
    }
  free(a.value);
  free(b.value);
  //Pass pointer to another variable in the struct and free to prevent memory leak
  result.value = filter_str_zeros(result.raw_value);
  free(result.raw_value);

  if (total_decimal_count > 0){
    insert_decimal_point(result.value, total_decimal_count);
  }

  //Check for minus in result
  if (a.is_negative != b.is_negative){
    add_minus_sign(result.value, result_len);
  }
  
  return result.value;
  }

//Fill string arr with zero chars, add null terminator
void populate_str_with_zeros(char* str, int str_len){
  for (int i = 0; i < str_len; i++){
    str[i] = '0';
  }
  str[str_len] = '\0';
}

//Return same newly allocated string without leading zeros
char* filter_str_zeros(const char* raw_str){
  int raw_str_len = strlen(raw_str);
  int first_non_zero_i = 0;
  while (first_non_zero_i < raw_str_len && raw_str[first_non_zero_i] == '0'){
    first_non_zero_i++;
  }
  //Filtered string is zero
  if (first_non_zero_i == raw_str_len){
    char* filtered_str = malloc(2); 
    filtered_str[0] = '0';
    filtered_str[1] = '\0';
    return filtered_str;
  }
  //Making copy without lead zeros
  int filtered_str_len = raw_str_len - first_non_zero_i;
  char* filtered_str = malloc(filtered_str_len + 1);
  for (int i = 0; i < filtered_str_len; i++){
    filtered_str[i] = raw_str[i + first_non_zero_i];
  }
  filtered_str[filtered_str_len] = '\0';
  return filtered_str;
}
