#include <stdio.h>
#include <errno.h>   // To access the integer `errno`
#include <string.h>  // To convert `errno` to a human-readable string with strerror

int main() {
    printf("At startup: value=%d, string=%s\n", errno, strerror(errno));
    FILE *file = fopen("NON_existing_file.txt", "r");
    if (file == NULL) {
        printf("After fopen fails: value=%d, string=%s\n", errno, strerror(errno));
    } else {
        fclose(file);
    }
    return 0;
}
