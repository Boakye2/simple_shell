#include "main.h"

/**
 * main - Display a prompt and wait for the user.
 * @argc: number of var.
 * @argv: input array pointer to char.
 * @ptr: input array pointer to char.
 *
 * Return: 0.
 */

int main(int argc, char *argv[], char *ptr[])
{
	char c;
	int i, fd;
	char *tmp = (char *)malloc(sizeof(char) * 100);
	char *path_str = (char *)malloc(sizeof(char) * 256);
	char *cmd = (char *)malloc(sizeof(char) * 100);

	signal(SIGINT, SIG_IGN);
	signal(SIGINT, handle_signal);

	copy_envp(ptr);
	get_path_string(my_envp, path_str);
	insert_path_str_to_search(path_str);
	argc = 0;
	if (fork() == 0)
	{
		exit(1);
	}
	else
	{
		wait(NULL);
	}
	printf("#cisfun$ ");
	fflush(stdout);
	while (c != EOF)
	{
		c = getchar();
		print_all(0, c, argv, ptr, tmp, cmd);
	}
	free(tmp);
	free(path_str);
	for (i = 0; my_envp[i] != NULL; i++)
		free(my_envp[i]);
	for (i = 0; i < 10; i++)
		free(search_path[i]);
	printf("\n");
	return (0);
}

/**
 * print_all - print value.
 * @a: int value initstate
 * @c: char variable
 * @argv: pointer in char input value.
 * @ptr: pointer in char input value
 * @tmp: pointer in char input value
 * @cmd: pointer
 *
 * Return: 0.
 */

int print_all(int a, char c, char *argv[], char *ptr[], char *tmp, char *cmd)
{
	switch (c)
	{
		case '\n':
			{
				if (tmp[0] == '\0')
					printf("#cisfun$ ");
				else
				{
					fill_argv(tmp);
					strncpy(cmd, my_argv[0], strlen(my_argv[0]));
					strncat(cmd, "\0", 1);
					if (index(cmd, '/') == NULL)
					{
					if (attach_path(cmd) == 0)
					{
						call_execve(cmd);
					}
					else
						printf("./shell: No such file or directory\n");
					}
					else
					{
						fd = open(cmd, O_RDONLY);
					if (fd > 0)
					{
						close(fd);
						call_execve(cmd);
					}
					else
						printf("./shell: No such file or directory\n");
					}
				}
				free_argv(void);
				printf("#cisfun$ ");
				bzero(cmd, 100);
			}
			bzero(tmp, 100);
			break;
		default:
			strncat(tmp, &c, 1);
			break;
	}
	return (0);
}
