// Header File to implement stack ADT

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    char data;
    struct Node *next;
};

class Stack
{
    struct Node *top;

public:
    Stack()
    {
        top = NULL;
    }
    void push(char);
    char pop();
    char peek();
    int isEmpty();
    int count();
    void display();
};

// Method to push/add a character to a stack: O(1)
void Stack::push(char chr)
{
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    new_node->data = chr;
    if (top == NULL)
    {
        top = new_node;
        new_node->next = NULL;
    }
    else
    {
        new_node->next = top;
        top = new_node;
    }
}

// Method to pop/remove a character from a stack: O(1)
char Stack::pop()
{
    if (top == NULL)
    {
        printf("\nUnderflow error!");
        return 0;
    }
    else
    {
        struct Node *temp = top;
        char data = temp->data;
        top = temp->next;
        temp->next = NULL;
        return data;
    }
}

// Method to display the top most character of a stack: O(1)
char Stack::peek()
{
    if (top == NULL)
    {
        printf("\nNothing to display");
        return -1;
    }
    else
    {
        return top->data;
    }
}

// Method to check whether the stack is empty  O(1)
int Stack::isEmpty()
{
    if (top == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int Stack::count()
{
    struct Node *temp = top;
    int count = 0;
    while (temp != NULL)
    {
        count+=1;
        temp = temp->next;
    }
    return count;
}

void Stack::display()
{
    struct Node *temp;
    temp = top;

    if (top == NULL)
    {
        printf("Empty list.");
    }
    else
    {

        while (temp != NULL)
        {
            printf("%c", temp->data);
            temp = temp->next;
        }
    }
}