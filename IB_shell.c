#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "main.h"
#include <string.h>
/**
 * main - function that execute our shell
 */
int main(int argc, char *argv[], char *en[])
{
	char c = '\0';
	char *val = (char *)malloc(sizeof(char) * 100);
	printf("\nIB_shell ");
	while (c != EOF)
	{
		c = getchar();
		switch (c)
		{
			case '\n': if (val[0] == '\0'){
					   printf("IB_shell ");
				   } else {
					 if (fork() == 0){
						 system(val);
						 exit(1);
				   }
				   }
				   printf("\nIB_shell ");
				   break;
			default:strncat(val, &c, 1);
				break;
		}
	}
	printf("%s",val);
	printf("\n");
	return (0);
}
/*void exeP(char *val)
{
	int i;
	if (fork() == 0)
		i = execve(val," -","l");
		if (i < 0)
		{
			printf("not foun");
			exit(1);
		}
		else {
			wait(NULL);
		}
}*/
