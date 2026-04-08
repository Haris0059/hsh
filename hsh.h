#ifndef HSH_H
#define HSH_H

void print_prompt();
void read_input(char* input);
void parse_input(char* input, char** argv);
void execute_command(char** argv);

#endif