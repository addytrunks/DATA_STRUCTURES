#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

class LinkedList
{
    struct Node *head;

public:
    LinkedList()
    {
        head = NULL;
    }

    struct Node *getHead()
    {
        return head;
    }

    // O(n)
    void insertAscending(int);
    // O(n)
    void mergeLists(LinkedList, LinkedList);
    // O(n)
    void display();
};

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


void LinkedList::display()
{
    if (head == NULL)
    {
        printf("Empty list,nothing to display.");
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

void LinkedList::insertAscending(int data)
{
    struct Node *new_node, *p, *q;
    new_node = (struct Node *)malloc(sizeof(struct Node));
    new_node->data = data;

    // Insert @ beginning if the given data is less than the head data
    if (!head || head->data >= data)
    {
        new_node->next = head;
        head = new_node;
    }
    else
    {
        p = head;
        q = head->next;
        while (q != NULL && q->data < data)
        {
            p = p->next;
            q = q->next;
        }
        p->next = new_node;
        new_node->next = q;
    }
}

void LinkedList::mergeLists(LinkedList l1, LinkedList l2)
{
    struct Node *temp1 = l1.getHead();
    struct Node *temp2 = l2.getHead();

    if (temp1 == NULL && temp2 == NULL)
    {
        printf("Empty lists, nothing to be merged.");
    }
    else
    {
        while (temp1 && temp2)
        {
            if (temp1->data < temp2->data)
            {
                insertAscending(temp1->data);
                temp1 = temp1->next;
            }
            else
            {
                insertAscending(temp2->data);
                temp2 = temp2->next;
            }
        }

        // Incase the lengths of the lists are not equal, the remaining will be added as it is.
        while (temp1)
        {
            insertAscending(temp1->data);
            temp1 = temp1->next;
        }

        while (temp2)
        {
            insertAscending(temp2->data);
            temp2 = temp2->next;
        }
    }
}