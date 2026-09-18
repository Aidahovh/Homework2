#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main()
{
    pid_t pid = fork();

    if (pid == -1) {
        perror("fork");
        return 1;
    }

    if (pid == 0) { // child process
        int ret = execl("/bin/ls", "ls", NULL);
        if (ret == -1)
            perror("execl");
        return 1;
    } else { // parent process
        wait(NULL);
        printf("Parent process done\n");
    }

    return 0;
}
