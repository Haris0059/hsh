#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include "hsh.h"

void execute_command(char** argv) {
    if (argv[0] == NULL) {
        return;
    }

    // scan for > and redirect stdout to the given file
    char* outfile = NULL;
    for (int i = 0; argv[i]; i++) {
        if (strcmp(argv[i], ">") == 0) {
            outfile = argv[i+1];
            argv[i] = NULL;
            break;
        }
    }

    int saved = -1;
    if (outfile) {
        int fd = open(outfile, O_WRONLY | O_CREAT | O_TRUNC, 0644);
        if (fd < 0) { perror(outfile); return; }
        saved = dup(STDOUT_FILENO);
        dup2(fd, STDOUT_FILENO);
        close(fd);
    }

    if      (strcmp(argv[0], "exit") == 0)  hsh_exit(argv);
    else if (strcmp(argv[0], "pwd") == 0)   hsh_pwd(argv);
    else if (strcmp(argv[0], "cd") == 0)    hsh_cd(argv);
    else if (strcmp(argv[0], "echo") == 0)  hsh_echo(argv);
    else if (strcmp(argv[0], "cat") == 0)   hsh_cat(argv);
    else if (strcmp(argv[0], "touch") == 0) hsh_touch(argv);
    else {
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

    fflush(stdout);
    if (saved != -1) {
        dup2(saved, STDOUT_FILENO);
        close(saved);
    }
}
