#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

#define BUFFER_SIZE 5

// Shared buffer and counter
int buffer[BUFFER_SIZE];
int count = 0;

// Semaphores and mutex
sem_t empty;
sem_t full;
pthread_mutex_t mutex;

// Producer function
void *producer(void *param)
{
    int item;
    while (1)
    {
        // Produce an item
        item = rand() % 100; // Random number as item
        sleep(1);            // Simulate time to produce

        // Wait until there is space in the buffer
        sem_wait(&empty);
        // Lock the buffer
        pthread_mutex_lock(&mutex);

        // Add item to the buffer
        buffer[count] = item;
        printf("Producer produced: %d\n", item);
        count++;

        // Unlock the buffer
        pthread_mutex_unlock(&mutex);
        // Signal that there is a new item in the buffer
        sem_post(&full);
    }
}

// Consumer function
void *consumer(void *param)
{
    int item;
    while (1)
    {
        // Wait until there is at least one item in the buffer
        sem_wait(&full);
        // Lock the buffer
        pthread_mutex_lock(&mutex);

        // Remove item from the buffer
        count--;
        item = buffer[count];
        printf("Consumer consumed: %d\n", item);

        // Unlock the buffer
        pthread_mutex_unlock(&mutex);
        // Signal that there is space in the buffer
        sem_post(&empty);

        sleep(1); // Simulate time to consume
    }
}

int main()
{
    pthread_t prod, cons;

    // Initialize the semaphores and mutex
    sem_init(&empty, 0, BUFFER_SIZE);
    sem_init(&full, 0, 0);
    pthread_mutex_init(&mutex, NULL);

    // Create producer and consumer threads
    pthread_create(&prod, NULL, producer, NULL);
    pthread_create(&cons, NULL, consumer, NULL);

    // Wait for the threads to finish (they actually won't in this case)
    pthread_join(prod, NULL);
    pthread_join(cons, NULL);

    // Cleanup (not reachable in this infinite example, but good practice)
    sem_destroy(&empty);
    sem_destroy(&full);
    pthread_mutex_destroy(&mutex);

    return 0;
}
