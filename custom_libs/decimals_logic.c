#include "decimals_logic.h"
#include <string.h>

size_t find_decimal_point_i(char* num){
    size_t i = 0;
    while (num[i] != '.' && num[i] != '\0'){
        i++;
    }

    //Check if decimal point exists
    if (num[i] != '.'){
        return 0;
    }
    return i;
}

int count_decimals(char* num, size_t d_i){
    int amount_of_decimals = 0;
    //Decimal point does not exist, return 0
    if (d_i == 0){
        return amount_of_decimals;
    }

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

char* insert_decimal_point(char* num, int decimal_count){
    //Checks if decimal point exists
    if (decimal_count == 0){
        return num;
    }

    size_t result_len = strlen(num);
    size_t i = result_len;
    //Shift every number after the decimal point
    while (i > result_len - 1 - decimal_count){
        num[i + 1] = num[i];
        i--;
    }
    //Offset 1 so the decimal point is placed in the spot for it, instead of rewriting the number before it
    num[i + 1] = '.';
    
    return num;
}