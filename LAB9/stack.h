/*Program to implement stack ADT using singly linked list*/

#include<stdio.h>
#include<stdlib.h>
class stack
{
  struct node
{
    char data;
    struct node *next;
};
struct node *head;

public:

  stack()
  {
    head=NULL;
  }  
    int push(char chr);
    char pop();
    char peek();

};



//Method to push a character into a stack

int stack:: push(char chr)
{
    struct node *newnode=(struct node *)malloc(sizeof(struct node));
    newnode->data=chr;
    if(head==NULL)
    { 
      newnode->next=NULL;
      head=newnode;
      return 1;
    }

    else
    {
       newnode->next=head;
       head=newnode;
       return 1;
    }
}

// Method to pop a character from the stack

char stack::pop()
{
    struct node *temp=head;
    if(head==NULL)
    {
        return '\0';
    }
    else
    {
        char ll=head->data;
        head=head->next;
        free(temp);
        temp=NULL;
        return ll;
    }
}

// Method to display the last element in a stack
char stack::peek()
{
   return head->data;   
}

