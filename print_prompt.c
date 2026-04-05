#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

void print_prompt() {
    char hostname[256];
    char* username = getenv("USER");

    gethostname(hostname, sizeof(hostname));
    
    printf("%s@%s:~$ ", username, hostname);
    fflush(stdout);
}