#include "mode_logic.h"
#include "dynamic_input.h"
#include "multiplication_logic.h"
#include "factorial_logic.h"

char get_mode(){
    char mode;
    printf("Choose calculator mode: M - Multiply, F - Factorial.\n");
    printf("Chosen mode: ");
    mode = getchar();
    flush_input();
    return mode;
}

void switch_mode(char current_mode){
    switch(current_mode){
        case 'M':
            trigger_multiplication_mode();
            break;

        case 'F':
            trigger_factorial_mode();
            break;
            
        default:
            printf("Invalid mode, try again.\n");
            break;
    }
}

void trigger_multiplication_mode(){
    char* num1;
    char* num2;
    char* result;
    char user_input;
    bool exit_mode = false;

    while (exit_mode == false){
        printf("First number: ");
        num1 = get_user_input_str();
        printf("Second number: ");
        num2 = get_user_input_str();
        result = multiply(num1, num2);
        free(num1);
        free(num2);
        printf("Result of multiplication is: %s \n", result);
        free(result);

        exit_mode = check_for_user_exit(true);
    }
}

void trigger_factorial_mode(){
    int num;
    char* result;
    char user_input;
    bool exit_mode = false;

    while (exit_mode == false){
        printf("Factorial of: ");
        scanf("%d", &num);
        result = calculate_factorial(num);
        printf("Result is %s \n", result);
        free(result);

        exit_mode = check_for_user_exit(true);
    }
}

bool check_for_user_exit(bool is_mode){
    char user_input;

    (is_mode == true) ? printf("Exit mode? [Y/N]: "): printf("Exit program? [Y/N]: ");
    scanf(" %c", &user_input);
    if (user_input == 'Y' || user_input == 'y'){
        return true;
    }
    flush_input();
    return false;
}