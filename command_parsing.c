#include <string.h>

/**
 * tokenization - The function tokenize the input to make tokens.
 * @input: The user input from the key board
 *
 */

void tokenization(char *input)
{
	int i;
	char *tokens_array[100];

	tokens_array[0] = strtok(input, " ");
	for (i = 0; tokens_array != NULL; i++)
	{
		tokens_array[++i] = strtok(NULL, " ");
	}
}
