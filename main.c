#include "main.h"

/**
 * main - Execusion of the program shell start.
 *
 * Return: Returns 0 on successs or 1 on failure
 */

int main(void)
{
	ssize_t n_chars;
	size_t n;
	char *command = NULL;
	const char *tokens_array[100] = {NULL, NULL};
	(void)n_chars;

	for ( ; 1; )
	{
		printf("cisfun$ ");
		n_chars = getline(&command, &n, stdin);
		if (n_chars < 0)
			exit(EXIT_FAILURE);

		tokenization(command, tokens_array);
		exec(tokens_array);
		free(command);
	}

	return (0);
}
