#include "shell.h"

/**
 * ctrlC - function called by signal
 * @signal: unused
 * Description: ctrlC cancel the current line and produce new prompt
 * Return: void
 */
void ctrlC(int signal)
{
	(void)signal;
	write(STDOUT_FILENO, "\n$ ", 3);
}

/**
 * main - Entry
 * @ac: ac
 * @av: av
 * Description: main function that run getline to read from the terminal
 * split the command from input
 * compare the input to built-ins commands
 * send the command to getpath to form a valid path
 * Return: 0
 */
int main(int ac, char **av)
{
	char *buffer = NULL;
	char **cmd = NULL;
	size_t b_size = 0;
	int user = isatty(STDIN_FILENO), path_value;/* si 0 pas de terminal */
	unsigned int line = 0;
	int status = 0;

	if (user)
		_puts("$ ");
	(void)ac, signal(SIGINT, ctrlC); /* handler pour CC */
	while (getline(&buffer, &b_size, stdin) != -1 && ++line)
	{
		cmd = strtow(buffer);
		if (!cmd)
		{
			if (user)
				_puts("$ ");
			continue;
		}
		if (env_builtin(cmd) || exit_builtin(cmd))
		{
			free_cmd(cmd);
			if (user)
				_puts("$ ");
			continue;
		}
		path_value = get_path(cmd);
		if (path_value == 1)
		{
			execve_cmd(cmd, av[0], line);
			status = 0;
		}
		else if (path_value == -1)
		{
			print_perm_denied(av[0], line, cmd[0]);
			status = 126;
		}
		else
		{
			print_not_found(av[0], line, cmd[0]);
			status = 127;
		}
		free_cmd(cmd);
		if (user)
			_puts("$ ");
	}
	if (user)
		putchar('\n');
	free(buffer); /*getline malloc auto */
	return (status);
}
