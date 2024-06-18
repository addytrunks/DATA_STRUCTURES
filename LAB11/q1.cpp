// Programm to implement Hash Table using Separate Chaining

#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

class HashTable {

    struct Node {
        int data;
        struct Node *next;
    };

    struct Node *table[SIZE];
    public:
        HashTable(){
            for(int i=0; i<SIZE; i++){
                table[i] = NULL;
            }
        }
        void insert(int);
        int deleteValue(int);
        int search(int);
        void display(); 
};  

int main(){

    HashTable ht;
    int choice,num;
    while(1){
        printf("\n1.Insert\n2.Delete\n3.Search\n4.Display\n5.Exit\nEnter your choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                printf("Enter the number to insert: ");
                scanf("%d", &num);
                ht.insert(num);
                break;
            case 2:
                printf("Enter the number to delete: ");
                scanf("%d", &num);
                ht.deleteValue(num);
                break;
            case 3:
                printf("Enter the number to search: ");
                scanf("%d", &num);  
                if(ht.search(num) == 1){
                    printf("Element found\n");
                }else{
                    printf("Element not found\n");
                };
                break;
            case 4:
                ht.display();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
};

// Method to insert a number in the hash table : O(n)
void HashTable::insert(int num){
    int index = num % SIZE;
    int alreadyExists = 0;

    
    struct Node *temp = table[index];
    while (temp != NULL) {
        if (temp->data == num) {
            printf("Element already exists\n");
            alreadyExists = 1;
            break;
        }
        temp = temp->next;
    }

    if(alreadyExists == 0){
        struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = num;
        newNode->next = NULL;

        if(table[index] == NULL){
            table[index] = newNode;
        }else{
            struct Node *temp = table[index];
            while(temp->next != NULL){
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }
}

// Method to search a number in the hash table : O(n)
int HashTable::search(int num){
    int index = num%SIZE;
    int flag = 0;
    struct Node *temp = table[index];
    
    while(temp != NULL){
        if(temp->data == num){
            flag = 1;
            break;
        }
        temp = temp->next;
    }
    return flag;
}

// Method to delete a number in the hash table : O(n)
int HashTable::deleteValue(int num){
    if(search(num) == 0){
        printf("Element not found\n");
        return -1;
    }else{
        int index = num%SIZE;
        struct Node *p = table[index];
        struct Node *q = p->next;

        if(p->data == num){
            table[index] = q;
            free(p);
            printf("Element deleted\n");
            return num;
        }

        while(q != NULL){
            if(q->data == num){
                p->next = q->next;
                free(q);
                return num;
            }
            p = q;
            q = q->next;
            printf("Element deleted\n");

        }
    }
}

// Method to display the hash table : O(n)
void HashTable::display(){
    for(int i=0; i<SIZE; i++){
        struct Node *temp = table[i];
        printf("Key[%d]--> ", i);
        while(temp != NULL){
            printf("%d-->", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}