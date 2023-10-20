#include "main.h"
/**
 * _path - Create a correct path for the command.
 * @cmd: Command to be appendend to the path
 * Return: Correct path
 */

char *_path(const char *cmd)
{
	struct stat buffer;
	char *env_path = getenv("PATH"), *path_tokens = NULL, *path = NULL;

	if (env_path == NULL)
		return (NULL);

	path_tokens = strtok(env_path, ":");
	while (path_tokens != NULL)
	{
		path = malloc(strlen(path_tokens) + strlen(cmd) + 2);
		if (path == NULL)
		{
			perror("Memory alloc error");
			exit(EXIT_FAILURE);
		}
		strcpy(path, path_tokens);
		strcat(path, "/");
		strcat(path, cmd);

		if (stat(path, &buffer) == 0)
		{
			return (path);
		}
		free(path);
		path = NULL;
		path_tokens = strtok(NULL, ":");
	}
	if (stat(cmd, &buffer) == 0)
		return (strdup(cmd));
	return (NULL);
}

