#include "shell.h"

void ctrlC(int signal __attribute__((unused)))
{
	write(STDOUT_FILENO, "\n$ ", 3);
}
int main(void)
{
	char *buffer = NULL;
	char **cmd = NULL;
	size_t b_size = 0;
	ssize_t r; /* peut etre negatif si EOF error*/
	int user = isatty(STDIN_FILENO); /* si 0 pas de terminal */
	/* terminal ? */
	if (user)
		_puts("$ ");
	/* getline lis le stdin */
	signal(SIGINT, ctrlC); /* handler pour CC */ 

	while ((r = getline(&buffer, &b_size, stdin)) != -1) /* & car getline doit pouvoir modifier le buffer */ 
	{
		(void)r; /* pour l'instant pas d'usage */
		cmd = strtow(buffer);
		if (!cmd)
			continue;

		free_cmd(cmd);
		if (user)
			_puts("$ ");
	}
	if (user)
		putchar('\n');
	free(buffer); /*getline malloc auto */
	return (0);
}
