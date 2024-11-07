#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
// #include <sys/wait.h>

int main()
{
    pid_t pid;
    // Fork a child process
    pid = fork();
    if (pid ==
        -1)
    {
        perror("fork");
        exit(1);
    }
    if (pid == 0)
    {
        // Child process
        printf("Child process: %d\n", getpid());
        exit(0);
    }
    else
    {
        // Parent process
        wait(NULL);
        printf("Parent process: %d\n", getpid());
    }
    return 0;
}
