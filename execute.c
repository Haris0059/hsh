#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include "hsh.h"

void execute_command(char** argv) {
    if (argv[0] == NULL) {
        return;
    }   

    if (strcmp(argv[0], "exit") == 0)  { hsh_exit(argv);  return; }
    if (strcmp(argv[0], "pwd") == 0)   { hsh_pwd(argv);   return; }
    if (strcmp(argv[0], "cd") == 0)    { hsh_cd(argv);    return; }
    if (strcmp(argv[0], "echo") == 0)  { hsh_echo(argv);  return; }
    if (strcmp(argv[0], "cat") == 0)   { hsh_cat(argv);   return; }
    if (strcmp(argv[0], "touch") == 0) { hsh_touch(argv); return; }

    pid_t pid = fork();

    if (pid == 0) {
        execvp(argv[0], argv);
        fprintf(stderr, "hsh: command not found: %s\n", argv[0]);
        _exit(1);
    } else if (pid > 0) {
        waitpid(pid, NULL, 0);
    } else {
        perror("fork");
    }
}