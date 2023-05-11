#include "main.h"

/**
  * main - prints the PID of the parent process
  * 
  * Return: Always 0.
  */
int main(void)
{
	pid_t my_ppid;

	my_ppid = getppid();
	printf("%d\n", my_ppid);
	return (0);
}
