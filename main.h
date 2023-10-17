#ifndef _MAIN_H
#define _MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <ctype.h>

extern char **environ;

/* main functions  */

char *read_line(void);

char **spilt_line(char *new_line);

int exec(char **args, char *line, int ind, char **name);

size_t _getline(char **lineptr, size_t *m, FILE *stream);

void comment(char *line);

char *_strtok(char *str, char *del);

char *handle_path(char *command, char *path);

char *_getpath(char *command, char *path);

char *get_full_path(char *command, char *path);

int check_built(char *command);

void handle_built(char **args, int status, char *command, int ind, char **argv);

char *_getenv(char *viron);

/*  strings  */

int _strlen(char *str);

char *_strcat(char *dest, char *src);

char *_strcpy(char *dest, char *src);

int _strcmp(char *s1, char *s2);

char *_strchr(char *s, char c);

char *_strdup(char *str);

int _strncmp(const char *str1, const char *str2, size_t num);

/* helper  */

int _isspace(char c);

int is_empty(const char *str);

int _atoi_(char *str);

void _free(char *f1, char **f2);
/* write  */

int _putchar(char c);

void _puts(char *str);

/* test */

void print_error(char *name, char *command, int ind);

char *_itoa(int n);

void rev_str(char *str, int len);
#endif

