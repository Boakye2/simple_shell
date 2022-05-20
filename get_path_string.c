#include "main.h"
/**
  * get_path_string - find the path
  * @tmp_envp: string env
  * @bin_path: bin path
  * Return: None
  */

void get_path_string(char **tmp_envp, char *bin_path)
{
	int count = 0;
	char *tmp;
	while(1) {
		tmp = strstr(tmp_envp[count], "PATH");
		if(tmp == NULL) {
			count++;
		} else {
			break;
		}
	}
        strncpy(bin_path, tmp, strlen(tmp));
}