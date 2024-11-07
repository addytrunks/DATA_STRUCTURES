#include <stdio.h>

#define MAX_QUEUE_SIZE 100

// Define a structure for queue to simulate the round robin process queue
struct Queue
{
    int items[MAX_QUEUE_SIZE];
    int front;
    int rear;
};

// Function declarations
void initialize_queue(struct Queue *q);
int is_empty(struct Queue *q);
void enqueue(struct Queue *q, int process_index);
int dequeue(struct Queue *q);
int is_in_queue(struct Queue *q, int process_index);

// Function to initialize the queue
void initialize_queue(struct Queue *q)
{
    q->front = -1;
    q->rear = -1;
}

// Function to check if the queue is empty
int is_empty(struct Queue *q)
{
    return q->front == -1;
}

// Function to add an item to the queue (enqueue)
void enqueue(struct Queue *q, int process_index)
{
    if (q->rear == MAX_QUEUE_SIZE - 1)
    {
        printf("Queue is full\n");
        return;
    }
    if (q->front == -1)
    {
        q->front = 0;
    }
    q->rear++;
    q->items[q->rear] = process_index;
}

// Function to remove an item from the queue (dequeue)
int dequeue(struct Queue *q)
{
    if (is_empty(q))
    {
        printf("Queue is empty\n");
        return -1;
    }
    int process_index = q->items[q->front];
    q->front++;
    if (q->front > q->rear)
    {
        q->front = q->rear = -1; // Reset queue when empty
    }
    return process_index;
}

// Function to check if a process is already in the queue
int is_in_queue(struct Queue *q, int process_index)
{
    if (q->front == -1)
        return 0;
    for (int i = q->front; i <= q->rear; i++)
    {
        if (q->items[i] == process_index)
        {
            return 1;
        }
    }
    return 0;
}