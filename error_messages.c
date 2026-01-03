#include "shell.h"
/**
 * print_perm_denied - print error with same output as sh
 * @prog: programe name av[0]
 * @line: line number
 * @cmd: input
 * Return: void
 */
void print_perm_denied(char *prog, unsigned int line, char *cmd)
{
	char buf[32];
	int len;

	write(STDERR_FILENO, prog, _strlen(prog));
	write(STDERR_FILENO, ": ", 2);
	len = sprintf(buf, "%u", line);
	write(STDERR_FILENO, buf, len);
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, cmd, _strlen(cmd));
	write(STDERR_FILENO, ": Permission denied\n", 20);
}

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
 * print_is_dir - print error with same output as sh
 * @prog: program name av[0]
 * @line: line number
 * @cmd: input
 * Return: void
 */
void print_is_dir(char *prog, unsigned int line, char *cmd)
{
	char buf[32];
	int len;

	write(STDERR_FILENO, prog, _strlen(prog));
	write(STDERR_FILENO, ": ", 2);
	len = sprintf(buf, "%u", line);
	write(STDERR_FILENO, buf, len);
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, cmd, _strlen(cmd));
	write(STDERR_FILENO, ": is a directory\n", 17);
}
