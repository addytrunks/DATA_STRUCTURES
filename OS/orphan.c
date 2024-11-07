#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main()
{
    pid_t pid = fork();

    if (pid < 0)
    { // Error handling for fork failure
        perror("fork failed");
        exit(1);
    }

    if (pid == 0)
    { // Child process
        printf("Child process (PID: %d) is running and will sleep for 5 seconds.\n", getpid());
        sleep(5); // Sleep to simulate a delay, making it an orphan, meanwhile the parent process finished execution
        printf("Child process (PID: %d) is now adopted by init after parent exit.\n", getpid());
    }
    else
    { // Parent process
        printf("Parent process (PID: %d) is exiting now.\n", getpid());
        exit(0); // Parent process exits immediately
    }

    return 0;
}
