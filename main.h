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
#include <errno.h>
#include <sys/stat.h>
#include <fcntl.h>
extern int errno;

typedef void (*sighandler_t)(int);
static char *my_argv[100], *my_envp[100];
static char *search_path[10];

void insert_path_str_to_search(char *path_str);
void fill_argv(char *tmp_argv);

#endif
