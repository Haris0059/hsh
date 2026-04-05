#include <stdio.h>
#include <string.h>

void read_input(char* input) {
    fgets(input, 1024, stdin);

    input[strcspn(input, "\n")] = '\0';
}