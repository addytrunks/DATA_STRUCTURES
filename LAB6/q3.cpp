#include <stdio.h>
#include "stack.h"

class Balancer
{
private:
    Stack stack;

public:
    int isBalanced(char *str)
    {
        for (int i = 0; str[i] != '\0'; i++)
        {
            if (str[i] == '(')
            {
                stack.push('(');
            }
            else if (str[i] == ')')
            {
                if (stack.isEmpty() == 1)
                {
                    return 0;
                }
                else
                {
                    stack.pop();
                }
            }
        }

        return stack.isEmpty();
    };
};

int main()
{
    Balancer balancer;
    char str[100];
    int choice;

    do
    {
        printf("\nMenu:\n1. Check Balance\n2. Exit\nEnter choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter a string of parentheses: ");
            scanf("%s", &str);
            if (balancer.isBalanced(str) == 1)
            {
                printf("The parentheses are balanced.\n");
            }
            else
            {
                printf("The parentheses are not balanced.\n");
            }
            break;
        case 2:
            printf("Exiting program.\n");
            break;
        default:
            printf("Invalid choice. Try again.\n");
        }
    } while (choice != 2);
}