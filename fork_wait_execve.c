#include "main.h"

/**
  * main - a program that executes the command ls -l /tmp in 5 different
  * child processes
  *
  * Return: Always 0.
  */
int main(void)
{
	pid_t child_pid;
	int status, i = 0;
	char *argv[] = {"/bin/ls", "-l", "/tmp", NULL};
	
	while (i < 5)
	{
		child_pid = fork();

		if (child_pid == -1)
		{
			perror("Error:");
			return (1);
		}
		
		/*printf("My pid is %u\n", getpid());*/
		if (child_pid == 0)
		{
			if (execve(argv[0], argv, NULL) == -1)
			{
				perror("Error:");
				return (1);
			}
		}
		else
		{
			wait(&status);
			printf("finished waiting\n");
		}
		i++;
	}
	return (0);
}
