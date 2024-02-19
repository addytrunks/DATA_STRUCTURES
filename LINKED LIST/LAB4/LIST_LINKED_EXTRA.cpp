#include <stdio.h>
#include "LINKED_LIST.h"

int main()
{
    LinkedList l1, l2,l3;
    int choice, num,l_choice;

    while (1)
    {
        printf("\nEnter \n1. Insert List 1\n2. Insert List 2\n3.Merge into List 3\n4.Display\n5.Exit\n6.Insert beg.\n7.Insert End.");
        printf("\n Enter a choice:");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("\nInsertion into List1\n");
            printf("Enter the number:");
            scanf("%d", &num);
            l1.insertAscending(num);
            break;
        case 2:
            printf("\nInsertion into List2\n");
            printf("Enter the number:");
            scanf("%d", &num);
            l2.insertAscending(num);
            break;
        case 3:
            printf("\nMerged contents of List 1 and List 2 into List 3.\n");
            l3.mergeLists(l1,l2);
            break;
        case 4:
            printf("\nChoose what list you want to display:(1/2/3):\n");
            scanf("%d",&l_choice);

            if(l_choice == 1){
                l1.display();
            }else if(l_choice == 2){
                l2.display();
            }else if(l_choice == 3){
                l3.display();
            }
            break;
        case 5:
            exit(1);
            break;
        default:
            printf("\nEnter a valid choice.\n");
            break;
        }
    }
    return 0;
}