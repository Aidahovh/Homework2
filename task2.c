#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main()
{
    pid_t pid1 = fork();

    if (pid1 == -1) {
        perror("fork");
        return 1;
    }

    if (pid1 == 0) { 
        int ret = execl("/bin/ls", "ls", NULL);
        if (ret == -1)
            perror("execl");
        return 1;
    }

    wait(NULL); 

    pid_t pid2 = fork();

    if (pid2 == -1) {
        perror("fork");
        return 1;
    }

    if (pid2 == 0) { 
        int ret = execl("/bin/date", "date", NULL);
        if (ret == -1)
            perror("execl");
        return 1;
    }

    wait(NULL); 

    printf("Parent process done\n");
    return 0;
}
