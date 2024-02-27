// Program to implement stack
#include <stdio.h>
#include <stdlib.h>

class Stack{
    int size;
    int top;
    int *arr;
    public:
        Stack(){
            size = 5;
            top = -1;
            arr = (int *)malloc(size * sizeof(int));
        }
        void push(int);
        int pop();
        void peek();
        void display();
}

void Stack::push(int data){
    if(top == size-1){
        printf("Stack Overflow.")
    }else{
        top+=1;
        arr[top] = data;
        printf("%d added to the stack",data);
    }
}

int Stack::pop(int data){
    if(top == -1){
        return -1;
    }else{
        int val = arr[top];
        top--;
        return val;
    }
}