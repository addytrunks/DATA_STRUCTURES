// Program to implement Queue ADT using Circular Linked List ADT

#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

class QueueCLL
{
    struct Node *head;
    struct Node *tail;  

public:
    QueueCLL()
    {
        head = NULL;
        tail = NULL;
    }
    void enqueue(int);
    int dequeue();
    int peek();
    int isEmpty();
};

// Method to check if the list is empty
int QueueCLL::isEmpty(){
    if(head == NULL){
        return 1;
    }else{
        return 0;
    }
}

// Method to add/enqueue an element from the queue : O(1)
void QueueCLL::enqueue(int data){
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
    tail->next = head;
}

// Method to remove/dequeue an element from the queue: O(1)
int QueueCLL::dequeue(){
    struct Node *temp = head;
    int data;
    if(head == NULL){
        return -1;
    }else{
        data = head->data;
        head = head->next;
        tail->next = head;
        free(temp);
        return data;
    }
}

// Method to display the element that can leave the queue: O(1)
int QueueCLL::peek()
{
    if (isEmpty()) // Check if queue is empty
    {
        return -1;
    }
    else
    {
        return head->data;
    }
}