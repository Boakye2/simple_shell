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
	char *tmp = (char *)malloc(sizeof(char) * 100);
	argc = 0;


	if (fork() == 0)
	{
		execve("/usr/bin/clear", argv, ptr);
		exit(1);
	}
	else
	{
		wait(NULL);
	}
	printf("#cisfun$ ");
	while (c != EOF)
	{
		c = getchar();
		switch (c)
		{
			case '\n':
				{
					if (tmp[0] == '\0')
					{
						printf("#cisfun$ ");
					}
					else
					{
						int i;

						if (fork() == 0)
						{
							i = execve(tmp, argv, ptr);
							if (i < 0)
							{
								printf("./shell: No such file or directory\n");
								exit(1);
							}
						}
						else
						{
							wait(NULL);
						}
					}
					printf("#cisfun$ ");
				}
				bzero(tmp, 100);
				break;
			default:
				strncat(tmp, &c, 1);
				 break;
		}
	}
	free(tmp);
	printf("\n");
	return (argc);
}
