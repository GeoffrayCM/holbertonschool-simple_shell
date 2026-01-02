#include "shell.h"

/**
 * direct_path - helper to shorten get_path
 * @cmd: input
 * Return: 0 if not found, -1 if found but no x, 1 if f and x
 */
int direct_path(char **cmd)
{
	if (access(cmd[0], F_OK) != 0)
		return (0);
	if (access(cmd[0], X_OK) != 0)
		return (-1);
	return (1);
}

/**
 * get_path - replace cmd[0] with full path
 * @cmd: array from strtow (cmd[0] is the command name)
 * Description: Firstly retrieve env with getenv
 * check if we already have an absolute path
 * split path with strtow to create severals dirs
 * check access each dirs with the cmd concatenated to it
 * Return: 1 if a valid executable path is found, 0 otherwise
 */
int get_path(char **cmd)
{
	char *env, *path, *full = NULL;
	char **dirs;      /* PATH directories split by ':' */
	int i = 0;

	if (!cmd || !cmd[0] || cmd[0][0] == '\0')
		return (0);
	if (cmd[0][0] == '/' || (cmd[0][0] == '.' && cmd[0][1] == '/'))
		return (direct_path(cmd));
	env = _getenv("PATH");	/* ("PATH=...") */
	if (!env)
		return (0);
	path = _strdup(env + 5);	/* skip the 5 chars "PATH=" duplicate the rest */
	if (!path)
		return (0);
	dirs = strtow(path);	/* split PATH by ':' into directories */
	free(path);
	if (!dirs)
		return (0);
	while (dirs[i])		/* try each directory with access() */
	{
		full = _calloc(sizeof(char), _strlen(dirs[i]) + 1 + _strlen(cmd[0]) + 1);
		if (!full)
			break;
		_strcat(full, dirs[i]);
		_strcat(full, "/");
		_strcat(full, cmd[0]);
		if (access(full, X_OK) == 0) /* found an executable */
			break;
		free(full);
		full = NULL;
		i++;
	}
	free_cmd(dirs);
	if (!full)
		return (0);
	free(cmd[0]);
	cmd[0] = full;
	return (1);
}
