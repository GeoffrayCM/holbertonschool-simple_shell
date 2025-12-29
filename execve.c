#include "shell.h"

void execve_cmd(char **cmd)
{
	/* declare un pid et un status pour waitpid */
	pid_t pid;
	int status;

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
	 /* l’enfant existe, si execve reussi l’enfant disparait et devient le process (ls etc) 
	    et le code s’arrete ici (sauf waitpid), sinon perror et exit */
		if (pid == 0)
		{
			execve(cmd[0], cmd, environ);
			perror(cmd[0]);
			exit(127);
		}
	 /* parent attend la mort de l’enfant avant de reprendre prompt et getline */ 
		waitpid(pid, &status, 0);
}
