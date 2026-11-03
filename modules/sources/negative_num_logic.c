#include "../headers/negative_num_logic.h"
bool check_for_minus_sign(char* num){
    return num[0] == '-';
}


void remove_sign(char* num, size_t len){
    for (size_t i = 1; i <= len; i++){
        num[i - 1] = num[i];
    }
}


void add_minus_sign(char* num, size_t len){
    bool non_zero_num_found = false;
    for (size_t i = 0; num[i] != '\0'; i++){
        if (num[i] != '0' && num[i] != '.'){
            non_zero_num_found = true;
        }
    }
    //Returning early in case where whole number is 0
    if (non_zero_num_found == false){
        return;
    }
    
    for (size_t i = len; i >= 0; i--){
        num[i + 1] = num[i];

        if (i == 0){
            num[i] = '-';
            break;
        }
    }
}