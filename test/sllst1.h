#include<stdio.h>
#include <stdlib.h>

class linkedlists
{
    struct node
    {
        int data;
        struct node *next;
    };

    struct node *head;

    public:
    linkedlists()
    {
        head = NULL;
    }

    struct node *gethead()
    {
        return head;
    }

    void insertasc(int num)
    {

        if (head == NULL || head->data >= num)
        {
            struct node *newnode = (struct node *)malloc(sizeof(struct node));
            newnode->data = num;
            printf("the list is empty, data added to the beginning of the list");
            newnode->next = NULL;
            head = newnode;
            
        }
        else
        {
            struct node *temp = head;
            while (temp->data < num)
            {
                temp = temp->next;
            }
            struct node *newnode = (struct node *)malloc(sizeof(struct node));
            newnode->data = num;
            newnode->next = temp->next;
            temp->next = newnode;
            
        }
    }

    void display()
    {
        if (head==NULL)
        {
            printf("the list is empty");
        }
        else
        {
            struct node *temp = head;
            while (temp!=NULL)
            {
                printf("%d,",temp->data);
                temp = temp->next;
            }
        }
    }


    void mergelists(linkedlists l1, linkedlists l2)
    {
        struct node *temp1 = l1.gethead();
        struct node *temp2 = l2.gethead();
        if (temp1==NULL)
        {
            l2.display();
        }
        else if (temp2 == NULL)
        {
            l1.display();
        }
        else if (temp1==NULL && temp2==NULL)
        {
            printf("both lists are empty");
        }
        else
        {
            while (temp1 && temp2)
            {
                if (temp1->data < temp2->data)
                {
                    insertasc(temp1->data);
                    temp1 = temp1->next;
                }
                else
                {
                    insertasc(temp2->data);
                    temp2 = temp2->next;
                }
            }

            // when the list lengths don't match, the remaining elements will be appended as is.
            while (temp1)
            {
                insertasc(temp1->data);
                temp1 = temp1->next;
            }

            while (temp2)
            {
                insertasc(temp2->data);
                temp2 = temp2->next;
            }
        }

    }

};