#ifndef _MAIN_H_
#define _MAIN_H_

/*Common Hearder files*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>

/*Micro variable*/
#define DELIM " \r\t\b\n"
#define COMMAND_SIZE 100

/*Global variables*/
extern char **environ;

/*Functions prototypes*/
void tokenization(char *input, const char *tokens_array[]);
void exec(const char **cmd, char **argv);
char *_path(const char *cmd);
char *_getenv(const char *var_name);
int builtin_cmd(char **array);
void exit_shell(char **array);
void _env(void);
int mysetenv(int argc, char **argv);
int myunsetenv(int argc, char **argv);

#endif
