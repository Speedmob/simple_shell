#include "main.h"
/**
 * _run - executes a file
 * @path: path to run the exe
 * @args: args to pass to the exe
 * @env: env var
 *
 * Return: Always Success(0)
*/
int _run(char *path, char **args, char **env)
{
	pid_t child;
	int status;

	VOIDED(path);
	child = fork();
	if (child == -1)
	{
		perror("Fork failed\n");
		return (1);
	}
	if (child == 0)
	{
		if (execve(args[0], args, env) == -1)
		{
			perror(args[0]);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		if (waitpid(child, &status, 0) == -1)
		{
			perror("waitpid");
		}
	}
	return (0);
}
/**
 * get_PATH_info - gets PATH value from PATH in env
 * @env: env to get PATH from
 *
 * Return: value of PATH
*/
char *get_PATH_info(char **env)
{
	char *value = NULL;
	int i, len, o;

	for (i = 0; (_strcmp(env[i], "PATH=") != 5); i++)
		;
	for (len = 0; env[i][len]; len++)
		;
	value = malloc(sizeof(char) * len);
	if (!value || !env)
		return (NULL);
	for (o = 0; env[i][o + 5]; o++)
		value[o] = env[i][o + 5];
	return (value);
}
/**
 * access_Check - checks if the file exists in PATH
 * @pathValue: value of PATH
 * @f: file to check
 *
 * Return: dir that has the file
*/
char *access_Check(char *pathValue, char **f)
{
	char **paths = NULL;
	char *fullPath = NULL;
	int i, o;

	if (!pathValue || !*f)
		return (NULL);
	paths = strtow(pathValue, ':');
	if (!paths)
		return (NULL);
	for (i = 0; paths[i]; i++)
	{
		fullPath = strcat(paths[i], "/");
		if (!fullPath)
			break;
		fullPath = strcat(fullPath, *f);
		if (!access(fullPath, X_OK))
		{
			for (o = 1; paths[o + i]; o++)
				free(paths[o + i]);
			free(paths);
			free(*f);
			return (fullPath);
		}
		free(paths[i]);
	}
	return (NULL);
}
/**
* psign - check the input form terminal or file
*/
void psign(void)
{
	if (isatty(STDIN_FILENO))
	{
		write(1, "($) ", 4);
	}
}
/**
 * free_grid - frees an already created grid
 * @grid: 2d array made
 * @height: height of 2d array
*/
void free_grid(char **grid, int height)
{
	int a;

	if (grid == NULL || height <= 0)
		return;
	for (a = 0; a < height; a++)
		free(grid[a]);
	free(grid);
}
