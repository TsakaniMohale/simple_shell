#include "main.h"

/**
 * _env - Display environment variable
 */

void _env(void)
{
	int i;
	char **env = environ;

	for (i = 0; env[i] != NULL; i++)
	{
		write(1, env[i], strlen(env[i]));
		write(STDOUT_FILENO, "\n", 1);
	}
}

/**
 * _getenv - Retrieves the value of an environment variable
 * @var_name: The name of the variable
 * Return: The value of the variable or NULL if not found
 */

char *_getenv(const char *var_name)
{
	char **env = environ;
	size_t var_len = strlen(var_name);

	while (*env != NULL)
	{
		if (strncmp(*env, var_name, var_len) == 0 && (*env)[var_len] == '=')
		{
			return (&(*env)[var_len + 1]);
		}
		env++;
	}
	return (NULL); /* Variable not found*/
}

/**
 * exit_shell - Terminate child process
 * @array: Arguments array
 */

void exit_shell(char **array)
{
	if (array[1])
	{
		int status = atoi(array[1]);

		if (status >= 0)
		{
			/*free(array);*/
			exit(status);
		} else
		{
			perror("Exit");
		}
	}
	/*free(array);*/
	exit(EXIT_SUCCESS);
}

/**
 * mysetenv - New variable
 * @argc: Total arguments
 * @argv: Array of arguments
 * Return: 0 on success, 1 on failure
 */

int mysetenv(int argc, char **argv)
{
	if (argc != 3)
	{
		write(STDERR_FILENO, "Incorrect number of arguments\n", 30);
		return (1);
	}
	if (setenv(argv[1], argv[2], 1) != 0)
	{
		write(STDERR_FILENO, "Failed to set environment variable\n", 35);
		return (1);
	}
	return (0);
}

/**
 * myunsetenv - Remove variable
 * @argc: Total arguments
 * @argv: Array of arguments
 * Return: 0 on success, 1 on failure
 */


int myunsetenv(int argc, char **argv)
{
	if (argc != 2)
	{
		write(STDERR_FILENO, "Incorrect number of arguments\n", 30);
		return (1);
	}

	if (unsetenv(argv[1]) != 0)
	{
		write(STDERR_FILENO, "Failed to unset environment variable\n", 37);
		return (1);
	}
	return (0);
}
