#ifndef MAIN_H
#define MAIN_H

#define VOIDED(x) (void)(x)

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <dirent.h>
#include <sys/wait.h>

extern char **environ;

char **strtow(char *str, char sep);
int _strcmp(char *s1, char *s2);
char *get_PATH_info(char **env);
char *access_Check(char *pathValue, char **f);
char *str_concat(char *s1, char *s2);
int _run(char *path, char **args, char **env);
int _strlen(char *s);
void psign(void);
void free_grid(char **grid, int height);
int cgrid(char **grid);
void _print_env(char **env);

#endif
