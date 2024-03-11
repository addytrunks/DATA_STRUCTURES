// Program to implement Queue using Linked List ADT

#include <stdio.h>
#include <stdlib.h>
#define SIZE 5

struct Node{
    int data;
    struct Node *next;
};

class Queue_LL
{
    struct Node *head;
    struct Node *tail;  

public:
    Queue_LL()
    {
        head = NULL;
        tail = NULL;
    }
    void enqueue(int);
    int dequeue();
    int peek();
};

int main()
{
    Queue_LL queue;
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
void Queue_LL::enqueue(int data){
    struct Node *new_node;
    new_node = (struct Node *)malloc(sizeof(struct Node));
    new_node->data = data;
    if(head == NULL){
        head = new_node;
        tail = new_node;
    }else if(head->next == NULL){
        head->next = new_node;
        tail = new_node;
    }else{
        tail->next = new_node;
        tail = new_node;
    }
    printf("Number added to the queue\n");
}

// Method to remove/dequeue an element from the queue: O(1)
int Queue_LL::dequeue(){
    struct Node *temp = head;
    int data;
    if(head == NULL){
        printf("Empty Queue,nothing to delete\n");
        return -1;
    }else{
        data = head->data;
        head = head->next;
        free(temp);
        printf("%d is the character that  left now\n", data);
        return data;
    }
}

// Method to display the element that can leave the queue: O(1)
int Queue_LL::peek()
{
    if (head == NULL) // Check if queue is empty
    {
        printf("Empty Queue,nothing to display\n");
        return -1;
    }
    else
    {
        printf("%d is the character that can leave now\n", head->data); // Display and increment front
        return head->data;
    }
}