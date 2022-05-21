#include "main.h"

/**
  * main- main for all functions
  * @argc: number of argument char
  * @argv: argument pointer char
  * @envp: argument char
  * Return: 0.
  */

int main(int argc, char *argv[], char *envp[])
{
	char c;
	int i, fd;
	char *tmp = (char *)malloc(sizeof(char) * 100);
	char *path_str = (char *)malloc(sizeof(char) * 256);
	char *cmd = (char *)malloc(sizeof(char) * 100);

	signal(SIGINT, SIG_IGN);
	signal(SIGINT, handle_signal);

	copy_envp(envp);
	get_path_string(my_envp, path_str);
	insert_path_str_to_search(path_str);

	if (fork() == 0)
	{
		execve("/usr/bin/clear", argv, my_envp);
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
		switch (c)
		{
			case '\n':
				if (tmp[0] == '\0')
				{
					printf("#cisfun$ ");
				}
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
						{
							printf("./shell: No such file or directory\n");
						}
					}
					else
					{
						if ((fd = open(cmd, O_RDONLY)) > 0)
						{
							close(fd);
							call_execve(cmd);
						}
						else
						{
							printf("./shell: No such file or directory\n");
						}
					}
					free_argv();
					printf("#cisfun$ ");
					bzero(cmd, 100);
				}
				bzero(tmp, 100);
				break;
			default: strncat(tmp, &c, 1);
				 break;
		}
	}
	free(tmp);
	free(path_str);
	for (i = 0; my_envp[i] != NULL; i++)
		free(my_envp[i]);
	for( i = 0; i < 10; i++)
		free(search_path[i]);
	printf("\n");
	return 0;
}
