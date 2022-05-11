#include <stdio.h>
#include <stdlib.h>
/**
 * main - function that execute our shell
 */
int main()
{
	char c = '\0';
	printf("\nIB_shell ");
	while (c != EOF)
	{
		c = getchar();
		if (c == '\n')
			printf("IB_shell ");
	}
	printf("\n");
	return (0);
}
