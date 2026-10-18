#ifndef NUMBER_STRUCT
#define NUMBER_STRUCT
#include <stdlib.h>
#include <stdbool.h>

struct number{
    char* raw_value;
    char* value;
    bool is_decimal;
    bool is_negative;
    size_t raw_value_decimal_point;
};

#endif