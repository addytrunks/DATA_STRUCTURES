// Program to implement circular queue using list ADT

#include <stdio.h>
#include <stdlib.h>
#define SIZE 5

class CircularQueue_Array
{
    int *arr;
    int front, rear;

public:
    CircularQueue_Array()
    {
        arr = (int *)malloc((SIZE) * sizeof(int));
        front = -1;
        rear = -1;
    }
    void enqueue(int);
    int dequeue();
    int peek();
};

int main()
{
    CircularQueue_Array queue;
    int choice;
    int data;
    while (1)
    {
        printf("Menu\n1.Enqueue\n2.Dequeue\n3.Peek\n4.Exit\nEnter your choice:");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("\nEnter the character that needs to be inserted:");
            scanf("%d", &data);
            queue.enqueue(data);
            break;
        case 2:
            queue.dequeue();
            break;
        case 3:
            queue.peek();
            break;
        case 4:
            exit(0);
            break;
        default:
            printf("\nEnter a valid choice");
            break;
        }
    }
    return 0;
}

// Method to add/enqueue an element from the queue : O(1)
void CircularQueue_Array::enqueue(int number)
{
    if ((front == rear+1) || (front == 0 && rear == SIZE-1)) // Check if the queue is full
    {
        printf("Size is full. Cannot add.\n");
    }
   else
    {
        if(front == -1){
            front = 0;
        }
        rear = (rear+1)%SIZE;
        arr[rear] = number;
        printf("Number added to the queue\n");
    }
}

// Method to remove/dequeue an element from the queue: O(1)
int CircularQueue_Array::dequeue(){
    if (front == -1)  // Check if queue is empty
    {
        printf("Empty Queue,nothing to delete\n");
        return -1;
    }else{
        int data = arr[front];
        if(front == rear){
            front = -1;
            rear = -1;
        }else{
            front = (front+1)%SIZE;
        }
        printf("%d is the number that  left now\n", data);
        return data;
    }
}

// Method to display the element that can leave the queue: O(1)
int CircularQueue_Array::peek()
{
    if (front == -1) // Check if queue is empty
    {
        printf("Empty Queue,nothing to display\n");
        return -1;
    }
    else
    {
        printf("%d is the number that can leave now\n", arr[front]); // Display and increment front
        return arr[front];
    }
}