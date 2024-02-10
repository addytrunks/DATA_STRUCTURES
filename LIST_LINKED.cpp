#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

int count_nodes(struct node *);
void display_nodes(struct node *);
struct node *insert_beg(struct node *, int);
struct node *insert_end(struct node *, int);
struct node *insert_index(struct node *, int, int);
struct node *del_beg(struct node *);
struct node *del_end(struct node *);
struct node *del_index(struct node *, int);

int main()
{
    struct node *head, *new_node1, *new_node2;
    head = NULL;
    head = insert_index(head, 5, 0);
    head = insert_beg(head, 4);
    head = insert_end(head, 7);
    head = insert_end(head, 8);
    head = insert_index(head, 6, 2);
    printf("Before deleting:\n");
    display_nodes(head);
    printf("After deleting:\n");
    head = del_index(head, 3);
    display_nodes(head);
    return 0;
}

int count_nodes(struct node *head)
{
    int count = 0;
    struct node *temp = head;

    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    return count;
}

void display_nodes(struct node *head)
{
    struct node *temp = head;

    if (head == NULL)
    {
        printf("Empty list.");
    }
    else
    {

        while (temp != NULL)
        {
            printf("%d->", temp->data);
            temp = temp->next;
        }
    }
}

struct node *insert_beg(struct node *head, int data)
{
    struct node *new_node;
    new_node = (struct node *)malloc(sizeof(struct node));
    new_node->next = head;
    new_node->data = data;
    return new_node;
}

struct node *insert_end(struct node *head, int data)
{
    struct node *new_node, *temp;
    new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = NULL;
    temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = new_node;
    return head;
}

struct node *insert_index(struct node *head, int data, int index)
{
    struct node *temp, *new_node;

    new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = data;
    temp = head;

    if (index == 0)
    {
        return insert_beg(head, data);
    }
    else if (index == count_nodes(head) - 1)
    {
        return insert_end(head, data);
    }
    else
    {
        int i = 0;
        while (i != index - 1)
        {
            temp = temp->next;
            i++;
        }
        new_node->next = temp->next;
        temp->next = new_node;
        return head;
    }
}

struct node *del_beg(struct node *head)
{
    if (head == NULL)
    {
        return NULL;
    }
    else
    {
        struct node *temp;
        temp = head;
        head = head->next;
        free(temp);
        return head;
    }
}

struct node *del_index(struct node *head, int index)
{
    if (head == NULL)
    {
        return NULL;
    }
    else
    {
        int i = 0;
        struct node *p, *q;
        p = head;
        q = head->next;

        while (i != index - 1)
        {
            p = p->next;
            q = q->next;
            i++;
        }
        p->next = q->next;
        free(q);
        return head;
    }
}

struct node *del_end(struct node *head)
{
    if (head == NULL)
    {
        return NULL;
    }
    else
    {
        struct node *p, *q;
        p = head;
        q = head->next;
        while (q->next != NULL)
        {
            p = p->next;
            q = q->next;
        }
        p->next = NULL;
        free(q);
        return head;
    }
}