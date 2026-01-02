#include "shell.h"

/**
 * print_not_found - print error with same output as sh
 * @prog: program name av[0]
 * @line: line number
 * @cmd: input
 * Return: void
 */
void print_not_found(char *prog, unsigned int line, char *cmd)
{
	char buf[32];
	int len;

	write(STDERR_FILENO, prog, _strlen(prog));
	write(STDERR_FILENO, ": ", 2);

	len = sprintf(buf, "%u", line);
	write(STDERR_FILENO, buf, len);

	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, cmd, _strlen(cmd));
	write(STDERR_FILENO, ": not found\n", 12);
}

/**
 * ctrlC - function called by signal
 * @signal: unused
 * Description: ctrlC cancel the current line and produce new prompt
 * Return: void
 */
void ctrlC(int signal __attribute__((unused)))
{
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
	(void)ac;
	char *buffer = NULL;
	char **cmd = NULL;
	size_t b_size = 0;
	int user = isatty(STDIN_FILENO); /* si 0 pas de terminal */
	unsigned int line = 0;

	if (user)
		_puts("$ ");
	signal(SIGINT, ctrlC); /* handler pour CC */
	while (getline(&buffer, &b_size, stdin) != -1)
	{
		line++;
		(void)r; /* pour l'instant pas d'usage */
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
		else if (get_path(cmd) == 1)
			execve_cmd(cmd);
		else
			print_not_found(av[0], line, cmd[0]);
		free_cmd(cmd);
		if (user)
			_puts("$ ");
	}
	if (user)
		putchar('\n');
	free(buffer); /*getline malloc auto */
	return (0);
}
