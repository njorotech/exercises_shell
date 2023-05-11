#include "main.h"

/**
  * main - prints a command prompt "$ "
  * ac: number of arguments
  * av: string array of arguments
  *
  * Return: zero on success
  * -1 on failure
  */
int main(int ac, char **av)
{
	char *lineptr = 0;
	size_t n = 0;
	ssize_t readbytes = 0;

	printf("$ ");
	readbytes = getline(&lineptr, &n, stdin);

	if (readbytes == EOF ||readbytes == -1)
	{
		free(lineptr);
		return (-1);
	}
	printf("%s", lineptr);
	free(lineptr);
	return (0);
}
