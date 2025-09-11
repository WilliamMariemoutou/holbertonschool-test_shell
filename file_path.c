#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

/**
 * search_path - looks for a command in PATH and prints the first match
 * @filename: command name to search for
 *
 * Return: 1 if found, 0 otherwise
 */
int search_path(char *filename)
{
	char *path_env, *path_copy, *dir;
	char full_path[1024];
	int found = 0;

	path_env = getenv("PATH");
	if (path_env == NULL)
		return (0);

	path_copy = strdup(path_env);
	if (path_copy == NULL)
	{
		perror("strdup");
		exit(EXIT_FAILURE);
	}

	dir = strtok(path_copy, ":");
	while (dir != NULL)
	{
		snprintf(full_path, sizeof(full_path), "%s/%s", dir, filename);

		if (access(full_path, X_OK) == 0)
		{
			printf("%s\n", full_path);
			found = 1;
			break;
		}
		dir = strtok(NULL, ":");
	}

	free(path_copy);
	return (found);
}

/**
 * main - entry point
 * @argc: argument count
 * @argv: argument vector
 *
 * Return: 0 on success, 1 on error
 */
int main(int argc, char *argv[])
{
	int i, found;

	if (argc < 2)
	{
		printf("Usage: %s filename ...\n", argv[0]);
		return (1);
	}

	for (i = 1; i < argc; i++)
	{
		found = search_path(argv[i]);
		if (!found)
			printf("%s not found in PATH\n", argv[i]);
	}

	return (0);
}

