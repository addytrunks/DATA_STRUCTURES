// Circular Linked List Implementation
#include <stdio.h>
#include <stdlib.h>

// Datatype of a node
struct Node
{
    int data;
    struct Node *next;
};

class CircularLinkedList
{
    struct Node *head;
    struct Node *tail;

public:
    CircularLinkedList()
    {
        head = NULL;
        tail = NULL;
    }

    int count_nodes(); // O(1)
    void display(); // O(n)
    void insert_beg(int); // O(1)
    void insert_end(int); // O(1)
    void insert_pos(int,int);// O(n)
    int delete_beg(); // O(1)
    int delete_end(); // O(n)
    int delete_pos(int); // O(n)
};

int main()
{
    CircularLinkedList l1;
    int choice, num, pos;

    while (1)
    {
        printf("\nEnter \n1. Insert Begin\n2. Insert End\n3. Insert Position");
        printf("\n4. Delete Begin\n5. Delete End\n6. Delete Position");
        printf("\n7. Search\n8. Display\n9. Display Reverse\n10.Reverse Link\n11.Exit");
        printf("\n Enter a choice:");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter the number:");
            scanf("%d", &num);
            l1.insert_beg(num);
            break;
        case 2:
            printf("Enter the number:");
            scanf("%d", &num);
            l1.insert_end(num);
            break;
        case 3:
            printf("\n Enter the number insert:");
            scanf("%d", &num);
            printf("\n Enter the position at which you want to insert:");
            scanf("%d", &pos);
            l1.insert_pos(num, pos);
            break;
        case 4:
            l1.delete_beg();
            break;
        case 5:
            l1.delete_end();
            break;
        case 6:
            printf("\n Enter the position at which you want to delete:");
            scanf("%d", &pos);
            l1.delete_pos(pos);
            break;
        case 8:
            l1.display();
            break;
        default:
            printf("\n Enter a valid choice\n");
            break;
        }
    }

    return 0;
}

int CircularLinkedList::count_nodes()
{
    int count = 0;
    struct Node *temp = head;

    do
    {
        count++;
        temp = temp->next;
    } while (temp != head);
    return count;
}

void CircularLinkedList::display()

{
    struct Node *temp;
    temp = head;

    if (head == NULL)
    {
        printf("Empty list.");
    }
    else
    {

        do
        {
            printf("%d->", temp->data);
            temp = temp->next;
        } while (temp != head);
    }
}

void CircularLinkedList::insert_beg(int data)
{
    struct Node *new_node;
    new_node = (struct Node *)malloc(sizeof(struct Node));
    new_node->data = data;

    if (head == NULL)
    {
        head = new_node;
        tail = new_node;
        tail->next = head;
    }
    else
    {
        new_node->next = head;
        head = new_node;
        tail->next = head;
    }
    printf("Element has been successfully inserted at the beginnig.\n");
}

void CircularLinkedList::insert_end(int data)
{
    struct Node *new_node;
    new_node = (struct Node *)malloc(sizeof(struct Node));
    new_node->data = data;

    tail->next = new_node;
    tail = new_node;
    tail->next = head;
    printf("Element has been successfully inserted at the end.\n");
}

void CircularLinkedList::insert_pos(int data, int pos)
{

    if (pos == 1)
    {
        insert_beg(data);
    }
    else if (pos == count_nodes() + 1)
    {
        insert_end(data);
    }
    else if (pos < 1 || pos > count_nodes() + 1)
    {
        printf("Invalid position.\n");
    }
    else
    {
        struct Node *temp, *new_node;
        new_node = (struct Node *)malloc(sizeof(struct Node));
        new_node->data = data;
        temp = head;
        int index = 1; // Start index from 1 for position comparison
        while (index != pos - 1)
        {
            printf("%d", index);
            temp = temp->next;
            index++;
        }
        new_node->next = temp->next;
        temp->next = new_node;
        printf("Element has been inserted at position %d.\n", pos);
    }
}

int CircularLinkedList::delete_beg()
{
    int deleted_value;
    if (head == NULL)
    {
        printf("Empty List.");
        return -1;
    }
    // Only one element present
    else if (tail == head)
    {
        deleted_value = head->data;
        tail = NULL;
        free(head);
        head = NULL;
        printf("First element (%d) has been deleted.\n", deleted_value);
        return deleted_value;
    }
    else
    {
        struct Node *temp = head;

        deleted_value = temp->data;
        head = head->next;
        tail->next = head;
        free(temp);
        printf("First element (%d) has been deleted.\n", deleted_value);
        return deleted_value;
    }
}

int CircularLinkedList::delete_end()
{
    int deleted_value;
    if (head == NULL)
    {
        printf("Empty List.");
        return -1;
    }
    // Only one element present
    else if (tail == head)
    {
        deleted_value = head->data;
        tail = NULL;
        free(head);
        head = NULL;
        printf("Last element (%d) has been deleted.\n", deleted_value);
        return deleted_value;
    }
    else
    {
        struct Node *p, *q;
        p = head;
        q = head->next;
        do
        {
            p = p->next;
            q = q->next;
        } while (q->next != head);
        tail = p;
        tail->next = head;
        deleted_value = q->data;
        free(q);
        printf("Last element (%d) has been deleted.\n", deleted_value);
        return deleted_value;
    }
}

int CircularLinkedList::delete_pos(int pos)
{
    if (head == NULL)
    {
        printf("Empty list");
        return -1;
    }
    else if (pos < 1 || pos > count_nodes() + 1)
    {
        printf("Invalid position");
        return -1;
    }
    else if (pos == 1)
    {
        return delete_beg();
    }
    else if (pos == count_nodes() + 1)
    {
        return delete_end();
    }
    else
    {
        int deleted_value;
        struct Node *p, *q;
        p = head;
        q = head->next;
        for (int i = 1; i < pos - 1; i++)
        {
            p = p->next;
            q = q->next;
        }
        p->next = q->next;
        deleted_value = q->data;
        free(q);
        printf("Element at position %d (%d) has been deleted.\n", pos, deleted_value);
        return deleted_value;
    }
}