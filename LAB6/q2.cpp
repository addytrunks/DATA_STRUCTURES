#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "stack.h"

class InfixToPostFix
{
private:
    Stack operator_stack;
    Stack number_stack;
    int size;
    char *array;

    int precedence(char op)
    {
        if (op == '+' || op == '-')
        {
            return 1;
        }
        else if (op == '*' || op == '/' || op == '%')
        {
            return 2;
        }
        else if (op == '=')
        {
            return 0; // Lower precedence for '=' to handle right-to-left associativity
        }
        else
        {
            return -1; // Assume other characters have lowest precedence
        }
    };

    int isOperator(char op)
    {
        return (op == '+' || op == '-' || op == '*' || op == '/' || op == '%' || op == '=');
    };

public:
    InfixToPostFix(int initialSize = 20)
    {
        size = initialSize;
        array = (char *)malloc(size * sizeof(char));
    }

    char *infixToPostfix(char *infix)
    {
        int index = 0;
        for (int i = 0; infix[i] != '\0'; i++)
        {
            if (index >= size)
            {
                size *= 2;
                array = (char *)realloc(array, size * sizeof(char)); // Resize array
            }

            if (!isOperator(infix[i]))
            {
                array[index++] = infix[i];
            }
            else
            {
                while (!operator_stack.isEmpty() && precedence(infix[i]) <= precedence(operator_stack.peek()))
                {
                    array[index++] = operator_stack.pop();
                }
                operator_stack.push(infix[i]);
            }
        }
        while (!operator_stack.isEmpty())
        {
            array[index++] = operator_stack.pop();
        }
        array[index] = '\0';

        return array;
    }

    int evaluatePostfix(char *postfix)
    {
        int result;
        int op1, op2;

        for (int i = 0; postfix[i] != '\0'; i++)
        {
            if (isdigit(postfix[i]))
            {
                number_stack.push(postfix[i] - '0');
            }
            else if (isOperator(postfix[i]))
            {
                op2 = number_stack.pop();
                op1 = number_stack.pop();

                switch (postfix[i])
                {
                case '+':
                    result = op1 + op2;
                    break;
                case '-':
                    result = op1 - op2;
                    break;
                case '*':
                    result = op1 * op2;
                    break;
                case '/':
                    result = op1 / op2;
                    break;
                case '%':
                    result = op1 % op2;
                    break;
                }

                number_stack.push(result);
            }
        }

        return number_stack.pop();
    }
};
int main()
{
    InfixToPostFix convert;
    char infix[100];
    char *postfix;
    int choice;

    while (1)
    {
        printf("Menu\n1.Get Infix\n2.Convert Infix\n3.Evaluate Postfix\n4.Exit\nEnter your choice:");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter infix expression: ");
            scanf("%s", infix);
            break;
        case 2:
            if (strlen(infix) > 0)
            {
                postfix = convert.infixToPostfix(infix);
                printf("%s\n", postfix);
            }
            else
            {
                printf("No infix expression found.Click on choice 1 to enter the expression.\n");
            }
            break;
        case 3:
            if (strlen(infix) > 0)
            {
                printf("%d is the final answer after evaluation of %s\n", convert.evaluatePostfix(postfix), postfix);
                break;
            }
            else
            {
                printf("No postfix expression found.Click on choice  2 to convert the infix to postfix,\n");
            }
        case 4:
            exit(1);
            break;
        default:
            printf("Enter a valid choice.");
        }
    }

    return 0;
}
