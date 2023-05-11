#include "main.h"

/**
  * main - prints all the arguments, without using ac
  * @ac: number of arguments passed by the user
  * @av: null terminated array of strings passed as arguments
  *
  * Return: Always 0.
  */
int main(int ac, char **av)
{
	int i = 0;

	while (av[i])
	{
		printf("%s\n", av[i]);
		i++;
	}
	return (0);
}
