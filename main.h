#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

#include <sys/types.h>
#include <sys/wait.h>

char *read_input(ssize_t *input_len);
int exe_input(char **argv, char **env);
char **parser(char *buffer, int *num_token);
void free_grid(char **grid, int num);
char *_strcpy(char *dest, char *src);
unsigned int _strlen(char *str);
char *_strdup(char *str);


#endif
