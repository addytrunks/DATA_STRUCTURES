#include <stdio.h>
#include <stdlib.h>
#include "q2.stack.h"

int isOperator(char ch)
{
    if (ch == '+' || ch == '-' || ch == '*' || ch == '/')
    {
        return 1;
    }
    return 0;
}

class BinaryTree
{
    struct Node *root;

public:
    int constructedTree;
    BinaryTree()
    {
        root = NULL;
        constructedTree = 0;
    }

    void constructExpressionTree(char *);
    void preOrder(struct Node *);
    void postOrder(struct Node *);
    void inOrder(struct Node *);
    struct Node *getRoot()
    {
        return root;
    };
};


void BinaryTree::constructExpressionTree(char *expression)
{
    struct Node *newNode;
    Stack stack;
    for (int i = 0; expression[i] != '\0'; i++)
    {
        if (isOperator(expression[i]) == 0)
        {
            newNode = (struct Node *)malloc(sizeof(struct Node));
            newNode->data = expression[i];
            newNode->left = NULL;
            newNode->right = NULL;
            stack.push(newNode);
        }
        else
        {
            newNode = (struct Node *)malloc(sizeof(struct Node));
            newNode->data = expression[i];
            newNode->right = stack.pop();
            newNode->left = stack.pop();
            stack.push(newNode);
        }
    }
    root = stack.pop();
    constructedTree = 1;
}

void BinaryTree::preOrder(struct Node *root)
{
    if (root == NULL)
    {
        return;
    }
    printf("%c ", root->data); 
    preOrder(root->left);
    preOrder(root->right);
}

void BinaryTree::postOrder(struct Node *root)
{
    if (root == NULL)
    {
        return;
    }
    postOrder(root->left);
    postOrder(root->right);
    printf("%c ", root->data); 
}

void BinaryTree::inOrder(struct Node *root)
{
    if (root == NULL)
    {
        return;
    }
    inOrder(root->left);
    printf("%c ", root->data); 
    inOrder(root->right);
}

