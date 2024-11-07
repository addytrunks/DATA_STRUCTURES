#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main() {
    pid_t pid = fork();

    if (pid < 0) {  // Error handling for fork failure
        perror("fork failed");
        exit(1);
    }
    
    if (pid == 0) {  // Child process
        printf("Child process (PID: %d) is running and will now exit.\n", getpid());
        exit(0);  // Child process exits
    } else {  // Parent process
        printf("Parent process (PID: %d) did not wait for the child.\n", getpid());
        printf("Child process should now be a zombie.\n");
        
        // Sleep for 10 seconds to keep the parent process alive
        sleep(10);
        
        printf("Parent process is done sleeping. Now exiting.\n");
    }
    
    return 0;
}
