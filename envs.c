#include <stdio.h>

extern char **environ;

/**
 * main - env vs envp
 * @argc: argument
 * @argv: array
 *@envp: environment
 *Return: 0
 */

int main(int argc, char *argv[], char *envp[])
{
	printf("Address of envp (main parameter): %p\n", (void *)envp);
	printf("Address pf environ (global variable): %p\n", (void *)environ);

	if (envp == environ)
	{
		printf("envp and environ point to the same location.\n");
	}
	else
	{
		printf("envp and environ point to different locationd.\n");
	}

	return (0);
}

