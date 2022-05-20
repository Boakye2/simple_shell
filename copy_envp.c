#include "main.h"
/**
  * copy_envp - for the copy
  * @envp: the environ var
  * Return: nothing
  */

void copy_envp(char **envp)
{
	int index = 0;

	for(;envp[index] != NULL; index++) 
	{
		my_envp[index] = (char *)malloc(sizeof(char) * (strlen(envp[index]) + 1));
		memcpy(my_envp[index], envp[index], strlen(envp[index]));
	}
}