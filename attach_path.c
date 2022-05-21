#include "main.h"

/**
  * attach_path - verification path
  * @cmd: command pointer char
  * Return: 0
  */

int attach_path(char *cmd)
{
	char ret[100];
	int index;
	int fd;

	bzero(ret, 100);
	for (index = 0; search_path[index] != NULL; index++)
	{
		strcpy(ret, search_path[index]);
		strncat(ret, cmd, strlen(cmd));
		fd = open(ret, O_RDONLY);
		if (fd > 0)
		{
			strncpy(cmd, ret, strlen(ret));
			close(fd);
			return (0);
		}
	}
	return (0);
}
