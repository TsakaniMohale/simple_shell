#include "main.h"

/**
 * builtin_cmd - Calls function that execute built-in commands
 * @array: Arguments array
 * Return: 0 or 1
 */


int builtin_cmd(char **array)
{
	if (strcmp(array[0], "env") == 0)
	{
		_env();
	}
	else if (strcmp(array[0], "exit") == 0)
	{
		exit_shell(array);
	}
	else if (strcmp(array[0], "setenv") == 0)
	{
		return (mysetenv(3, array));
	}
	else if (strcmp(array[0], "unsetenv") == 0)
	{
		return (myunsetenv(2, array));
	}
	return (1);
}

