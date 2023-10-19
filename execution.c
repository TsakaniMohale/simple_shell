#include "main.h"

/**
 * exec - The function execute the commands
 * @cmd: Command to be executed
 * @argv: Array of arguments
 *
 */

void exec(const char **cmd, **argv)
{
	int status;
	pid_t child_pid = fork();

	if (child_pid == -1)
	{
		perror(argv[0]);
		exit(EXIT_FAILURE);
	} else if (child_pid == 0)
	{
		if (cmd)
		{
			/*Executing the first string from the command*/
			if (execve(cmd[0], (char * const*)cmd[0], NULL) == -1)
			{
				perror(argv[0]);
				exit(EXIT_FAILURE);
			}
		}
	} else
	{
		waitpid(child_pid, &status, 0);
	}
}
