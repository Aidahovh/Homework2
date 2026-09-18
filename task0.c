#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main()
{
    if (fork() == -1)
        perror("fork");

    if (fork() == -1)
        perror("fork");

    if (fork() == -1)
        perror("fork");

    printf("PID = %d, PPID = %d\n", getpid(), getppid());

    while (wait(NULL) > 0);

    return 0;
}
