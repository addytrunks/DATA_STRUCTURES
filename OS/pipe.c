#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>

int main() {
    int fd[2]; // File descriptors for the pipe
    pid_t pid;
    char message[] = "Hello from parent process!";
    char buffer[100];

    // Step 2: Create a pipe
    if (pipe(fd) == -1) {
        perror("Pipe creation failed");
        return 1;
    }

    // Step 3: Create a child process
    pid = fork();
    if (pid < 0) {
        perror("Fork failed");
        return 1;
    }

    if (pid > 0) { 
        // Parent Process
        close(fd[0]);  // Step 4: Close read end of the pipe
        write(fd[1], message, strlen(message) + 1);  // Write message to the pipe
        close(fd[1]);  // Close write end of the pipe after writing
        printf("Parent process: Sent message to child\n");
    } else { 
        // Child Process
        close(fd[1]);  // Step 5: Close write end of the pipe
        read(fd[0], buffer, sizeof(buffer));  // Read message from the pipe
        printf("Child process: Received message - %s\n", buffer);  // Print message
        close(fd[0]);  // Close read end of the pipe after reading
    }

    return 0;
}
