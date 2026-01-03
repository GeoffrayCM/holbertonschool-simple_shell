#include "shell.h"

/**
 * _cwp - count words
 * @str: string to check
 * Return: words count
 */

int _cwp(char *str)
{
	int i = 0;
	int s = 0;

	while (str[i])
	{
		while (str[i] == ':')
			i++;
		if (!str[i])
			break;
		s++;
		while (str[i] && str[i] != ':')
			i++;
	}
	return (s);
}

/**
 * _chspp - check for spaces
 * @str: string to check
 * @n: char location
 * Return: 1 or 0
 */

int _chspp(char *str, int n)
{
	if (str[n] == ':')
		return (0);
	return (1);
}

/**
 * strtowp - split string into array
 * @str: string
 * Return: array
 */

char **strtowp(char *str)
{
	char **dest;
	int i = 0;
	int j = 0;
	int num;
	int cw;

	if (!str)
		return (0);

	cw = _cwp(str);
	if (cw == 0)
		return (0);

	dest = malloc(sizeof(char *) * (cw + 1));
	if (!dest)
		return (0);

	while (i < cw)
	{
		num = 0;
		while (str[j] && _chspp(str, j) == 0)
			j++;
		while (str[j + num] && _chspp(str, j + num) == 1)
			num++;
		dest[i] = _strndup(&str[j], num);
		j += num;
		i++;
	}
	dest[i] = NULL;
	return (dest);
}
