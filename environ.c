#include <stdio.h>
#include <unistd.h>

exxtern char **environ;

int main(void)
{
	int i = 0;

	while (environ[i] != NULL)
	{
		printf("%s\n", environ[i]);
		i++;
	}

	return (0);
}
