#include "main.h"

/**
  * main - Entry point
  *
  * Return: Always 0.
  */
int main(void)
{
	const char *delimeter = " \n";
	char **words_array = NULL;
	char *word, *buf_copy, *buf = NULL;
	int words_quantity = 0;
	ssize_t readbytes = 0;
	size_t n = 0;
	
	readbytes = getline(&buf, &n, stdin);
	if (readbytes == EOF || readbytes == -1)
	{
		free(buf);
		return (-1); /* not sure about this */
	}

	buf_copy = strcpy(buf_copy, buf);

	/* count the no. of words in the string */
	words_quantity = no_of_words(buf_copy, delimeter);

	/* Allocate memory for words_array */
	words_array = malloc((words_quantity + 1) * sizeof(char *));
	if (words_array == NULL)
	{
		perror("Memory allocation failed");
		return (1);/*not sure about this*/
	}

	/* Parse the string into individual words*/
	words_array = split_string(buf, words_quantity, words_array, delimeter);

	/* print the array */
	print_words(words_array);

	/* free memory */
	free_words_array(words_array);
	return (0);

}

int no_of_words(char *buf_copy, const char *delimeter)
{
	char *word;
	int words_quantity = 0;

	word = strtok(buf_copy, delimeter);

	while (word != NULL)
	{
		words_quantity++;
		word = strtok(NULL, delimeter);
	}
	
	return (words_quantity);
}
char **split_string(char *buf, int words_quantity, char **words_array, const char *delimeter)
{
	int i = 0;
	char *word;

	word = strtok(buf, delimeter);
	while (word != NULL)
	{
		words_array[i] = malloc((strlen(word) + 1) * sizeof(char));
		if (words_array[i] == NULL)
		{
			perror("Memory allocation failed");
			return (NULL);
		}

		strcpy(words_array[i], word);
		i++;
		word = strtok(NULL, delimeter);
	}

	/* Set the last element of the array to NULL */
	words_array[i] = NULL;

	return (words_array);
}

void print_words (char **words_array)
{
	int i = 0;

	while (words_array[i])
	{
		printf("%s\n", words_array[i]);
		i++;
	}
}

void free_words_array(char **words_array)
{
	int i = 0;

	while(words_array[i])
	{
		free(words_array[i]);
		i++;
	}
	free(words_array);
}
