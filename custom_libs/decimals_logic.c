#include "decimals_logic.h"
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

char* remove_decimal_point(char* num, size_t d_i){
    for (size_t i = d_i; num[i] != '\0'; i++){
        num[i] = num[i + 1];
    }
    return num;
}

char* pre_fill_decimal_with_zeroes(char* num, size_t zero_count){
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
    return num;
}

char* insert_decimal_point(char* num, size_t decimal_count){
    //Check if decimal point exists
    if (decimal_count == 0){
        return num;
    }
    size_t result_len = strlen(num);
    size_t i = result_len;
    //Pre fill with zeroes if input number length is lower than decimal count, which would cause i to be negative later on
    if(i < decimal_count){
        num = pre_fill_decimal_with_zeroes(num, decimal_count);
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

    return num;
}
