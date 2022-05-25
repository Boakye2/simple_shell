#include "main.h"

/**
 * main - program that prints "$ ".
 * Return: a;
 */

int main(void)
{
	size_t buflen = 32;
	pid_t pid;
	char *buffer, *argv[] = {"/bin/ls","ls", "-l","/tmp" };
	
	buffer = (char *)malloc(buflen * sizeof(char));
        if (!buffer)
        {
                perror("impossible d'allouer");
        }
	printf("#cisfun$");
        getline(&buffer, &buflen, stdin);
	pid = fork();
	if (pid == 0)
	{
		if (execve(argv[0], argv, NULL) == -1)
		{
			perror("./shell:");
		}
	}
	else
	{
		perror("error");
	}
	exit(0);
}
