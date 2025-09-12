#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * my_strdup - duplicates
 * @s: string
 *
 * Return: 0
 */
char *my_strdup(const char *s)
{
	size_t len = strlen(s) + 1;
	char *dup = malloc(len);

	if (dup == NULL)
		return (NULL);
	memcpy(dup, s, len);
	return (dup);
}
/**
 * main - path
 *
 * Return: 0
 */
int main(void)
{
	char *path_env = getenv("PATH");

	if (path_env == NULL)
	{
		fprintf(stderr, "PATH environment variable not found.\n");
		return (1);
	}

	char *path_copy = my_strdup(path_env);

	if (path_copy == NULL)
	{
		perror("Failed to allocate memory for path_copy");
		return (1);
	}

	char *token;

#ifdef _WIN32
	const char *delimiter = ";";
#else
	const char *delimiter = ":";
#endif

	token = strtok(path_copy, delimiter);
	while (token != NULL)
	{
		printf("%s\n", token);
		token = strtok(NULL, delimiter);
	}

	free(path_copy);
	return (0);
}

