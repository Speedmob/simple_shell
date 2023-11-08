#include "main.h"
/**
 * main - Entry point
 * @ac: num of args
 * @av: args vector
 * @envp: env variables
 *
 * Return: Always Success(0)
*/
int main(int ac, char **av, char **envp)
{
	size_t len = 0;
	char *line = NULL, *path = NULL;
	char **fline = NULL;

	VOIDED(ac);
	VOIDED(av);
	path = get_PATH_info(envp);
	psign();
	while (getline(&line, &len, stdin) != EOF)
	{
		line[_strlen(line) - 1] = '\0';
		if (_strcmp(line, "exit") == 4)
			break;
		if (_strcmp(line, "env") == 3)
		{
			_print_env(envp);
			continue; }
		fline = strtow(line, ' ');
		if (fline == NULL)
		{
			psign();
			continue; }
		if (line[0] != '/')
			fline[0] = access_Check(path, &fline[0]);
		if (!access(fline[0], X_OK))
			_run(fline[0], fline, envp);
		else
		{
			printf("%s: ", av[0]);
			if (line[0] == '/')
				printf("%s: No such file or directory\n", fline[0]);
			else
				printf("%s: command not found\n", line); }
		free_grid(fline, cgrid(fline));
		psign(); }
	if (isatty(STDIN_FILENO) && _strcmp(line, "exit") != 4)
		putchar(10);
	free(path);
	free(line);
	return (EXIT_SUCCESS); }
