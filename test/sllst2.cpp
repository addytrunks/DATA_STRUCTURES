#include<stdio.h>
#include "sllst1.h"

int main()
{
    linkedlists l1, l2, l3;
    int choice, num, listchoice;

    while(1)
    {
        printf("\n1.insert in ascending order\n2.merge two lists\n3.display\n4.exit\nenter your choice:");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                printf("\nenter the number to be inserted:");
                scanf("%d",&num);
                printf("\n1.list1\n2.list2\nenter the list in which the element is to be inserted:");
                scanf("%d",&listchoice);
                if (listchoice==1)
                {
                    l1.insertasc(num);
                }
                else if (listchoice==2)
                {
                    l2.insertasc(num);
                }
                break;
            case 2:
                l3.mergelists(l1,l2);
                break;
            case 3:
                printf("\n1.list1\n2.list2\n3.list3\nenter your choice:");
                scanf("%d",&listchoice);
                if (listchoice==1)
                {
                    l1.display();
                }
                else if (listchoice==2)
                {
                    l2.display();
                }
                else if (listchoice==3)
                {
                    l3.display();
                }
                else
                {
                    printf("invalid choice");
                }
                break;
            case 4:
                printf("the program has been exited");
                exit(0);
                break;
            default:
                printf("invalid choice");
                break;



        }   
    }

}