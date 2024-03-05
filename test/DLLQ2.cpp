#include<stdio.h>
#include "DLLQ2.h"
int main(){
    int choice,num;
    WebPage W1;
    while(1){
        getchar();
        getchar();
        system("cls");
        printf("\n\t1.New Webpage\n\t2.Move Front\n\t3.Move Back\n\t4.Display Information of current page\n\t5.Exit");
        printf("\nEnter your choice:");
        scanf("%d",&choice);
        switch (choice){
            case (1):
                printf("\nEnter the data of the new web page:");
                scanf("%d",&num);
                W1.New_Web_Page(num);
                break;
            case (2):
                W1.Front();
                break;
            case (3):
                W1.Back();
                break;
            case (4):
                W1.Display_Current_Page();
                break;
            case (5):
                printf("\nQUITING THE PROGRAM!!!");
                exit(0);
                break;
            default:
                printf("\nPlease enter a valid choice");
                break;
        }
    }
    return 0;
}