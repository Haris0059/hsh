#include <string.h>

void parse_input(char* input, char** argv) {
    int i = 0;

    argv[i] = strtok(input, " ");

    while(argv[i] != NULL) {
        i++;
        argv[i] = strtok(NULL, " ");
    }
}