#include "shell.h"

void _puts(char *str)
{
	int i = 0;

	while(str[i])
		putchar(str[i++]);
}
void ctrlC(int signal __attribute__((unused)))
{
	write(STDOUT_FILENO, "\n$ ", 3);
}
int main(void)
{
	char *buffer = NULL;
	size_t b_size = 0;
	ssize_t r; /* peut etre negatif si EOF error*/
	int user = isatty(STDIN_FILENO); /* si 0 pas de terminal */
	/* si utilisateur clavier puts du prompt */
	if (user)
		_puts("$ ");
	/* getline lis le stdin */
	signal(SIGINT, ctrlC); /* handler pour CC */ 

	while ((r = getline(&buffer, &b_size, stdin)) != -1) /* & car getline doit pouvoir modifier le buffer */ 
	{
		(void)r; /* pour l'instant pas d'usage */
		if (user)
			_puts("$ ");
	}
	if (user)
		putchar('\n');
	free(buffer); /*getline malloc auto */
	return (0);
}
