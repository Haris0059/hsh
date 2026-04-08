#include "hsh.h"

int main() {
    char input[1024];
    char* argv[64];

    while(1) {
        print_prompt();
        read_input(input);
        parse_input(input, argv);
        execute_command(argv);
    }
}