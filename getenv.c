#include <stdio.h>
#include <string.h>

extern char **environ;

/**
 * _getenv - custom getenv function
 * @name: name of the environment variable
 *
 * Return: pointer to the value string, or NULL if not found
 */
char *_getenv(const char *name)
{
	int i;
	size_t len = strlen(name);

	for (i = 0; environ[i] != NULL; i++)
	{
		if (strncmp(environ[i], name, len) == 0 && environ[i][len] == '=')
			return (environ[i] + len + 1);
	}
	return (NULL);
}

/**
 * main - entry point, test _getenv function
 *
 * Return: Always 0
 */
int main(void)
{
	char *value;

	value = _getenv("PATH");
	if (value != NULL)
		printf("PATH = %s\n", value);
	else
		printf("PATH not found\n");

	return (0);
}

