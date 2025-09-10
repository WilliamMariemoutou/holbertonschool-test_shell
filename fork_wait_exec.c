#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

/**
 * main - execute, fork wait
 *
 * Return: 0
 */
int main(void)
{
	int i;
	pid_t pid;
	int status;

	for (i = 0; i < 5; i++)
	{
		pid = fork();

		if (pid == 1)
		{
			perror("fork failed");
			exit(EXIT_FAILURE);
		}
		else if (pid == 0)
		{
			printf("Child %d (PID: %d) executing 'ls -l /tmp'...\n", i + 1, getpid());

			execlp("ls", "ls", "-1", "/tmp", (char *)NULL);
			perror("execlp failed");
			exit(EXIT_FAILURE);
		}
		else
		{
			waitpid(pid, &status, 0);
			printf("Parent (PID: %d) detected child %d (PID: %d) ",
					getpid(), i + 1, pid);
			printf("exited with status %d.\n", WEXITSTATUS(status));
		}
	}

	return (0);
}
