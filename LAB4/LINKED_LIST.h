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

    void display()
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

    void insertAscending(int data)
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
            while (q->data < data && q!=NULL)
            {
                p = p->next;
                q = q->next;
            }
            p->next = new_node;
            new_node->next = q;
        }
    }

    void mergeLists(LinkedList l1, LinkedList l2)
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
};