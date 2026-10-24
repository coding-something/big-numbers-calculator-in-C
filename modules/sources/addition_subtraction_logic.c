#include "../headers/addition_subtraction_logic.h"
#include "../headers/decimals_logic.h"
#include "../headers/negative_num_logic.h"
#include "../headers/multiplication_logic.h"
#include "../headers/dynamic_memory.h"
#include "../struct_headers/number_struct.h"
#include "stdbool.h"
#include "string.h"

char* add_or_subtract(char* num1, char* num2){
    struct number a = {
        .raw_value = num1,
        .value = NULL,
        .is_decimal = check_if_decimal_point_exists(num1),
        .is_negative = check_for_minus_sign(num1),
        .raw_value_decimal_point = 0,

    };

    struct number b = {
        .raw_value = num2,
        .value = NULL,
        .is_decimal = check_if_decimal_point_exists(num2),
        .is_negative = check_for_minus_sign(num2),
        .raw_value_decimal_point = 0,

    };

    struct number result = {
        .raw_value = NULL,
        .value = NULL,
        .is_decimal = a.is_decimal + b.is_decimal,
        .is_negative = false,
        .raw_value_decimal_point = 0,

    };
    
    int result_possible_size_offset = 1;
    int result_decimal_point_offset = (result.is_decimal) ? 1 : 0;
    int result_minus_sign_offset = 0;
    int result_len_total_offset = 0;
    size_t result_len;
    //UNUSED AS OF NOW
    int equalized_decimal_point_i;

    //Handle negative numbers
    if (a.is_negative){
        remove_minus_sign(a.raw_value, strlen(a.raw_value));
    }
    if (b.is_negative){
        remove_minus_sign(b.raw_value, strlen(b.raw_value));
    }
    //Handle decimal points
    if (a.is_decimal){
        a.raw_value_decimal_point = find_decimal_point_i(a.raw_value);
        remove_decimal_point(a.raw_value, a.raw_value_decimal_point);
    }
    if (b.is_decimal){
        b.raw_value_decimal_point = find_decimal_point_i(b.raw_value);
        remove_decimal_point(b.raw_value, b.raw_value_decimal_point);
    }

    //Make both number strings of same size
    a.raw_value = get_equal_size_num(a.raw_value, b.raw_value);
    b.raw_value = get_equal_size_num(b.raw_value, a.raw_value);

    //Result handling and allocation of memory for string
    result.is_negative = check_for_negative_addition_result(a.raw_value, b.raw_value, a.is_negative, b.is_negative);
    result_minus_sign_offset = (result.is_negative) ? 1 : 0;
    result_len_total_offset =  result_decimal_point_offset + result_minus_sign_offset + result_possible_size_offset;
    result_len = strlen(a.raw_value) + result_len_total_offset;
    result.raw_value = malloc(result_len + 1); //1 is for null terminator
    populate_str_with_zeros(result.raw_value, result_len);

    //Main loop for addition
    int digit_a;
    int digit_b;
    int digit_result;
    int carry = 0;
    
    for (int i = strlen(a.raw_value) - 1; i >= 0; i--){
        digit_a = a.raw_value[i] - '0';
        digit_b = b.raw_value[i] - '0';
        digit_result = digit_a + digit_b + carry; //carry can be only 1 or 0, thus digit_result can max be 19
        carry = digit_result / 10;
        result.raw_value[i + result_len_total_offset] = digit_result % 10 + '0';
    }

    result.raw_value[result_len_total_offset - 1] = carry + '0';

    return result.raw_value;
}

bool check_for_negative_addition_result(char* stripped_a, char* stripped_b, bool is_a_negative, bool is_b_negative){
    size_t a_len = strlen(stripped_a);
    size_t b_len = strlen(stripped_b);
    char* larger_num = NULL;

    //Find larger number using len(amount of digits) if lengths are not same
    larger_num = (a_len > b_len) ? stripped_a : stripped_b;

    //Find larger number using first different digit if lengths of numbers are the same
    if (a_len == b_len){
        for (size_t i = 0; i < a_len; i++){
            if (stripped_a[i] != stripped_b[i]){
                larger_num = (stripped_a[i] > stripped_b[i]) ? stripped_a: stripped_b;
                break;
            }
        }
    }

    if (stripped_a == larger_num && is_a_negative){
        return true;
    }

    if (stripped_b == larger_num && is_b_negative){
        return true;
    }

    return false;
}

//Used to equalize length of strings, handles moving number to the proper position in string automatically
char* get_equal_size_num(char* num_to_resize, char* other_num){
    char* larger_num = (strlen(num_to_resize) < strlen(other_num)) ? other_num : num_to_resize;

    //Number does not need resizing
    if (larger_num == num_to_resize){
        return num_to_resize;
    }
    size_t smaller_number_original_len = strlen(num_to_resize);
    size_t len_difference = strlen(larger_num) - smaller_number_original_len;
    size_t smaller_number_current_size = smaller_number_original_len + 1;

    //Reallocating the original number string
    char* resized_num = resize_str_arr(num_to_resize, &smaller_number_current_size, len_difference);

    //Move number to proper position in reallocated string
    for (size_t i = smaller_number_original_len; i > 0; i--){
        resized_num[i + len_difference] = resized_num[i];
    }
    //Move final char
    resized_num[len_difference] = resized_num[0];


    //Fill rest of string with 0 chars;
    for (size_t i = 0; i < smaller_number_current_size - 1 - smaller_number_original_len; i++){
        resized_num[i] = '0';
    }
    return resized_num;
}
