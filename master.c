#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

char* multiply (char* raw_a, char* raw_b);
void clear_zeroes_from_front(char* str, int full_str_len, int full_result_first_i);
void zero_str_arr(char* str, int str_len);
char* filter_str_zeros(const char* raw_str);

char* get_user_input_str();
char* resize_str_arr(char* original_str, size_t* current_limit);
bool check_allocated_memory_of_str(char* str);

void flush_input();


int main(){
    char* num1;
    char* num2;
    char* result;
    char user_input;
    bool exit_program = false;

    while (exit_program == false){
        printf("First number: ");
        num1 = get_user_input_str();
        printf("Second number: ");
        num2 = get_user_input_str();
        result = multiply(num1, num2);
        free(num1);
        free(num2);
        printf("Result of multiplication is: %s \n", result);
        free(result);

        printf("Exit? [Y/N]: ");
        scanf(" %c", &user_input);
        if (user_input == 'Y' || user_input == 'y'){
            exit_program = true;
        }
        flush_input();
    }
    return 0;
}

//Multiply big numbers
char* multiply (char* raw_a, char* raw_b) {
  char* a = filter_str_zeros(raw_a);
  char* b = filter_str_zeros(raw_b);
  
  //Calculate length of result ahead of time
  int result_len = strlen(a) + strlen(b) + 1;
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
  clear_zeroes_from_front(result, result_len, full_result_first_i);
  free(a);
  free(b);
  return result;
  }

//Remove zeroes from front of string
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

//Get user input and handle automatically allocating memory to the arr
char* get_user_input_str(){
  char input_character = ' ';
  size_t current_limit = 50;
  size_t char_i = 0;
  bool is_newline = false;
  char* str = malloc(current_limit);

  while (is_newline == false){
    //Check if arr is big enough for next char
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

//Checks if memory has been successfully allocated or not
bool check_allocated_memory_of_str(char* str){
  if (str != NULL){
    return true;
  }
  printf("Error, memory allocation failed.");
  return false;
}

//Resize arr
char* resize_str_arr(char* original_str, size_t* current_limit){
  *current_limit *= 2;
  char* temp_str = realloc(original_str, *current_limit);
  if (check_allocated_memory_of_str(temp_str) == false){
    free(original_str);
  }
  return temp_str;
}

//Flush old terminal input
void flush_input(){
  while(getchar() != '\n');
}