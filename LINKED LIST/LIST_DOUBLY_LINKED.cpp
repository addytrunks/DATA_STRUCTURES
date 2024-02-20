// implementation of doubly linked list

#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *prev;
    struct Node *next;
}

class DoublyLinkedList{
    struct Node *head;
    DoublyLinkedList(){
        head = NULL;
    }
    public:
        void insertbeg(int);
        void insertend(int);
        void insertpos(int,int);

        void display();
        void search();

        void delbeg();
        void delend();
        void delpos(int);
}

int main(){
    DoublyLinkedList l1;
    int choice, num, pos;

    while (1)
    {
        printf("\nEnter \n1. Insert Begin\n2. Insert End\n3. Insert Position");
        printf("\n4. Delete Begin\n5. Delete End\n6. Delete Position");
        printf("\n7. Search\n8. Display\n\n9.Exit");
        printf("\n Enter a choice:");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                break;
            case 5:
                break;
            case 6:
                break;
            case 7:
                break;
            case 8:
                break;
            case 9:
                exit(1);
                break;
            default:
                printf("Enter a valid choice.");
                break;
        }    
    }

    return 0;
}