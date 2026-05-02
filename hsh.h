#ifndef HSH_H
#define HSH_H

void print_prompt();
void read_input(char* input);
void parse_input(char* input, char** argv);
void execute_command(char** argv);

void hsh_echo(char** argv);
void hsh_cat(char** argv);
void hsh_touch(char** argv);
void hsh_cd(char** argv);
void hsh_pwd(char** argv);
void hsh_exit(char** argv);

#endif