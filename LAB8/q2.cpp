#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "q2.h"

int main() {
    
    int choice;
    char expression[100];
    BinaryTree tree;
    while(1){
        printf("\n1.Postfix Expression\n2.Construct Expression Tree\n3.Pre Order\n4.Post Order\n5.In Order\n6.Exit\nEnter your choice:");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                printf("Enter the postfix expression: ");
                scanf(" %s", &expression);
                break;
            case 2:
                if(strlen(expression) == 0){
                    printf("Please enter the postfix expression first\n");
                    break;
                }else{
                    tree.constructExpressionTree(expression);
                    printf("Expression Tree Constructed\n");
                    break;
                }
            case 3:
                if(tree.constructedTree == 0){
                    printf("Please construct the expression tree first\n");
                    break;
                }else{
                    printf("Pre Order: ");
                    tree.preOrder(tree.getRoot());
                    break;
                }
            case 4:
                if(tree.constructedTree == 0){
                    printf("Please construct the expression tree first\n");
                    break;
                }else{
                    printf("Post Order: ");
                    tree.postOrder(tree.getRoot());
                    break;
                }
            case 5:
                if(tree.constructedTree == 0){
                    printf("Please construct the expression tree first\n");
                    break;
                }else{
                    printf("In Order: ");
                    tree.inOrder(tree.getRoot());
                    break;
                }
            case 6:
                return 0;
                exit(1);
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}
