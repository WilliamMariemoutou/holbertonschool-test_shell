#include <stdio.h>

int main(int ac, char **av)
{
	int i = 0;

	(void)ac;

	while (av[i] != NULL)
	{
		printf("Argument %d: %s\n", i, av[i]);
	i++;
	}

return (0);
}
