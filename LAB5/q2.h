#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next, *prev;
};

class Webpage
{
public:
    struct node *head;
    int cur;
    webpage()
    {
        head = NULL;
        cur = -1;
    }
    int openwebpage(int);
    int front();
    int back();
    int count();
    void currentwebpage();
};

int Webpage::openwebpage(int data)
{
    int cnt;
    cnt = count();
    struct node *newwebpage = (struct node *)malloc(sizeof(struct node));
    if (head == NULL && cnt == 0)
    {
        newwebpage->data = data;
        newwebpage->next = NULL;
        newwebpage->prev = NULL;
        head = newwebpage;
        cur = 0;
        return 1;
    }
    else
    {
        struct node *temp = head, *temp2;

        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        
        while (cnt != (cur + 1))
        {
            cnt -= 1;
            temp2 = temp;
            temp = temp->prev;
            free(temp2);
        }
        newwebpage->next = NULL;
        temp->next = newwebpage;
        newwebpage->prev = temp;
        cur += 1;
        newwebpage->data = dat;
        return 1;
    }

    return 0;
}

// Method to count and return the number of webpages
int Webpage::count()
{
    struct node *temp = head;
    int count = 0;
    while (temp != NULL)
    {
        count += 1;
        temp = temp->next;
    }
    return count;
}

// Method to print the number of the current webpage
void Webpage::currentwebpage()
{
    struct node *temp = head;
    for (int i = 0; i < cur; i++)
    {
        temp = temp->next;
    }
    printf("You are currently at webpage no. %d\nThe data stored in it is %d", cur + 1, temp->data);
}

// Method to move to the next webpage
int Webpage::front()
{
    int cnt = count();
    if (cur == -1 || cur == (cnt - 1))
    {
        return 0;
    }
    else
    {
        cur += 1;
        return 1;
    }
}

// Method to move  to the previous page
int Webpage::back()
{
    if (cur == -1 || cur == 0)
    {
        return 0;
    }
    else
    {
        cur -= 1;
        return 1;
    }
}