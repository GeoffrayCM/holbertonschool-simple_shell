int _putchar(char c)
{
	return (write(1, &c, 1));
}

void _puts(char *str)
{

	int i = 0;

	while(str[i])
	{
	_putchar(str[i]);
	i++;
	}
}

int _strlen(char *str)
{
	int i = 0;

	while(str[i])
		i++;
	return(i);
}

/**
 * _strcat - concatenate 2 strings
 * @dest: string that receive
 * @src: source string
 * Return: pointer to new string dest
 */

char *_strcat(char *dest, char *src)
{
	int i = 0;
	int j = 0;

	while (dest[i])
		i++;
	while (src[j])
	{
		dest[i] = src[j];
		j++;
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

/**
 * _strdup - duplicate string
 * @str: string
 * Return: allocated string
 */

char *_strdup(char *str)
{
	int i = 0;
	char *dest;

	if (str == 0)
		return (0);
	while (str[i])
		i++;
	dest = malloc(sizeof(char) * i + 1);
	if (!dest)
		return (0);
	i = 0;
	while (str[i])
	{
		dest[i] = str[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

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


