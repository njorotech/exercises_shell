#ifndef MAIN_H
#define MAIN_H
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
void print_words (char **words_array);
char **split_string(char *buf, int words_quantity, char **words_array, const char *delimeter);
int no_of_words(char *buf_copy, const char *delimeter);
void free_words_array(char **words_array);
#endif
