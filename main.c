#include <stdio.h>

/**
 * main - Execusion of the program shell start.
 *
 * Return: Returns 0 on successs or 1 on failure
 */

int main(void)
{
	ssize_t n_chars;
	size_t n;
	char *command;
	(void)n_chars;

	for(;1;)
	{
		printf("cisfun$ ");
		n_chars = getline(&command, &n, stdin);

		tokenization(command);
	}

	return (0);
}
