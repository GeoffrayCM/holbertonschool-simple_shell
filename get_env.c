#include "shell.h"

char *_getenv(charname)
{
	int i = 0;
	int nlen;

	if (!name || name[0] == '\0')
		return (NULL);

	nlen = _strlen(name);

	while (environ && environ[i])
	{
		if (_strncmp(environ[i], name, nlen) == 0 && environ[i][nlen] == '=')
			return (environ[i]); /* DO NOT free */
		i++;
	}

	if (_strcmp(name, "PATH") == 0)
		return ("PATH=/bin:/usr/local/bin:/usr/bin:/bin:/usr/local/sbin");

	return (NULL);
}
