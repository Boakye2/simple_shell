#include "main.h"

/**
 * main - program that prints "$ ".
 * Return: a;
 */

int main(void)
{
	size_t buflen = 32;
	ssize_t len = 0;
	char *buffer, *argv[] = {"/bin/ls", NULL}, cmd[] = "/bin/ls";

	buffer = (char *)malloc(buflen * sizeof(char));
	if (!buffer)
	{
		perror("impossible d'allouer");
	}
	while (len != EOF)
	{
		printf("#cisfun$");
		len = getline(&buffer, &buflen, stdin);
		if (cmd == buffer)
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
		}
		else
		{
			printf("./shell: No such file or directory\n");
		}
	}
	return (0);
}
