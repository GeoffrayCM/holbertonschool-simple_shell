#include "shell.h"
/**
 * _strcmp - compares two strings
 * @s1: first string
 * @s2: second string
 *
 * Return: difference between first non-matching characters
 */
int _strcmp(char *s1, char *s2)
{
	while (*s1 && (*s1 == *s2))
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

void free_cmd(char **str)
{
	int i = 0;

	if (!str)
		return;
	while (str[i])
	free(str[i++]);
	free(str);
}

int _strncmp(char *s1, char *s2, unsigned int n)
{
	int i = 0;

	while (s1[i] && s2[i] && s1[i] == s2[i] &&
			i < n - 1)
		i++;
	return (s1[i] - s2[i]);
}


