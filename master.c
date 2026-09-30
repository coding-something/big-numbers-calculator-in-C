#include <stdbool.h>
#include "custom_libs/mode_logic.h"

int main(){
    bool exit_program = false;
    char current_mode;

    //Primary loop
    while (exit_program == false){
        current_mode = get_mode();
        switch_mode(current_mode);
        exit_program = check_for_user_exit(false);
    }
    return 0;
}
