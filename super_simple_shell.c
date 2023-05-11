#include "main.h"

/**
  * main - super simple shell that can run commands
  * with their full path, without any argument.
  *
  * Return: always 0.
  */
int main(void)
{
	char *buf = NULL;
	pid_t child_pid;
	char **argv;
	int readbytes = 0, status;
	size_t n = 0;

	while (1)
	{
		printf("#cisfun$ ");

		readbytes = getline(&buf, &n, stdin);

		if (readbytes == -1)
		{
			perror("Error:");
			free(buf);
			return (1);
		}

		argv = malloc(sizeof(char *) * 2);
		argv[0] = malloc(sizeof(char ) * (strlen(buf) + 1));
		argv[1] = NULL;

		child_pid = fork();

		if (child_pid == -1)
		{
			perror("Error: ");
			return (1);
		}

		if (child_pid == 0)
		{
			if (execve(argv[0], argv, NULL) == -1)
			{
				perror("Error:");
			}
		}
		else
		{
			wait(&status);
		}
		free(buf);
		free(argv);
		free(argv[0]);
	}
	return (0);
}
