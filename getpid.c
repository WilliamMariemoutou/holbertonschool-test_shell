#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

/**
 * main - PID
 *
 * Return: Always 0
 */
int main(void)
{
	pid_t my_pid = getpid();
	pid_t my_ppid = getppid();


	printf("The pid of the current process is: %d\n", my_pid);
	printf("The pid of the current process is: %d\n", my_ppid);
	return (0);
}
