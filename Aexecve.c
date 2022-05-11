#include "main.h"
/*
 * exeP - Function that execute a command by a child processus
 */
void exeP(char *val)
{
	int i;
	if (fork() == 0)
	{
		i = mexecve(val,"","");
		if (i < 0)
		{
			printf("%s: %s\n", val, "Command not found");
			exit(1);
		}
	} else {
		wait(NULL);
	}
}
