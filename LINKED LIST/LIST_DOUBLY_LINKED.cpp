// Implementation of Doubly Linked List ADT.
// NOTE: The terms node and element will be used interchangeably.

#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *next;
    struct Node *prev;
};

class DoublyLinkedList{

    // Reference to the top-most/first element of the list.
    struct Node *head;
    public:
        DoublyLinkedList(){
            head = NULL;
        }
        
        int count_nodes(); // O(n)
        void display(); // O(n)

        void insert_beg(int); // O(1)
        void insert_end(int); // O(n)
        void insert_pos(int,int); // O(n)

        int del_beg(); // O(1)
        int del_end(); // O(n)
        int del_pos(int); // O(n)

        void search(int); // O(n)
};

int main(){
    DoublyLinkedList l1;
    int choice, num, pos,ret_del;

    while (1)
    {
        printf("\nEnter \n1. Insert Begin\n2. Insert End\n3. Insert Position");
        printf("\n4. Delete Begin\n5. Delete End\n6. Delete Position");
        printf("\n7. Search\n8. Display\n9.Exit");
        printf("\n Enter a choice:");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                printf("Enter an element to insert at the beginning:");
                scanf("%d", &num);
                l1.insert_beg(num);
                printf("Element has been inserted at the beginning.\n");
                break;
            case 2:
                printf("Enter an element to insert at the end:");
                scanf("%d", &num);
                l1.insert_end(num);
                printf("Element has been inserted at the end.\n");
                break;
            case 3:
                printf("Enter an element to insert:");
                scanf("%d", &num);
                printf("\n Enter the position at which you want to insert:");
                scanf("%d", &pos);
                l1.insert_pos(num, pos);
                printf("Element has been inserted at the given position.\n");
                break;
            case 4:
                ret_del = l1.del_beg();

                if(ret_del == -1){
                    printf("Empty List. Cannot perform delete operation.");
                }else{
                    printf("The element %d has been deleted from the list.",ret_del);
                }
                break;
            case 5:
                ret_del = l1.del_end();

                if(ret_del == -1){
                    printf("Empty List. Cannot perform delete operation.");
                }else{
                    printf("The element %d has been deleted from the list.",ret_del);
                }
                break;
            case 6:
                 printf("Enter the position you want to delete:");
                 scanf("%d",&pos);
                 ret_del = l1.del_pos(pos);

                if(ret_del == -1){
                    printf("Empty List. Cannot perform delete operation.");
                }else if(ret_del == -2){
                    printf("Invalid position given.");
                }else{
                    printf("The element %d has been deleted from the list.",ret_del);
                }
                break;
                break;
            case 7:
                printf("Enter the element you want to search for:");
                scanf("%d",&num);
                l1.search(num);
                break;
            case 8:
                l1.display();
                break;
            case 9:
                exit(1);
                break;
            default:
                printf("Enter a valid choice:");
                break;
        }
    }
}

// Method to count the number of elements in the list.
int DoublyLinkedList::count_nodes()
{
    int count = 0;
    struct Node *temp;
    temp = head;
    while (temp != NULL)
    {
        count += 1;
        temp = temp->next;
    }

    return count;
}

// Method to display the elements of the list in forward and reverse order.
void DoublyLinkedList::display()
{
    if (head == NULL)
    {
        printf("Empty List.Nothing to display.\n");
    }
    else
    {
        struct Node *temp = head;

        printf("Display Forward:\n");

        // reason as to why not temp!=NULL, access to the last element will be lost.
        while (temp->next != NULL)
        {
            printf("%d <=> ", temp->data);
            temp = temp->next;
        }
        printf("%d <=> \n", temp->data);

        printf("Display reverse:\n");
        while(temp != NULL){
            printf("%d <=>",temp->data);
            temp = temp->prev;
        }
    }
}

// Method to insert the element in the beginning of the list.
void DoublyLinkedList::insert_beg(int data)
{
    // Allocating memory for the new element/node to be inserted.
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

// Method to insert the element in the end of the list.
void DoublyLinkedList::insert_end(int data)
{

    if (head == NULL)
    {
        insert_beg(data);
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

// Method to insert the element in the given position (user input) of the list.
void DoublyLinkedList::insert_pos(int data, int pos)
{
    if (head == NULL)
    {
        insert_beg(data);
    }
    else if (pos == count_nodes() + 1)
    {
        insert_end(data);
    }
    else if (pos < 0 || pos > count_nodes() + 1)
    {
        printf("Invalid Position.\n");
    }
    else
    {
        struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
        new_node->data = data;
        struct Node *temp;

        temp = head;

        // Iterating the list till the temporary pointer lands on a position i.e one less than the given position.
        for (int i = 1; i < pos - 1; i++)
        {
            temp = temp->next;
        }

        new_node->next = temp->next;
        temp->next->prev = new_node;
        temp->next = new_node;
        new_node->prev = temp;
    }
}

// Method to delete the element in the beginning of the list.
int DoublyLinkedList::del_beg()
{
    if (head == NULL)
    {
        return -1;
    }
    // If only one element exist
    else if (head->next == NULL)
    {
        int data = head->data;
        head = NULL;
        free(head);
        return data;
    }
    else
    {
        struct Node *temp = head;
        int data = head->data;
        head = head->next;
        head->prev = NULL;
        free(temp);
        return data;
    }
}

// Method to delete the element in the end of the list.
int DoublyLinkedList::del_end(){
    if (head == NULL)
    {
        return -1;
    }// If only one element exist
    else if (head->next == NULL)
    {
        int data = head->data;
        head = NULL;
        free(head);
        return data;
    }else{
        struct Node *p,*q;
        p = head;
        q = head->next;
        while(q->next!=NULL){
            q = q->next;
            p = p->next;
        }
        int data = q->data;
        q->prev = NULL;
        p->next = NULL;
        free(q);
        return data;
    }
}

// Method to delete the element in the given position (user input) of the list.
int DoublyLinkedList::del_pos(int pos){
    if(head == NULL){
        return -1;
    }else if(pos<0 || pos > count_nodes()+1){
        return -2;
    }else if(pos == 0){
        return del_beg();
    }else if(pos == count_nodes() + 1){
        return del_end();
    }else{
        struct Node *p,*q;
        p = head;
        q = head->next;
        // Iterating the list till the temporary pointer lands on a position i.e one less than the given position.
        for(int i = 1; i<pos-1;i++){
            p = p->next;
            q = q->next;
        }
        int data = q->data;
        p->next = q->next;
        q->next->prev = p;
        free(q);
        return data;
    }
}

// Method to search for the given element (user input) in the list.
void DoublyLinkedList::search(int num){
    struct Node *temp = head;
    int pos = 1;
    int found = 0;
    while(temp!=NULL){
        if(temp->data == num){
            printf("%d has been found at position no %d.",num,pos);
            found = 1;
            break;
        }
        temp = temp->next;
        pos++;
    }

    if(found == 0){
        printf("The given element doesn't exist.");
    }
}