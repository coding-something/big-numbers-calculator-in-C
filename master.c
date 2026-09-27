#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "custom_libs/dynamic_input.h"
#include "custom_libs/dynamic_memory.h"
#include "custom_libs/multiplication_logic.h"

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
