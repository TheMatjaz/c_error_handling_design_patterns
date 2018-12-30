#include <stdio.h>
#include <setjmp.h>

static jmp_buf state;

typedef enum {
    OK = 0,
    NEGATIVE_VALUE = 1,
    TOO_BIG_VALUE = 2,
} error_code_t;

int twice4(int value) {
    if (value < 0) {
        printf("(!) Negative value: %d\n", value);
        longjmp(state, NEGATIVE_VALUE); // Restore state, set code
    } else if (value > 100) {
        printf("(!) Too big value: %d\n", value);
        longjmp(state, TOO_BIG_VALUE);  // Restore state, set code
    } else { return 2 * value; }
}

int twice3(int value) { return twice4(value); }
int twice2(int value) { return twice3(value); }
int twice(int value)  { return twice2(value); }

int main() {
    // Initially saves state and sets error_code to 0.
    // Jumped to using longjmp(state, new_value),
    // setting error_code to new_value.
    int error_code = setjmp(state);
    if (error_code == OK) {
        int input = 1000;  // -10 or 1000 jumps to else branch
        int result = twice(input);
        printf("Twice of %d is %d\n", input, result);
    } else {
        printf("Error code %d\n", error_code);
    }
    return 0;
}
