#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
    // Step 1: Create a shared memory segment
    int shm_id = shmget(IPC_PRIVATE, sizeof(int), IPC_CREAT | 0666);
    if (shm_id < 0)
    {
        perror("Failed to create shared memory");
        exit(1);
    }

    // Step 2: Attach the shared memory segment to parent process's address space
    int *shared_mem = (int *)shmat(shm_id, NULL, 0);
    if (shared_mem == (int *)-1)
    {
        perror("Failed to attach shared memory");
        exit(1);
    }

    // Initialize shared memory value to 0
    *shared_mem = 0;
    printf("Initial value in shared memory: %d\n", *shared_mem);

    // Step 3: Create a child process
    pid_t pid = fork();
    if (pid < 0)
    {
        perror("Failed to fork");
        exit(1);
    }

    if (pid == 0)
    { // Child process
        // Step 4: Child reads, modifies, and writes to shared memory
        *shared_mem += 10; // Increment shared memory value by 10
        printf("Child process modified shared memory to: %d\n", *shared_mem);
        shmdt(shared_mem); // Detach shared memory in child process
        exit(0);
    }
    // Parent process
    else
    {
        wait(NULL); // Step 5: Wait for the child process to finish
        printf("Parent process reads shared memory: %d\n", *shared_mem);

        // Step 6: Detach and remove shared memory
        shmdt(shared_mem);              // Detach shared memory in parent process
        shmctl(shm_id, IPC_RMID, NULL); // Remove shared memory segment
    }

    return 0;
}
