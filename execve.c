#include "shell.h"

/**
 * execve_cmd - use execve to process the command
 * @cmd: input forming an array of commands
 * Description: This code firstly uses fork to create a child
 * if the fork is successfull execve tries to run the command
 * Return: None
 */
void execve_cmd(char **cmd)
{
	/* declare un pid et un status pour waitpid */
	pid_t pid;
	int status;

	/* DEBUG: pid du shell (parent) avant fork */
	printf("[DEBUG] before fork: pid=%d\n", getpid());

	/* check si fichier existe (/bin/ls etc) */
	if (access(cmd[0], X_OK) != 0)
	{
		perror(cmd[0]);
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
		printf("[DEBUG] child: pid=%d ppid=%d cmd=%s\n", getpid(), getppid(), cmd[0]);
		execve(cmd[0], cmd, environ);
		perror(cmd[0]);
		exit(127);
	}
	/* DEBUG: on est dans le parent (pid = pid de l'enfant) */
	printf("[DEBUG] parent: pid=%d child_pid=%d\n", getpid(), pid);
	/* part attend mort de l’enfant avant de reprendre prompt getline */
	printf("[DEBUG] child %d finished\n", pid);
	waitpid(pid, &status, 0);
}
