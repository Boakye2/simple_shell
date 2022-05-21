#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <ctype.h>
#include <sys/stat.h>
#include <fcntl.h>
extern int errno;

typedef void (*sighandler_t)(int);
static char *my_argv[100], *my_envp[100];
static char *search_path[10];

void handle_signal(int signo);
void fill_argv(char *tmp_argv);
void copy_envp(char **envp);
void get_path_string(char **tmp_envp, char *bin_path);
void insert_path_str_to_search(char *path_str);
int attach_path(char *cmd);
void call_execve(char *cmd);
void free_argv(void);
int print_all(int a, char c, char *argv[], char *ptr[], char *tmp, char *cmd)


#endif
