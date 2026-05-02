#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void print_prompt() {
    char hostname[256];
    char cwd[1024];
    char* username = getenv("USER");
    char* home = getenv("HOME");

    gethostname(hostname, sizeof(hostname));
    getcwd(cwd, sizeof(cwd));

    if (home && strncmp(cwd, home, strlen(home)) == 0) {
        printf("%s@%s:~%s$ ", hostname, username, cwd + strlen(home));
    } else {
        printf("%s@%s:%s$ ", hostname, username, cwd);
    }
    fflush(stdout);
}
