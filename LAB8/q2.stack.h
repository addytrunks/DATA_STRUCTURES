// Header File to implement stack ADT

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    char data;
    struct Node *left;
    struct Node *right;
};

struct StackNode{
    struct Node *treeNode;
    struct StackNode *next;
};

class Stack
{
    struct StackNode *top;

public:
    Stack()
    {
        top = NULL;
    }
    void push(struct Node *);
    struct Node *pop(){
        if (isEmpty() == 1)
        {
            printf("\nUnderflow error!");
            return NULL;    
        }
        else
        {
            struct StackNode *temp = top;
            top = top->next;
            struct Node *poppedNode = temp->treeNode;
            free(temp);
            return poppedNode;
        }
    };
    int isEmpty();
};

// Method to push/add a character to a stack: O(1)
void Stack::push(struct Node *node)
{
    struct StackNode *newNode = (struct StackNode *)malloc(sizeof(struct StackNode));
    newNode->treeNode = node;
    newNode->next = top;
    top = newNode;
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