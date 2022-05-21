#include "main.h"

/**
  * copy_envp - for the copy la
  * @envp: the environ var moau
  * Return: nothing
  */

void copy_envp(char **envp)
{
	int index = 0;

	for (index = 0; envp[index] != NULL; index++)
	{
		my_envp[index] = (char *)malloc(sizeof(char) * (strlen(envp[index]) + 1));
		memcpy(my_envp[index], envp[index], strlen(envp[index]));
	}
}
