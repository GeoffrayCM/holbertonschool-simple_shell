#include "shell.h"
#include <errno.h>

/**
 * execve_cmd - use execve to process the command
 * @cmd: input forming an array of commands
 * @prog: prog name av[0] for error messages
 * @line: line number for error messages
 * Description: This code firstly uses fork to create a child
 * if the fork is successfull execve tries to run the command
 * Return: None
 **/

void execve_cmd(char **cmd, char *prog, unsigned int line)
{
	pid_t pid;
	int status;

	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		return;
	}
	if (pid == 0)
	{
		execve(cmd[0], cmd, environ);
		if (errno == ENOENT)
			print_not_found(prog, line, cmd[0]);
		else
			perror(cmd[0]);
		exit(127);
	}
	waitpid(pid, &status, 0);
}
