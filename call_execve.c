#include "main.h"
/**
  * call_execve - verification
  * @cmd: command
  * Return: none
  */
void call_execve(char *cmd)
{
	int i;
	if(fork() == 0) {
		i = execve(cmd, my_argv, my_envp);
		if(i < 0) {
			printf("./shell: No such file or directory\n");
			exit(1);		
		}
	} else {
		wait(NULL);
	}
}