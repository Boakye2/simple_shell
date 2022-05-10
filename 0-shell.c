#include <stdio.h>
#include <stdlib.h>
#include "main.h"

/**
 * main - program that prints "$ ".
 * Return: 0;
 */

int main()
{
	char *buffer;
	size_t buflen = 32;
	size_t valeur;

	buffer = malloc(buflen * sizeof(char));
	if (!buffer)
	{
		perror("impossible d'allouer");
	}
	for (int i = 0; i < 5; i++)
	{	
		printf("$ ");
		valeur = getline(&buffer, &buflen, stdin);
		printf("%zu \n", valeur);
		printf("%s\n", buffer);
	}
	return (0);
}
