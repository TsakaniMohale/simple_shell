#include "main.h"

/**
 * exec - The function execute the commands
 * @cmd: Command to be executed
 * @argv: Array of arguments
 *
 */

void exec(const char **cmd, char **argv)
{
	int status;
	pid_t child_pid = fork();
	char *path;

	if (child_pid == -1)
	{
		perror(argv[0]);
		exit(EXIT_FAILURE);
	} else if (child_pid == 0)
	{
		if (cmd)
		{
			builtin_cmd((char **)cmd);
			path = _path(cmd[0]);
			if (path == NULL)
			{
				perror(argv[0]);
				exit(EXIT_FAILURE);
			}

			if (execve(path, (char * const*)cmd, NULL) == -1)
			{
				perror(argv[0]);
				exit(EXIT_FAILURE);
			}
			free(path);
			path = NULL;
		}
	} else
	{
		waitpid(child_pid, &status, 0);
	}
}
