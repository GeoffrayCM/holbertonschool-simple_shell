#ifndef SHELL_H_
#define SHELL_H_
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <signal.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
int _putchar(char c);
void _puts(char *str);
int _strcmp(char *s1, char *s2);
char *_strndup(char *str, int n);
int _strlen(char *str);
char *_strcat(char *dest, char *src);
char **strtow(char *str);
void free_cmd(char **str);
#endif
