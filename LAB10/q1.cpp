//Program to implement Priority Queue ADT using a max heap.

#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

class PriorityQueue{
    int heapArray[MAX_SIZE];
    int size;
    int parent(int i) { return (i - 1) / 2; }
    int leftChild(int i) { return (2 * i + 1); }
    int rightChild(int i) { return (2 * i + 2); }
    
    void swap(int *x, int *y) {
        int temp = *x;
        *x = *y;
        *y = temp;
    }

    // Method to heapify upwards
    void heapifyUp(int index) {
        while (index > 0 && heapArray[parent(index)] < heapArray[index]) {
            swap(&heapArray[parent(index)], &heapArray[index]);
            index = parent(index);
        }
    }

    // Method to heapify downwards
    void heapifyDown(int index) {
        int maxIndex = index;
        int left = leftChild(index);
        if (left < size && heapArray[left] > heapArray[maxIndex]) {
            maxIndex = left;
        }
        int right = rightChild(index);
        if (right < size && heapArray[right] > heapArray[maxIndex]) {
            maxIndex = right;
        }
        if (index != maxIndex) {
            swap(&heapArray[index], &heapArray[maxIndex]);
            heapifyDown(maxIndex);
        }
    }

    public:
        PriorityQueue(){
            size = 0;
        }
        void insert(int);
        void search(int);
        int del_el();
        void display();
        void sort();
};


int main(){

    int choice,num;
    PriorityQueue pq;

    while (1)
    {
        printf("\n1.Insert\n2.Delete\n3.Display\n4.Search\n5.Sort\n6.Exit\nEnter your choice:");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
            printf("Enter the number to insert:");
            scanf("%d",&num);
            pq.insert(num);
            break;
        case 2:
            num = pq.del_el();
            if(num == -1){
                printf("Empty queue.Cannot delete.");
            }else{
                printf("Element %d deleted.",num);
            }
            break;
        case 3:
            pq.display();
            break;
        case 4:
            printf("Enter the number to search:");
            scanf("%d",&num);
            pq.search(num);
            break;
        case 5:
            printf("Sorted Queue:");
            pq.sort();
            break;
        case 6:
            exit(0);
            break;
        default:
            printf("\nEnter a valid choice");
            break;
        }
    }
    

    return 0;
}

// Method to insert an element into the queue:O(log n)
void PriorityQueue::insert(int data){
   if(size == MAX_SIZE){
    printf("Queue full,cannot add element.\n");
   }else{
    heapArray[size] = data;
    heapifyUp(size);
    size++;
    printf("Element added.\n");
   }
}

// Method to delete an element from the queue:O(log n)
int PriorityQueue::del_el(){
    int num;
    if(size == 0) {
        return -1;
    }
    num = heapArray[0];
    heapArray[0] = heapArray[size - 1];
    size--;
    heapifyDown(0);
    return num;
}

// Method to search for an element in the queue:O(n)
void PriorityQueue::search(int num){
    int found = 0;
    for (int i = 0; i <=size; i++) {
        if (heapArray[i] == num){
            found = 1;
            printf("Element %d exists in the queue.",num);
            break;
        }
    }
    if(found == 0){
        printf("Element %d does not exist in the queue.",num);
    }
}

// Method to display the contents of the queue.:O(n)
void PriorityQueue::display() {
    printf("Heap: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", heapArray[i]);
    }
    printf("\n");
}

// Method to sort the queue in descending order: O(nlog n)
void PriorityQueue::sort(){
    int num;
    int arr[MAX_SIZE];
    int i = 0;
    while(1){
        num = del_el();
        if(num==-1){
            break;
        }else{
            arr[i] = num;
            i++;
            printf("%d ",num);
        }
    }

    for(int j=0;j<i;j++){
        insert(arr[j]);
    }    
}

