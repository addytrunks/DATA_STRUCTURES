// Program to implement stack ADT using array

#include <stdio.h>
#include <stdlib.h>
#define SIZE 5
class Stack_Array
{
    char arr[SIZE];
    int cur;

public:
    Stack_Array()
    {
        cur = -1;
    }
    int push(char);
    int pop();
    int peek();
};

int main()
{
    Stack_Array l1;
    int choice;
    char data;
    while (1)
    {
        printf("\n\t1.Push\n\t2.Pop\n\t3.Peek\n\t4.Exit\nEnter your choice:");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("\nEnter the character that needs to be inserted:");
            scanf(" %c", &data);
            l1.push(data);
            break;
        case 2:
            l1.pop();
            break;
        case 3:
            l1.peek();
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

// Method to push/add a character to a stack: O(1)
int Stack_Array::push(char character)
{
    if (cur == SIZE - 1)
    {
        printf("\nStack is already full");
        return 0;
    }
    else
    {
        arr[++cur] = character;
        printf("%c has been inserted successfully into the stack", character);
        return 1;
    }
}

// Method to pop/remove a character from a stack: O(1)
int Stack_Array::pop()
{
    if (cur == -1)
    {
        printf("\nStack is empty");
        return 0;
    }
    else
    {
        char temp = arr[cur--];
        printf("\nTop most element has been popped successfully");
        printf("\nPopped element:%c", temp);
        return 1;
    }
}

// Method to display the top most character of a stack: O(1)
int Stack_Array::peek()
{
    if (cur == -1)
    {
        printf("\nNothing to peek");
        return 0;
    }
    else
    {
        printf("\nTop of the stack:%c", arr[cur]);
        return 1;
    }
}