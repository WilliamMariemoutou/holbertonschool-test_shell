#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>

extern char **environ;

int is_interactive_mode(void);
void print_prompt(void);
char *trim_newline(char *s);
void run_command(char *cmd, char *prog_name, unsigned long line_no);

#endif
