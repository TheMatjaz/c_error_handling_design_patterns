#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int parsed_value;

    parsed_value = strtol("0", NULL, 10);
    printf("Parsed value of '0' is %d\n", parsed_value);

    parsed_value = strtol("12", NULL, 10);
    printf("Parsed value of '12' is %d\n", parsed_value);

    parsed_value = strtol("fdjkfnskxg", NULL, 10);
    printf("Parsed value of 'fdjkfnskxg' is %d\n", parsed_value);

    char* string = "    12  ";
    char* after_parsed_number;

    parsed_value = strtol(string, &after_parsed_number, 10);
    printf("Parsed value of '%s' is %d\n", string, parsed_value);
    printf("Parsed %ld characters\n", after_parsed_number - string);

    string = "   0";
    parsed_value = strtol(string, &after_parsed_number, 10);
    printf("Parsed value of '%s' is %d\n", string, parsed_value);
    printf("Parsed %ld characters\n", after_parsed_number - string);

    string = "fdjkfnskxg";
    parsed_value = strtol(string, &after_parsed_number, 10);
    printf("Parsed value of '%s' is %d\n", string, parsed_value);
    printf("Parsed %ld characters\n", after_parsed_number - string);
}
