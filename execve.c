#include "shell.h"

/**
 * execve_cmd - use execve to process the command
 * @cmd: input forming an array of commands
 * @prog: prog name av[0] for error messages
 * @line: line number for error messages
 * Description: This code firstly uses fork to create a child
 * if the fork is successfull execve tries to run the command
 * Return: None
 */
void execve_cmd(char **cmd, char *prog, unsigned int line)
{
	/* declare un pid et un status pour waitpid */
	pid_t pid;
	int status;

	/* check si fichier existe (/bin/ls etc) */
	if (access(cmd[0], X_OK) != 0)
	{
		print_perm_denied(prog, line, cmd[0]);
		return;
	}
	/* fork clone le process enfant et parent */
	pid = fork();
	/* si fork echoue */
	if (pid == -1)
	{
		perror("fork");
		return;
	}
	/*
	 *l’enfant existe, si execve reussi l’enfant disparait
	 *l'enfant devient le process (ls etc)
	 * le code s’arrete ici (sauf waitpid), sinon perror et exit
	 */
	if (pid == 0)
	{
		/* DEBUG: on est dans l'enfant */
		execve(cmd[0], cmd, environ);
		print_perm_denied(prog, line, cmd[0]);
		exit(127);
	}
	waitpid(pid, &status, 0);
}
