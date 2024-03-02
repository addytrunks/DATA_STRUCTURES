#include<stdio.h>
#include<stdlib.h>
class Stack_LinkedList{
    struct Node{
        char data;
        struct Node* next;
    };
    struct Node*top;
    public:
        Stack_LinkedList(){
            top=NULL;
        }
        int push(char);
        int pop();
        int peek();
};
int main(){
    Stack_LinkedList l1;
    int choice;
    char data;
    while(1){
        getchar();
        getchar();
        system("clear");
        printf("\n\t1.Push\n\t2.Pop\n\t3.Peek\n\t4.Exit\nEnter your choice:");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                printf("\nEnter the character that needs to be inserted:");
                scanf(" %c",&data);
                l1.push(data);
                break;
            case 2:
                l1.pop();
                break;
            case 3:
                l1.peek();
                break;
            case 4:
                exit(0);
                break;
            default:
                printf("\nEnter a valid choice");
                break;
        }
    }
    return 0;
}


int Stack_LinkedList::push(char chr){
    struct Node* new_node=(struct Node *)malloc(sizeof(struct Node));
    new_node->data=chr;
    if (top==NULL){
        top=new_node;
        new_node->next=NULL;
    }
    else{
        new_node->next=top;
        top=new_node;
    }
    printf("\n%c has been inserted successfully",chr);
    return 1;
}

int Stack_LinkedList::pop(){
    if(top==NULL){
        printf("\nUnderflow error!");
        return 0;
    }
    else{
        struct Node*temp=top;
        char data=temp->data;
        top=temp->next;
        temp->next=NULL;
        printf("\nElement has been popped successfully from the stack");
        printf("\nPopped Element:%c",data);
        return 1;
    }
}
int Stack_LinkedList::peek(){
    if(top==NULL){
        printf("\nNothing to display");
        return -1;
    }
    else{
        printf("\nTop of the stack:%c",top->data);
        return 1;
    }
}

