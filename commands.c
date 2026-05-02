#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>
#include "hsh.h"

void hsh_echo(char** argv) {
    int i = 1;
    int newline = 1;
    int escapes = 0;

    if (argv[i] && strcmp(argv[i], "-n") == 0) { newline = 0; i++; }
    if (argv[i] && strcmp(argv[i], "-e") == 0) { escapes = 1; i++; }

    for (; argv[i]; i++) {
        if (escapes) {
            for (char* p = argv[i]; *p; p++) {
                if (*p == '\\' && *(p+1) == 'n') { putchar('\n'); p++; }
                else if (*p == '\\' && *(p+1) == 't') { putchar('\t'); p++; }
                else putchar(*p);
            }
        } else printf("%s", argv[i]);
        if (argv[i+1]) putchar(' ');
    }
    if (newline) putchar('\n');
}

void hsh_cat(char** argv) {
    char buf[1024];
    ssize_t n;

    if (argv[1] == NULL) {
        while ((n = read(STDIN_FILENO, buf, sizeof(buf))) > 0)
            write(STDOUT_FILENO, buf, n);
        return;
    }

    for (int i = 1; argv[i]; i++) {
        int fd = open(argv[i], O_RDONLY);
        if (fd < 0) { perror(argv[i]); continue; }
        while ((n = read(fd, buf, sizeof(buf))) > 0)
            write(STDOUT_FILENO, buf, n);
        close(fd);
    }
}

void hsh_touch(char** argv) {
    if (argv[1] == NULL) {
        fprintf(stderr, "touch: missing file operand\n");
        return;
    }

    for (int i = 1; argv[i] != NULL; i++) {
        int fd = open(argv[i], O_WRONLY | O_CREAT, 0644);
        if (fd < 0) {
            perror(argv[i]);
            continue;
        }
        close(fd);

        if (utimensat(AT_FDCWD, argv[i], NULL, 0) != 0) {
            perror(argv[i]);
        }
    }
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
