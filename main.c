#include "main.h"
#include <stdbool.h>

/**
 * signal_handler - Handles interrupt Ctrl+C signal
 * @signal: The signal
 */

void signal_handler(int signal)
{
	(void)signal;
	write(STDOUT_FILENO, "\n#cisfun$ ", 10);
	kill(getpid(), SIGCONT);
}

/**
 * is_interactive - Returns associated file descriptor
 * Return: input(0) file descriptor
 */
bool is_interactive(void)
{
	return (isatty(STDIN_FILENO) && isatty(STDOUT_FILENO));
}

/**
 * get_line - Get the the user inpute
 * @command: Arguments array
 * Return: The command read
 */
char *get_line(char **command)
{
	char *input = NULL;
	size_t length = 0;
	ssize_t n_chars;

	signal(SIGINT, signal_handler);

	n_chars = getline(&input, &length, stdin);
	if (n_chars == -1)
	{
		free(input);
		input = NULL;
		if (isatty(STDIN_FILENO) && isatty(STDOUT_FILENO))
		{
			write(STDOUT_FILENO, "\n", 1);
		}
		exit(0);
	}
	if (strcmp(input, "\n") == 0)
	{
		free(input);
		input = NULL;
		get_line(command);
	}
	if (input[n_chars - 1] == '\n')
	{
		input[n_chars - 1] = '\0';
	}
	return (input);
}

/**
 * main - Execusion of the program shell start.
 * @argc: Total number of arguments
 * @argv: Array of arguments
 * Return: Returns 0 on successs or 1 on failure
 */

int main(int argc, char **argv)
{
	char *command = NULL;
	const char *tokens_array[100] = {NULL, NULL};
	(void)argc;

	for ( ; 1; )
	{
		if (is_interactive())
			write(STDOUT_FILENO, "#cisfun$ ", 9);

		command = get_line((char **)tokens_array);

		tokenization(command, tokens_array);
		exec(tokens_array, argv);
	}

	free(command);
	return (0);
}
