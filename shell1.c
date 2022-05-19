#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include "main.h"

/**
 * main - program that prints "$ ".
 * Return: a;
 */

int main(void)
{
	size_t buflen = 32;
	char *buffer, *argv[] = {"/bin/ls", NULL}, cmd[] = "/bin/ls";

	buffer = (char *)malloc(buflen * sizeof(char));
	if (!buffer)
	{
		perror("impossible d'allouer");
	}
	printf("#cisfun$");
	getline(&buffer, &buflen, stdin);
	while (*buffer != EOF)
	{
		if (cmd[0] == *buffer)
		{
			int i;

			if (fork() == 0)
			{
				i = execve(cmd, argv, NULL);
				if (i < 0)
				{
					printf("./shell: No such file or directory\n");
				}
			}
			else
			{
				wait(NULL);
			}
			printf("#cisfun$");
			getline(&buffer, &buflen, stdin);
		}
		else
		{
			printf("./shell: No such file or directory\n");
		}
	printf("#cisfun$");
	getline(&buffer, &buflen, stdin);
	}
	return (0);
}
