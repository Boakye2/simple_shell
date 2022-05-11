
#include "main.h"
/**
 * main - function that execute our shell
 */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

char c = '\0';



int main()
{
	printf("IB_shell  ");
	while(c != EOF) {
		c = getchar();
		switch(c) {
			case '\n':  if(tmp[0] == '\0') {
					   printf("IB_shell  ");
				   } else {}
				   break;
			default: strncat(tmp, &c, 1);
				 break;
		}
	}
	f
	printf("\n");
	return 0;
}
