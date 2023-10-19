#include "main.h"

/**
 * main - Execusion of the program shell start.
 * @argc: Total number of arguments
 * @argv: Array of arguments
 * Return: Returns 0 on successs or 1 on failure
 */

int main(int argc, char **argv)
{
	ssize_t n_chars;
	size_t n;
	char *command = NULL;
	const char *tokens_array[100] = {NULL, NULL};
	(void)argc;

	for ( ; 1; )
	{
		printf("cisfun$ ");
		n_chars = getline(&command, &n, stdin);
		if (n_chars < 0)
			exit(EXIT_FAILURE);

		tokenization(command, tokens_array);
		exec(tokens_array, argv);
		free(command);
	}

	return (0);
}
