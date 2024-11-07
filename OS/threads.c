#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

// Function to be executed by the thread
void *myThreadFun(void *vargp)
{
    printf("Thread isrunning...\n");
    sleep(5); // Simulate thread execution
    return NULL;
}
int main()
{
    pthread_t thread_id;
    printf("Before Thread\n");
    pthread_create(&thread_id, NULL, myThreadFun, NULL);

    // Waiting for the thread to complete
    pthread_join(thread_id, NULL);
    printf("After Thread\n");
    exit(0);
}