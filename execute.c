#include <stdio.h>
#include <unistd.h> 
#include <sys/wait.h>

void execute_command(char** argv) {
    if (argv[0] == NULL) {
        return;
    }   

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