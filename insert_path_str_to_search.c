#include "main.h"
/**
  * insert_path_str_to_search - search
  * @path_str: path string
  * Return: None
  */
void insert_path_str_to_search(char *path_str) 
{
	int index=0;
	char *tmp = path_str;
	char ret[100];

	while(*tmp != '=')
		tmp++;
	tmp++;

	while(*tmp != '\0') {
		if(*tmp == ':') {
			strncat(ret, "/", 1);
			search_path[index] = (char *) malloc(sizeof(char) * (strlen(ret) + 1));
			strncat(search_path[index], ret, strlen(ret));
			strncat(search_path[index], "\0", 1);
			index++;
			bzero(ret, 100);
		} else {
			strncat(ret, tmp, 1);
		}
		tmp++;
	}
}