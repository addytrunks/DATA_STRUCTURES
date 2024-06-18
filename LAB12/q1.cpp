// Program to implement a hash table using linear probing

#include <stdio.h>
#include <stdlib.h>

#define SIZE 10
#define TOMBSTONE -1

class HashTable
{
    int table[SIZE];

public:
    HashTable()
    {
        for (int i = 0; i < SIZE; i++)
        {
            table[i] = TOMBSTONE;
        }
    }
    void insert(int);
    int deleteValue(int);
    int search(int);
    void display();
};

int main()
{
    HashTable ht;
    int choice, num;
    while (1)
    {
        printf("\n1.Insert\n2.Delete\n3.Search\n4.Display\n5.Exit\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter the number to insert: ");
            scanf("%d", &num);
            ht.insert(num);
            break;
        case 2:
            printf("Enter the number to delete: ");
            scanf("%d", &num);
            if(ht.deleteValue(num) == -1){
                printf("Element not found\n");
            }else{
                printf("Element deleted\n");
            }
            break;
        case 3:
            printf("Enter the number to search: ");
            scanf("%d", &num);
            if (ht.search(num) == 1)
            {
                printf("Element found\n");
            }
            else
            {
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
}

// Method to insert a number into the hash table : O(n)
void HashTable::insert(int num){
    int index;
    index = num % SIZE;

    if(table[index] == TOMBSTONE){
        table[index] = num;
    }else{
        for(int i = 0; i < SIZE; i++){
            if(table[(index + i) % SIZE] == TOMBSTONE){
                table[(index + i) % SIZE] = num;
                break;
            }
        }
    }
}

// Method to display the hash table : O(n)
void HashTable::display(){
    for(int i = 0; i < SIZE; i++){
        if(table[i] != TOMBSTONE){
            printf("%d ", table[i]);
        }else{
            printf("NULL ");
        }
    }
}

// Method to search for a number in the hash table : O(n)
int HashTable::search(int num){
    int index;
    index = num % SIZE;

    if(table[index] == num){
        return 1;
    }else{
        for(int i = 0; i < SIZE; i++){
            if(table[(index + i) % SIZE] == num){
                return 1;
            }
        }
    }
    return 0;
}

// Method to delete a number from the hash table : O(n)
int HashTable::deleteValue(int num){
    int index;
    index = num % SIZE;

    if(table[index] == num){
        table[index] = TOMBSTONE;
        return num;
    }else{
        for(int i = 0; i < SIZE; i++){
            if(table[(index + i) % SIZE] == num){
                table[(index + i) % SIZE] = TOMBSTONE;
                return num;
            }
        }
    }
    return -1;
}
