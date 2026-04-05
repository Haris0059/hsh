#include "prompt.c"
#include "input.c"

int main() {
    char input[1024];

    while(1) {
        print_prompt();
        read_input(input);
    }
}