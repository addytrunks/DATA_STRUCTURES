#include <stdio.h>
#include <stdlib.h>
#define SIZE 5

class Queue_Array
{
    char *arr;
    int front, rear;

public:
    Queue_Array()
    {
        arr = (char *)malloc(SIZE * sizeof(char));
        front = -1;
        rear = -1;
    }
    void enqueue(char);
    char dequeue();
    void display();
};

int main()
{
    Queue_Array l1;
    int choice;
    char data;
    while (1)
    {
        printf("\n\t1.Enqueue\n\t2.Dequeue\n\t3.Display\n\t4.Exit\nEnter your choice:");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("\nEnter the character that needs to be inserted:");
            scanf(" %c", &data);
            l1.enqueue(data);
            break;
        case 2:
            l1.dequeue();
            break;
        case 3:
            l1.display();
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

void Queue_Array::enqueue(char character)
{
    if((rear+1)%SIZE == front || (front == -1 && rear == SIZE-1) ){ // full condition
        printf("Size Full.Cannot Add.");
    }else{
        rear = (rear+1)%SIZE;
        arr[rear] = character;
        printf("Character added to the queue\n");
    }
}

char Queue_Array::dequeue(){ 
     if (front == rear)  // Check if queue is empty
    {
        printf("Empty Queue,nothing to display\n");
        return '0';
    }else{
        front = (front+1)%SIZE;
        printf("%c is the character that  left now\n", arr[front]);
        return arr[front];
    }
}

void Queue_Array::display()
{
    if (front == rear) // Check if queue is empty
    {
        printf("Empty Queue,nothing to display\n");
    }
    else
    {
        printf("%c is the character that can leave now\n", arr[front+1]); // Display and increment front
    }
}
