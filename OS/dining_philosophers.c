#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

#define N 5 // Number of philosophers

sem_t chopsticks[N]; // Semaphore array for each chopstick
sem_t mutex;         // Semaphore to limit number of philosophers at table

void *philosopher(void *num)
{
    int id = *(int *)num;

    // Philosopher action cycle
    while (1)
    {
        printf("Philosopher %d is thinking.\n", id + 1);
        sleep(1);

        // Limit the number of philosophers picking up chopsticks to N-1
        sem_wait(&mutex);

        // Pick up left and right chopsticks (ensuring both are available)
        sem_wait(&chopsticks[id]);           // Pick up left chopstick
        sem_wait(&chopsticks[(id + 1) % N]); // Pick up right chopstick

        // Eating
        printf("Philosopher %d is eating.\n", id + 1);
        sleep(2);

        // Put down both chopsticks
        sem_post(&chopsticks[id]);           // Put down left chopstick
        sem_post(&chopsticks[(id + 1) % N]); // Put down right chopstick

        // Leave the table
        sem_post(&mutex);

        printf("Philosopher %d finished eating and is thinking again.\n", id + 1);
        sleep(1);
    }
}

int main()
{
    int i;
    pthread_t thread_id[N];
    int philosopher_ids[N];

    // Initialize semaphores
    sem_init(&mutex, 0, N - 1); // Only allow N-1 philosophers at a time to prevent deadlock
    for (i = 0; i < N; i++)
    {
        sem_init(&chopsticks[i], 0, 1);
    }

    // Create philosopher threads
    for (i = 0; i < N; i++)
    {
        philosopher_ids[i] = i;
        pthread_create(&thread_id[i], NULL, philosopher, &philosopher_ids[i]);
    }

    // Wait for threads to finish
    for (i = 0; i < N; i++)
    {
        pthread_join(thread_id[i], NULL);
    }

    // Destroy semaphores
    for (i = 0; i < N; i++)
    {
        sem_destroy(&chopsticks[i]);
    }
    sem_destroy(&mutex);

    return 0;
}
