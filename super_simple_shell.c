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

		if (readbytes == -1 || readbytes == EOF)
		{
			perror("Error:");
			free(buf);
			return (1);
		}

		/* Remove trailing newline character from user input */
		if (buf[readbytes - 1] == '\n')
		{
			buf[readbytes - 1] = '\0';
		}

		argv = malloc(sizeof(char *) * 2);
		argv[0] = malloc(sizeof(char ) * (strlen(buf) + 1));
		strcpy(argv[0], buf);
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
				exit(1);
			}
		}
		else
		{
			wait(&status);
		}
		free(argv[0]);
		free(argv);
		free(buf);
	}
	return (0);
}
