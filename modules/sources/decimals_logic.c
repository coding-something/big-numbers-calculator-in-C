#include "../headers/decimals_logic.h"
#include "../headers/dynamic_memory.h"
#include <string.h>
#include <stdio.h>


bool check_if_decimal_point_exists(char* num){
    size_t i = 0;
    while (num[i] != '.' && num[i] != '\0'){
        i++;
    }

    //Check if decimal point exists
    if (num[i] == '.'){
        return true;
    }
    return false;
}

size_t find_decimal_point_i(char* num){
    size_t i = 0;
    while (num[i] != '.' && num[i] != '\0'){
        i++;
    }
    return i;
}

size_t count_decimals(char* num, size_t d_i){
    size_t amount_of_decimals = 0;
    //Correct for index and start from first number after decimal point
    d_i++;
    while (num[d_i] != '\0'){
        amount_of_decimals++;
        d_i++;
    }

    return amount_of_decimals;
}

void remove_decimal_point(char* num, size_t d_i){
    for (size_t i = d_i; num[i] != '\0'; i++){
        num[i] = num[i + 1];
    }
}

void pre_fill_decimal_with_zeroes(char* num, size_t zero_count){
    size_t i = strlen(num);
    //Shift arr before adding zeros
    while (i > 0){
        num[i + zero_count] = num[i]; 
        i--;
    }
    //Manually shift final number
    num[i + zero_count] = num[i];
    //Add zeroes
    while (zero_count != 0){
        num[i] = '0';
        i++;
        zero_count--;
    }
}

void insert_decimal_point(char* num, size_t decimal_count){
    //Check if decimal point exists
    if (decimal_count == 0){
        return;
    }
    size_t result_len = strlen(num);
    size_t i = result_len;
    //Pre fill with zeroes if input number length is lower than decimal count, which would cause i to be negative later on
    if(i < decimal_count){
        pre_fill_decimal_with_zeroes(num, decimal_count);
        result_len = strlen(num);
        i = result_len;
    }
    //Shift every number until the decimal point index is reached
    while (i != result_len - decimal_count){
        num[i + 1] = num[i];
        i--;
    }
    //Shift original number at decimal point index
    num[i + 1] = num[i];
    //Insert decimal point
    num[i] = '.';
}

void remove_decimal_trailing_zeros(char* num_str, size_t decimal_point_i){
    for (size_t i = strlen(num_str) - 1; i >= decimal_point_i; i--){
        //Add null terminator in front of trailing zeros
        if (num_str[i] != '0'){
            num_str[i + 1] = '\0';
            return;
        }
    }
}

char* get_equal_decimals_num(char* num_str, size_t decimal_point_i, size_t equalized_decimal_count){
    //Adding decimal point index to non decimal numbers.
    if (decimal_point_i == 0){
        decimal_point_i = strlen(num_str);
    }

    size_t last_decimal_i = decimal_point_i + equalized_decimal_count - 1; //Offset 1 because decimal point is stripped
    size_t num_len = strlen(num_str);
    size_t num_size = num_len + 1;
    bool passed_null_terminator = false;

    //Allocate additional memory for trailing zeros
    num_str = resize_str_arr(num_str, &num_size, equalized_decimal_count);
    size_t i = decimal_point_i;
    while (i <= last_decimal_i){
        //Finding first decimal index after already occupied decimal indexes.
        if (num_str[i] == '\0'){
            passed_null_terminator = true;
        }

        if (passed_null_terminator){
            num_str[i] = '0';
        }
        i++;
    }
    num_str[i] = '\0';

    return num_str;
}