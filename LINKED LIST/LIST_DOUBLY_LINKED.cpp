// implementation of doubly linked list

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *prev;
    struct Node *next;
};

class DoublyLinkedList
{
    struct Node *head;

public:
    DoublyLinkedList()
    {
        head = NULL;
    }

    int countnodes();

    void insertbeg(int);
    void insertend(int);
    void insertpos(int, int);

    void display();
    void search();

    void delbeg();
    void delend();
    void delpos(int);
};

int main()
{
    DoublyLinkedList l1;
    int choice, num, pos;

    while (1)
    {
        printf("\nEnter \n1. Insert Begin\n2. Insert End\n3. Insert Position");
        printf("\n4. Delete Begin\n5. Delete End\n6. Delete Position");
        printf("\n7. Search\n8. Display\n9.Exit");
        printf("\n Enter a choice:");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter an element to insert at the beginning:");
            scanf("%d", &num);
            l1.insertbeg(num);
            printf("Element has been inserted at the beginning.\n");
            break;
        case 2:
            printf("Enter an element to insert at the end:");
            scanf("%d", &num);
            l1.insertend(num);
            printf("Element has been inserted at the end.\n");
            break;
        case 3:
            printf("Enter an element to insert:");
            scanf("%d", &num);
            printf("\n Enter the position at which you want to insert:");
            scanf("%d", &pos);
            l1.insertpos(num,pos);
            printf("Element has been inserted at the given position.\n");
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
            l1.display();
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

int DoublyLinkedList::countnodes(){
    int count = 0;
    struct Node *temp;
    temp = head;
    while(temp!=NULL){
        count+=1;
        temp = temp->next;
    }

    return count;
}

void DoublyLinkedList::display(){
    if (head == NULL)
    {
        printf("Empty List.Nothing to display.\n");
    }
    else
    {
        struct Node *temp = head;

        while (temp != NULL)
        {
            printf("%d->", temp->data);
            temp = temp->next;
        }
    }
}

void DoublyLinkedList::insertbeg(int data)
{
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->prev = NULL;
    if (head == NULL)
    {
        new_node->next = NULL;
        head = new_node;
    }
    else
    {
        new_node->next = head;
        head->prev = new_node;
        head = new_node;
    }
}

void DoublyLinkedList::insertend(int data){

    if (head == NULL)
    {
        insertbeg(data);
    }
    else
    {
        struct Node *temp = head;
        struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        new_node->data = data;
        temp->next = new_node;
        new_node->prev = temp;
        new_node->next = NULL;
    }
}

void DoublyLinkedList::insertpos(int data,int pos){
    if(head == NULL){
        insertbeg(data);
    }else if(pos == countnodes() +1){
        insertend(data);
    }else if(pos<0 || pos>countnodes() + 1){
        printf("Invalid Position.\n");
    }
    else{
        struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
        new_node->data = data;
        struct Node *temp;

        temp = head;

        for(int i = 1;i < pos - 1;i++){
            temp = temp->next;
        }

        new_node->next = temp->next;
        temp->next->prev = new_node;
        temp->next = new_node;
        new_node->prev = temp;

    }
}