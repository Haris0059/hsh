#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void read_input(char* input) {
    if (fgets(input, 1024, stdin) == NULL) {
        // clean way to leave the shell like in bash
        printf("\n");
        exit(0);
    }

    input[strcspn(input, "\n")] = '\0';
}
