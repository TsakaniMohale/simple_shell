#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>

/**
 * tokenization - The function tokenize the input to make tokens.
 * @input: The user input from the key board
 * @tokens_array: The array of tokens parsed
 *
 */

void tokenization(char *input, const char *tokens_array[])
{
	int i;

	tokens_array[0] = strtok(input, DELIM);
	for (i = 0; tokens_array[i] != NULL; i++)
	{
		tokens_array[++i] = strtok(NULL, DELIM);
	}
}
