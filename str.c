#include <stdio.h>
#include <string.h>

/**
 * main - strtok
 *
 * Return: 0
 */
int main(void)
{
	char str[] = "Shell coding is a pain in the ahh";
	char *token;

	token = strtok(str, " ");

	while (token != NULL)
	{
		printf("%s\n", token);
		token = strtok(NULL, " ");
	}

	return (0);
}
