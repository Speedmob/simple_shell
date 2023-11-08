#include "main.h"
/**
 * _print_env - prints env
 * @env: env to print
*/
void _print_env(char **env)
{
	int i;

	for (i = 0; env[i]; i++)
		printf("%s\n", env[i]);
}
