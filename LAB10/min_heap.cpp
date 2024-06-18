// Program to implement priority queue using min heap

#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

class PriorityQueue
{
    int heapArray[MAX_SIZE];
    int size;
    int parent(int i) { return (i - 1) / 2; }
    int leftChild(int i) { return (2 * i + 1); }
    int rightChild(int i) { return (2 * i + 2); }

    void swap(int *x, int *y)
    {
        int temp = *x;
        *x = *y;
        *y = temp;
    }

    void heapifyUp(int index)
    {
        while (index > 0 && heapArray[index] < heapArray[parent(index)])
        {
            swap(&heapArray[index], &heapArray[parent(index)]);
            index = parent(index);
        }
    }

    void heapifyDown(int index)
    {
        int minIndex = index;
        int left = leftChild(index);

        if (left < size && heapArray[left] < heapArray[minIndex])
        {
            minIndex = left;
        }
        int right = rightChild(index);
        if (right < size && heapArray[right] < heapArray[minIndex])
        {
            minIndex = right;
        }
        if (index != minIndex)
        {
            swap(&heapArray[index], &heapArray[minIndex]);
            heapifyDown(minIndex);
        }
    }

public:
    PriorityQueue()
    {
        size = 0;
    }
    void insert(int);
    int del_el();
    void display();
    void sort();
    void search(int);
};

int main()
{

    int choice, num;
    PriorityQueue pq;

    while (1)
    {
        printf("\n1.Insert\n2.Delete\n3.Display\n4.Search\n5.Sort\n6.Exit\nEnter your choice:");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter the number to insert:");
            scanf("%d", &num);
            pq.insert(num);
            break;
        case 2:
            num = pq.del_el();
            if (num == -1)
            {
                printf("Empty queue.Cannot delete.");
            }
            else
            {
                printf("Element %d deleted.", num);
            }
            break;
        case 3:
            pq.display();
            break;
        case 4:
            printf("Enter the number to search:");
            scanf("%d", &num);
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

void PriorityQueue::insert(int num)
{
    if (size == MAX_SIZE - 1)
    {
        printf("Size full, cannot add");
    }
    else
    {
        heapArray[size] = num;
        heapifyUp(size);
        size++;
    }
}

void PriorityQueue::display()
{
    printf("Heap: ");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", heapArray[i]);
    }
    printf("\n");
}

int PriorityQueue::del_el()
{
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

void PriorityQueue::sort(){
    int num;
    while(1){
        num = del_el();
        if(num==-1){
            break;
        }else{
            printf("%d ",num);
        }
    }
}

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