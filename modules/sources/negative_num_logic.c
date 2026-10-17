#include "../headers/negative_num_logic.h"

bool check_for_minus_sign(char* num){
    return num[0] == '-';
}


void remove_minus_sign(char* num, size_t len){
    for (size_t i = 1; i <= len; i++){
        num[i - 1] = num[i];
    }
}


void add_minus_sign(char* num, size_t len){
    for (size_t i = len; i > 0; i--){
        num[i + 1] = num[i];
    }
    //Manually shift first char
    num[1] = num[0];
    num[0] = '-';
}