#include<stdio.h>
#include<stdlib.h>
 class WebPage{
    struct Node{
        int data;
        struct Node *next;
        struct Node *prev;
    };
    public:
        struct Node*current;
        WebPage(){
            current=NULL;
        }
        int Display_Current_Page();
        int New_Web_Page(int);
        int Front();
        int Back();


 };

 int WebPage::New_Web_Page(int num){
   
    if (current==NULL){
        struct Node*newpage=(struct Node*)malloc(sizeof(struct Node));
        newpage->data=num;
        newpage->prev=NULL;
        newpage->next=NULL;
        current=newpage;
        printf("\nNew web page with data %d has been created successfully",num);
        return 1;
    }
    else{
        struct Node*newpage=(struct Node*)malloc(sizeof(struct Node));
        newpage->data=num;
        newpage->prev=current;
        newpage->next=NULL;
        current->next=newpage;
        current=newpage;
        printf("\nNew web page with data %d has been created successfully",num);
        return 1;
    }
 }

 int WebPage::Front(){
    if(current==NULL){
        printf("\nNo webpages are formed at all");
        return -1;
    }
    else if (current->next==NULL){
        printf("\nNo next webpage was formed for the current webpage");
        return -2;
    }
    else{
        current=current->next;
        printf("\nMoved to the next page successfully");
        return 1;
        
    }
 }
 int WebPage::Back(){
    if(current==NULL){
        printf("\nNo webpages are formed at all");
        return -1;
    }
    else if (current->prev==NULL){
        printf("\nNo previous webpage was formed for the current webpage");
        return -2;
    }
    else{
        current=current->prev;
        printf("\nMoved to the previous page successfully");
        return 1;
        
    }
 }
 int WebPage::Display_Current_Page(){
    if (current==NULL){
        printf("\nNo contents to display");
        return -1;
    }
    else{
        printf("\nCurrent Webpage:%d",current->data);
        return 1;
    }
 }
 

