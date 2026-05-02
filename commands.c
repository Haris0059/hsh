#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "hsh.h"

void hsh_echo(char** argv) {
}

void hsh_cat(char** argv) {
}

void hsh_touch(char** argv) {
}

void hsh_cd(char** argv) {
    const char* path = argv[1] ? argv[1] : getenv("HOME");
    if (chdir(path) != 0) perror("cd");
}

void hsh_pwd(char** argv) {
    char cwd[1024];
    if (getcwd(cwd,sizeof(cwd)) != NULL) printf("%s\n", cwd);
    else perror("pwd");
}

void hsh_exit(char** argv) {
    exit(0);
}
